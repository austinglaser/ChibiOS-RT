/*
   ChibiOS/RT - Copyright (C) 2006-2013 Giovanni Di Sirio

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */

#include <stdio.h>
#include <string.h>

#include "ch.h"
#include "hal.h"

#include "shell.h"
#include "chprintf.h"

/*===========================================================================*/
/* ADC related stuff.                                                        */
/*===========================================================================*/

#define ADC_GRP1_NUM_CHANNELS   2
#define ADC_GRP1_BUF_DEPTH      8

#define ADC_GRP2_NUM_CHANNELS   8
#define ADC_GRP2_BUF_DEPTH      16

static adcsample_t samples1[ADC_GRP1_NUM_CHANNELS * ADC_GRP1_BUF_DEPTH];
static adcsample_t samples2[ADC_GRP2_NUM_CHANNELS * ADC_GRP2_BUF_DEPTH];

/*
 * ADC streaming callback.
 */
size_t nx = 0, ny = 0;
static void adccallback(ADCDriver *adcp, adcsample_t *buffer, size_t n) {

  (void)adcp;
  if (samples2 == buffer) {
    nx += n;
  }
  else {
    ny += n;
  }
}

static void adcerrorcallback(ADCDriver *adcp, adcerror_t err) {

  (void)adcp;
  (void)err;
}

/*
 * ADC conversion group.
 * Mode:        Linear buffer, 8 samples of 2 channels, SW triggered.
 * Channels:    IN7, IN8.
 */
static const ADCConversionGroup adcgrpcfg1 = {
  FALSE,
  ADC_GRP1_NUM_CHANNELS,
  NULL,
  adcerrorcallback,
  0,                        /* CFGR    */
  ADC_TR(0, 4095),          /* TR1     */
  0,                        /* CCR     */
  {                         /* SMPR[2] */
    0,
    0
  },
  {                         /* SQR[4]  */
    ADC_SQR1_SQ1_N(ADC_CHANNEL_IN7) | ADC_SQR1_SQ2_N(ADC_CHANNEL_IN8),
    0,
    0,
    0
  }
};

/*
 * ADC conversion group.
 * Mode:        Continuous, 16 samples of 8 channels, SW triggered.
 * Channels:    IN7, IN8, IN7, IN8, IN7, IN8, Sensor, VBat/2.
 */
static const ADCConversionGroup adcgrpcfg2 = {
  TRUE,
  ADC_GRP2_NUM_CHANNELS,
  adccallback,
  adcerrorcallback,
  0,                         /* CFGR    */
  ADC_TR(0, 4095),           /* TR1     */
  ADC_CCR_TSEN
   | ADC_CCR_VBATEN,         /* CCR     */
  {                          /* SMPR[2] */
    ADC_SMPR1_SMP_AN7(ADC_SMPR_SMP_19P5)
     | ADC_SMPR1_SMP_AN8(ADC_SMPR_SMP_19P5),
    ADC_SMPR2_SMP_AN16(ADC_SMPR_SMP_61P5)
     | ADC_SMPR2_SMP_AN17(ADC_SMPR_SMP_61P5),
  },
  {                          /* SQR[4]  */
    ADC_SQR1_SQ1_N(ADC_CHANNEL_IN12)  | ADC_SQR1_SQ2_N(ADC_CHANNEL_IN12)
     | ADC_SQR1_SQ3_N(ADC_CHANNEL_IN12)  | ADC_SQR1_SQ4_N(ADC_CHANNEL_IN12),
    ADC_SQR2_SQ5_N(ADC_CHANNEL_IN12)  | ADC_SQR2_SQ6_N(ADC_CHANNEL_IN12)
     | ADC_SQR2_SQ7_N(ADC_CHANNEL_IN12) | ADC_SQR2_SQ8_N(ADC_CHANNEL_IN12),
    0,
    0
  }
};

/*===========================================================================*/
/* USB related stuff.                                                        */
/*===========================================================================*/

/*
 * Endpoints to be used for USBD1.
 */
#define USBD1_DATA_REQUEST_EP           1
#define USBD1_DATA_AVAILABLE_EP         1
#define USBD1_INTERRUPT_REQUEST_EP      2

/*
 * DP resistor control is not possible on the STM32F3-Discovery, using stubs
 * for the connection macros.
 */
#define usb_lld_connect_bus(usbp)
#define usb_lld_disconnect_bus(usbp)

/*
 * Serial over USB Driver structure.
 */
static SerialUSBDriver SDU1;

/*
 * USB Device Descriptor.
 */
static const uint8_t vcom_device_descriptor_data[18] = {
  USB_DESC_DEVICE       (0x0110,        /* bcdUSB (1.1).                    */
      0x02,          /* bDeviceClass (CDC).              */
      0x00,          /* bDeviceSubClass.                 */
      0x00,          /* bDeviceProtocol.                 */
      0x40,          /* bMaxPacketSize.                  */
      0x0483,        /* idVendor (ST).                   */
      0x5740,        /* idProduct.                       */
      0x0200,        /* bcdDevice.                       */
      1,             /* iManufacturer.                   */
      2,             /* iProduct.                        */
      3,             /* iSerialNumber.                   */
      1)             /* bNumConfigurations.              */
};

/*
 * Device Descriptor wrapper.
 */
static const USBDescriptor vcom_device_descriptor = {
  sizeof vcom_device_descriptor_data,
  vcom_device_descriptor_data
};

/* Configuration Descriptor tree for a CDC.*/
static const uint8_t vcom_configuration_descriptor_data[67] = {
  /* Configuration Descriptor.*/
  USB_DESC_CONFIGURATION(67,            /* wTotalLength.                    */
      0x02,          /* bNumInterfaces.                  */
      0x01,          /* bConfigurationValue.             */
      0,             /* iConfiguration.                  */
      0xC0,          /* bmAttributes (self powered).     */
      50),           /* bMaxPower (100mA).               */
  /* Interface Descriptor.*/
  USB_DESC_INTERFACE    (0x00,          /* bInterfaceNumber.                */
      0x00,          /* bAlternateSetting.               */
      0x01,          /* bNumEndpoints.                   */
      0x02,          /* bInterfaceClass (Communications
                        Interface Class, CDC section
                        4.2).                            */
      0x02,          /* bInterfaceSubClass (Abstract
                        Control Model, CDC section 4.3).   */
      0x01,          /* bInterfaceProtocol (AT commands,
                        CDC section 4.4).                */
      0),            /* iInterface.                      */
  /* Header Functional Descriptor (CDC section 5.2.3).*/
  USB_DESC_BYTE         (5),            /* bLength.                         */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x00),         /* bDescriptorSubtype (Header
                                           Functional Descriptor.           */
  USB_DESC_BCD          (0x0110),       /* bcdCDC.                          */
  /* Call Management Functional Descriptor. */
  USB_DESC_BYTE         (5),            /* bFunctionLength.                 */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x01),         /* bDescriptorSubtype (Call Management
                                           Functional Descriptor).          */
  USB_DESC_BYTE         (0x00),         /* bmCapabilities (D0+D1).          */
  USB_DESC_BYTE         (0x01),         /* bDataInterface.                  */
  /* ACM Functional Descriptor.*/
  USB_DESC_BYTE         (4),            /* bFunctionLength.                 */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x02),         /* bDescriptorSubtype (Abstract
                                           Control Management Descriptor).  */
  USB_DESC_BYTE         (0x02),         /* bmCapabilities.                  */
  /* Union Functional Descriptor.*/
  USB_DESC_BYTE         (5),            /* bFunctionLength.                 */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x06),         /* bDescriptorSubtype (Union
                                           Functional Descriptor).          */
  USB_DESC_BYTE         (0x00),         /* bMasterInterface (Communication
                                           Class Interface).                */
  USB_DESC_BYTE         (0x01),         /* bSlaveInterface0 (Data Class
                                           Interface).                      */
  /* Endpoint 2 Descriptor.*/
  USB_DESC_ENDPOINT     (USBD1_INTERRUPT_REQUEST_EP|0x80,
      0x03,          /* bmAttributes (Interrupt).        */
      0x0008,        /* wMaxPacketSize.                  */
      0xFF),         /* bInterval.                       */
  /* Interface Descriptor.*/
  USB_DESC_INTERFACE    (0x01,          /* bInterfaceNumber.                */
      0x00,          /* bAlternateSetting.               */
      0x02,          /* bNumEndpoints.                   */
      0x0A,          /* bInterfaceClass (Data Class
                        Interface, CDC section 4.5).     */
      0x00,          /* bInterfaceSubClass (CDC section
                        4.6).                            */
      0x00,          /* bInterfaceProtocol (CDC section
                        4.7).                            */
      0x00),         /* iInterface.                      */
  /* Endpoint 3 Descriptor.*/
  USB_DESC_ENDPOINT     (USBD1_DATA_AVAILABLE_EP,       /* bEndpointAddress.*/
      0x02,          /* bmAttributes (Bulk).             */
      0x0040,        /* wMaxPacketSize.                  */
      0x00),         /* bInterval.                       */
  /* Endpoint 1 Descriptor.*/
  USB_DESC_ENDPOINT     (USBD1_DATA_REQUEST_EP|0x80,    /* bEndpointAddress.*/
      0x02,          /* bmAttributes (Bulk).             */
      0x0040,        /* wMaxPacketSize.                  */
      0x00)          /* bInterval.                       */
};

/*
 * Configuration Descriptor wrapper.
 */
static const USBDescriptor vcom_configuration_descriptor = {
  sizeof vcom_configuration_descriptor_data,
  vcom_configuration_descriptor_data
};

/*
 * U.S. English language identifier.
 */
static const uint8_t vcom_string0[] = {
  USB_DESC_BYTE(4),                     /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  USB_DESC_WORD(0x0409)                 /* wLANGID (U.S. English).          */
};

/*
 * Vendor string.
 */
static const uint8_t vcom_string1[] = {
  USB_DESC_BYTE(38),                    /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  'S', 0, 'T', 0, 'M', 0, 'i', 0, 'c', 0, 'r', 0, 'o', 0, 'e', 0,
  'l', 0, 'e', 0, 'c', 0, 't', 0, 'r', 0, 'o', 0, 'n', 0, 'i', 0,
  'c', 0, 's', 0
};

/*
 * Device Description string.
 */
static const uint8_t vcom_string2[] = {
  USB_DESC_BYTE(56),                    /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  'C', 0, 'h', 0, 'i', 0, 'b', 0, 'i', 0, 'O', 0, 'S', 0, '/', 0,
  'R', 0, 'T', 0, ' ', 0, 'V', 0, 'i', 0, 'r', 0, 't', 0, 'u', 0,
  'a', 0, 'l', 0, ' ', 0, 'C', 0, 'O', 0, 'M', 0, ' ', 0, 'P', 0,
  'o', 0, 'r', 0, 't', 0
};

/*
 * Serial Number string.
 */
static const uint8_t vcom_string3[] = {
  USB_DESC_BYTE(8),                     /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  '0' + CH_KERNEL_MAJOR, 0,
  '0' + CH_KERNEL_MINOR, 0,
  '0' + CH_KERNEL_PATCH, 0
};

/*
 * Strings wrappers array.
 */
static const USBDescriptor vcom_strings[] = {
  {sizeof vcom_string0, vcom_string0},
  {sizeof vcom_string1, vcom_string1},
  {sizeof vcom_string2, vcom_string2},
  {sizeof vcom_string3, vcom_string3}
};

/*
 * Handles the GET_DESCRIPTOR callback. All required descriptors must be
 * handled here.
 */
static const USBDescriptor *get_descriptor(USBDriver *usbp,
    uint8_t dtype,
    uint8_t dindex,
    uint16_t lang) {

  (void)usbp;
  (void)lang;
  switch (dtype) {
    case USB_DESCRIPTOR_DEVICE:
      return &vcom_device_descriptor;
    case USB_DESCRIPTOR_CONFIGURATION:
      return &vcom_configuration_descriptor;
    case USB_DESCRIPTOR_STRING:
      if (dindex < 4)
        return &vcom_strings[dindex];
  }
  return NULL;
}

/**
 * @brief   IN EP1 state.
 */
static USBInEndpointState ep1instate;

/**
 * @brief   OUT EP1 state.
 */
static USBOutEndpointState ep1outstate;

/**
 * @brief   EP1 initialization structure (both IN and OUT).
 */
static const USBEndpointConfig ep1config = {
  USB_EP_MODE_TYPE_BULK,
  NULL,
  sduDataTransmitted,
  sduDataReceived,
  0x0040,
  0x0040,
  &ep1instate,
  &ep1outstate,
  1,
  NULL
};

/**
 * @brief   IN EP2 state.
 */
static USBInEndpointState ep2instate;

/**
 * @brief   EP2 initialization structure (IN only).
 */
static const USBEndpointConfig ep2config = {
  USB_EP_MODE_TYPE_INTR,
  NULL,
  sduInterruptTransmitted,
  NULL,
  0x0010,
  0x0000,
  &ep2instate,
  NULL,
  1,
  NULL
};

/*
 * Handles the USB driver global events.
 */
static void usb_event(USBDriver *usbp, usbevent_t event) {

  switch (event) {
    case USB_EVENT_RESET:
      return;
    case USB_EVENT_ADDRESS:
      return;
    case USB_EVENT_CONFIGURED:
      chSysLockFromISR();

      /* Enables the endpoints specified into the configuration.
         Note, this callback is invoked from an ISR so I-Class functions
         must be used.*/
      usbInitEndpointI(usbp, USBD1_DATA_REQUEST_EP, &ep1config);
      usbInitEndpointI(usbp, USBD1_INTERRUPT_REQUEST_EP, &ep2config);

      /* Resetting the state of the CDC subsystem.*/
      sduConfigureHookI(&SDU1);

      chSysUnlockFromISR();
      return;
    case USB_EVENT_SUSPEND:
      return;
    case USB_EVENT_WAKEUP:
      return;
    case USB_EVENT_STALLED:
      return;
  }
  return;
}

/*
 * USB driver configuration.
 */
static const USBConfig usbcfg = {
  usb_event,
  get_descriptor,
  sduRequestsHook,
  NULL
};

/*
 * Serial over USB driver configuration.
 */
static const SerialUSBConfig serusbcfg = {
  &USBD1,
  USBD1_DATA_REQUEST_EP,
  USBD1_DATA_AVAILABLE_EP,
  USBD1_INTERRUPT_REQUEST_EP
};

/*===========================================================================*/
/* Command line related.                                                     */
/*===========================================================================*/

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(2048)
#define TEST_WA_SIZE    THD_WORKING_AREA_SIZE(256)

static void cmd_adc(BaseSequentialStream *chp, int argc, char * argv[]) {
  (void)argc;
  (void)argv;

  while (chnGetTimeout((BaseChannel *)chp, TIME_IMMEDIATE) == Q_TIMEOUT) {
  //  chSequentialStreamWrite(&SDU1, buf, sizeof buf - 1);
    chprintf(chp, "temp: %u\r\n",samples2[7]);
  }
  chprintf(chp, "\r\n\nstopped\r\n");
  
  //int i;
  //for (i = 0; i < ADC_GRP2_NUM_CHANNELS * ADC_GRP2_BUF_DEPTH; i++) {
  //  if (i%10 == 0) chprintf(chp, "\r\n");
  //  chprintf(chp, "%03d: %04u ", i, samples2[i]);
  //}
  //chprintf(chp, "\r\n\r\n");
}

static void cmd_mem(BaseSequentialStream *chp, int argc, char *argv[]) {
  size_t n, size;

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: mem\r\n");
    return;
  }
  n = chHeapStatus(NULL, &size);
  chprintf(chp, "core free memory : %u bytes\r\n", chCoreStatus());
  chprintf(chp, "heap fragments   : %u\r\n", n);
  chprintf(chp, "heap free total  : %u bytes\r\n", size);
}

static void cmd_threads(BaseSequentialStream *chp, int argc, char *argv[]) {
  static const char *states[] = {CH_STATE_NAMES};
  thread_t *tp;

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: threads\r\n");
    return;
  }
  chprintf(chp, "    addr    stack prio refs     state\r\n");
  tp = chRegFirstThread();
  do {
    chprintf(chp, "%.8lx %.8lx %4lu %4lu %9s %lu\r\n",
        (uint32_t)tp, (uint32_t)tp->p_ctx.r13,
        (uint32_t)tp->p_prio, (uint32_t)(tp->p_refs - 1),
        states[tp->p_state]);
    tp = chRegNextThread(tp);
  } while (tp != NULL);
}

/*static void cmd_test(BaseSequentialStream *chp, int argc, char *argv[]) {
  thread_t *tp;

  (void)argv;
  if (argc > 0) {
  chprintf(chp, "Usage: test\r\n");
  return;
  }
  tp = chThdCreateFromHeap(NULL, TEST_WA_SIZE, chThdGetPriorityX(),
  TestThread, chp);
  if (tp == NULL) {
  chprintf(chp, "out of memory\r\n");
  return;
  }
  chThdWait(tp);
  } */

static void cmd_write(BaseSequentialStream *chp, int argc, char *argv[]) {
  static uint8_t buf[] =
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef"
    "0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef";

  (void)argv;
  if (argc > 0) {
    chprintf(chp, "Usage: write\r\n");
    return;
  }

  while (chnGetTimeout((BaseChannel *)chp, TIME_IMMEDIATE) == Q_TIMEOUT) {
    chSequentialStreamWrite(&SDU1, buf, sizeof buf - 1);
  }
  chprintf(chp, "\r\n\nstopped\r\n");
}

static const ShellCommand commands[] = {
  {"mem", cmd_mem},
  {"threads", cmd_threads},
  //{"test", cmd_test},
  {"write", cmd_write},
  {"adc", cmd_adc},
  {NULL, NULL}
};

static const ShellConfig shell_cfg1 = {
  (BaseSequentialStream *)&SDU1,
  commands
};


/*
 * Red LEDs blinker thread, times are in milliseconds.
 * AG: Commented out
 */
/*static THD_WORKING_AREA(waThread1, 128);
  static msg_t Thread1(void *arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (TRUE) {
  palSetPad(GPIOE, GPIOE_LED10_RED);
  chThdSleepMilliseconds(500);
  palClearPad(GPIOE, GPIOE_LED10_RED);
  chThdSleepMilliseconds(500);
  }
  return 0;
  } */

/*
 * Application entry point.
 */
int main(void) {
  thread_t *shelltp=NULL;

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /*
   * Initializes a serial-over-USB CDC driver.
   */
  sduObjectInit(&SDU1);
  sduStart(&SDU1, &serusbcfg);

  /*
   * Activates the USB driver and then the USB bus pull-up on D+.
   * Note, a delay is inserted in order to not have to disconnect the cable
   * after a reset.
   */
  usbDisconnectBus(serusbcfg.usbp);
  chThdSleepMilliseconds(1500);
  usbStart(serusbcfg.usbp, &usbcfg);
  usbConnectBus(serusbcfg.usbp);

  /* 
   * Turn on shell
   */
  shellInit();

  /*
   * Setting up analog inputs used by the demo.
   */
  palSetGroupMode(GPIOB, PAL_PORT_BIT(0), 0, PAL_MODE_INPUT_ANALOG);

  /*
   * Creates the blinker thread.
   * AG: Commented out
   */
  //chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /*
   * Activates the ADC1 driver and the temperature sensor.
   */
  adcStart(&ADCD3, NULL);

  /*
   * Linear conversion.
   */
  adcConvert(&ADCD3, &adcgrpcfg1, samples1, ADC_GRP1_BUF_DEPTH);
  chThdSleepMilliseconds(1000);

  /*
   * Starts an ADC continuous conversion.
   */
  adcStartConversion(&ADCD3, &adcgrpcfg2, samples2, ADC_GRP2_BUF_DEPTH);

  /*  
   * Normal main() thread activity, in this demo it does nothing except
   * sleeping in a loop and check the button state.
   */
  while (TRUE) {
    if (!shelltp && (SDU1.config->usbp->state == USB_ACTIVE))
      shelltp = shellCreate(&shell_cfg1, SHELL_WA_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(shelltp)) {
      chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
      shelltp = NULL;           /* Triggers spawning of a new shell.        */
    }   
    chThdSleepMilliseconds(1000);
  }
}
