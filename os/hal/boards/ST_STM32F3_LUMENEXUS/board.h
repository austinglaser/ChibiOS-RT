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

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for STMicroelectronics STM32F3-Discovery board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_STM32F3_DISCOVERY
#define BOARD_NAME                  "Luminexus (STM32F3)"

/*
 * Board oscillators-related settings.
 */
#if !defined(STM32_LSECLK)
#define STM32_LSECLK                0
#endif

#define STM32_LSEDRV                (3 << 3)

#if !defined(STM32_HSECLK)
#define STM32_HSECLK                8000000
#endif

/*
 * MCU type as defined in the ST header.
 */
#define STM32F30X

/*
 * IO pins assignments.
 */
#define GPIOA_BUTTON                0
#define GPIOA_WS2812                1
#define GPIOA_TX2                   2
#define GPIOA_RX2                   3
#define GPIOA_DAC                   4
#define GPIOA_BOOT_OUT_2            5
#define GPIOA_RESET_OUT_2           6
#define GPIOA_RESET_OUT_1           7
#define GPIOA_BOOT_OUT_1            8
#define GPIOA_TX1                   9
#define GPIOA_RX1                   10
#define GPIOA_USB_DM                11
#define GPIOA_USB_DP                12
#define GPIOA_SWDIO                 13
#define GPIOA_SWCLK                 14
#define GPIOA_JTDI                  15

#define GPIOB_MIC_OUT               0
#define GPIOB_VIN_SENSE             1
#define GPIOB_V_TEMP                2
#define GPIOB_JTDO                  3
#define GPIOB_MISO3                 4
#define GPIOB_MODE                  5
#define GPIOB_GAIN                  6
#define GPIOB_A_R                   7
#define GPIOB_BOOT_OUT_3            8
#define GPIOB_RESET_OUT_3           9
#define GPIOB_TX3                   10
#define GPIOB_RX3                   11
#define GPIOB_NSS2                  12
#define GPIOB_SCK2                  13
#define GPIOB_MISO2                 14
#define GPIOB_MOSI2                 15

#define GPIOC_PIN0                  0
#define GPIOC_PIN1                  1
#define GPIOC_PIN2                  2
#define GPIOC_PIN3                  3
#define GPIOC_PIN4                  4
#define GPIOC_PIN5                  5
#define GPIOC_PIN6                  6
#define GPIOC_PIN7                  7
#define GPIOC_PIN8                  8
#define GPIOC_PIN9                  9
#define GPIOC_PIN10                 10
#define GPIOC_PIN11                 11
#define GPIOC_PIN12                 12
#define GPIOC_BIT0                  13
#define GPIOC_BIT1                  14
#define GPIOC_BIT2                  15

#define GPIOD_PIN0                  0
#define GPIOD_PIN1                  1
#define GPIOD_PIN2                  2
#define GPIOD_PIN3                  3
#define GPIOD_PIN4                  4
#define GPIOD_PIN5                  5
#define GPIOD_PIN6                  6
#define GPIOD_PIN7                  7
#define GPIOD_PIN8                  8
#define GPIOD_PIN9                  9
#define GPIOD_PIN10                 10
#define GPIOD_PIN11                 11
#define GPIOD_PIN12                 12
#define GPIOD_PIN13                 13
#define GPIOD_PIN14                 14
#define GPIOD_PIN15                 15

#define GPIOE_L3GD20_INT1           0
#define GPIOE_L3GD20_INT2           1
#define GPIOE_LSM303_DRDY           2
#define GPIOE_SPI1_CS               3
#define GPIOE_LSM303_INT1           4
#define GPIOE_LSM303_INT2           5
#define GPIOE_PIN6                  6
#define GPIOE_PIN7                  7
#define GPIOE_LED4_BLUE             8
#define GPIOE_LED3_RED              9
#define GPIOE_LED5_ORANGE           10
#define GPIOE_LED7_GREEN            11
#define GPIOE_LED9_BLUE             12
#define GPIOE_LED10_RED             13
#define GPIOE_LED8_ORANGE           14
#define GPIOE_LED6_GREEN            15

#define GPIOF_OSC_IN                0
#define GPIOF_OSC_OUT               1
#define GPIOF_PIN2                  2
#define GPIOF_PIN3                  3
#define GPIOF_PIN4                  4
#define GPIOF_PIN5                  5
#define GPIOF_PIN6                  6
#define GPIOF_PIN7                  7
#define GPIOF_PIN8                  8
#define GPIOF_PIN9                  9
#define GPIOF_PIN10                 10
#define GPIOF_PIN11                 11
#define GPIOF_PIN12                 12
#define GPIOF_PIN13                 13
#define GPIOF_PIN14                 14
#define GPIOF_PIN15                 15

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0U << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1U << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2U << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3U << ((n) * 2))
#define PIN_ODR_LOW(n)              (0U << (n))
#define PIN_ODR_HIGH(n)             (1U << (n))
#define PIN_OTYPE_PUSHPULL(n)       (0U << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1U << (n))
#define PIN_OSPEED_2M(n)            (0U << ((n) * 2))
#define PIN_OSPEED_25M(n)           (1U << ((n) * 2))
#define PIN_OSPEED_50M(n)           (2U << ((n) * 2))
#define PIN_OSPEED_100M(n)          (3U << ((n) * 2))
#define PIN_PUPDR_FLOATING(n)       (0U << ((n) * 2))
#define PIN_PUPDR_PULLUP(n)         (1U << ((n) * 2))
#define PIN_PUPDR_PULLDOWN(n)       (2U << ((n) * 2))
#define PIN_AFIO_AF(n, v)           ((v##U) << (((n) % 8) * 4))

/*
 * GPIOA setup:                     
 *
 * PA0  - BUTTON                    (input floating).
 * PA1  - WS2812                    (output pushpull).
 * PA2  - TX2                       (alternate 7).
 * PA3  - RX2                       (alternate 7).
 * PA4  - DAC                       (input floating). NOTE: no DAC AF. automatically controls pin on enable
 * PA5  - BOOT_OUT_2                (input floating).
 * PA6  - RESET_OUT_2               (input floating).
 * PA7  - RESET_OUT_1               (input floating).
 * PA8  - BOOT_OUT_1                (input floating).
 * PA9  - TX1                       (alternate 7).
 * PA10 - RX1                       (alternate 7).
 * PA11 - USB_DM                    (alternate 14).
 * PA12 - USB_DP                    (alternate 14).
 * PA13 - SWDIO                     (input floating).
 * PA14 - SWCLK                     (input floating).
 * PA15 - JTDI                      (input floating).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_INPUT(GPIOA_BUTTON) |           \
                                     PIN_MODE_INPUT(GPIOA_WS2812) |           \
                                     PIN_MODE_ALTERNATE(GPIOA_TX2) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_RX2) |          \
                                     PIN_MODE_INPUT(GPIOA_DAC) |              \
                                     PIN_MODE_INPUT(GPIOA_BOOT_OUT_2) |       \
                                     PIN_MODE_INPUT(GPIOA_RESET_OUT_2) |      \
                                     PIN_MODE_INPUT(GPIOA_RESET_OUT_1) |      \
                                     PIN_MODE_INPUT(GPIOA_BOOT_OUT_1) |       \
                                     PIN_MODE_ALTERNATE(GPIOA_TX1) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_RX1) |          \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_DM) |       \
                                     PIN_MODE_ALTERNATE(GPIOA_USB_DP) |       \
                                     PIN_MODE_INPUT(GPIOA_SWDIO) |            \
                                     PIN_MODE_INPUT(GPIOA_SWCLK) |            \
                                     PIN_MODE_INPUT(GPIOA_JTDI))
#define VAL_GPIOA_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOA_BUTTON) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_WS2812) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_TX2) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RX2) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOA_DAC) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOA_BOOT_OUT_2) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RESET_OUT_2) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RESET_OUT_1) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOA_BOOT_OUT_1) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOA_TX1) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOA_RX1) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DM) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_USB_DP) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWDIO) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_SWCLK) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOA_JTDI))
#define VAL_GPIOA_OSPEEDR           (PIN_OSPEED_2M(GPIOA_BUTTON) |            \
                                     PIN_OSPEED_2M(GPIOA_WS2812) |            \
                                     PIN_OSPEED_100M(GPIOA_TX2) |             \
                                     PIN_OSPEED_100M(GPIOA_RX2) |             \
                                     PIN_OSPEED_100M(GPIOA_DAC) |             \
                                     PIN_OSPEED_2M(GPIOA_BOOT_OUT_2) |        \
                                     PIN_OSPEED_2M(GPIOA_RESET_OUT_2) |       \
                                     PIN_OSPEED_2M(GPIOA_RESET_OUT_1) |       \
                                     PIN_OSPEED_2M(GPIOA_BOOT_OUT_1) |        \
                                     PIN_OSPEED_100M(GPIOA_TX1) |             \
                                     PIN_OSPEED_100M(GPIOA_RX1) |             \
                                     PIN_OSPEED_100M(GPIOA_USB_DM) |          \
                                     PIN_OSPEED_2M(GPIOA_USB_DP) |            \
                                     PIN_OSPEED_100M(GPIOA_SWDIO) |           \
                                     PIN_OSPEED_100M(GPIOA_SWCLK) |           \
                                     PIN_OSPEED_2M(GPIOA_JTDI))
#define VAL_GPIOA_PUPDR             (PIN_PUPDR_FLOATING(GPIOA_BUTTON) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_WS2812) |         \
                                     PIN_PUPDR_FLOATING(GPIOA_TX2) |          \
                                     PIN_PUPDR_FLOATING(GPIOA_RX2) |          \
                                     PIN_PUPDR_FLOATING(GPIOA_DAC) |          \
                                     PIN_PUPDR_FLOATING(GPIOA_BOOT_OUT_2) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_RESET_OUT_2) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_RESET_OUT_1) |  \
                                     PIN_PUPDR_FLOATING(GPIOA_BOOT_OUT_1) |   \
                                     PIN_PUPDR_FLOATING(GPIOA_TX1) |          \
                                     PIN_PUPDR_FLOATING(GPIOA_RX1) |          \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DM) |       \
                                     PIN_PUPDR_FLOATING(GPIOA_USB_DP) |       \
                                     PIN_PUPDR_PULLUP(GPIOA_SWDIO) |          \
                                     PIN_PUPDR_PULLDOWN(GPIOA_SWCLK) |        \
                                     PIN_PUPDR_PULLUP(GPIOA_JTDI))
#define VAL_GPIOA_ODR               (PIN_ODR_HIGH(GPIOA_BUTTON) |             \
                                     PIN_ODR_HIGH(GPIOA_WS2812) |             \
                                     PIN_ODR_HIGH(GPIOA_TX2) |                \
                                     PIN_ODR_HIGH(GPIOA_RX2) |                \
                                     PIN_ODR_HIGH(GPIOA_DAC) |                \
                                     PIN_ODR_HIGH(GPIOA_BOOT_OUT_2) |         \
                                     PIN_ODR_HIGH(GPIOA_RESET_OUT_2) |        \
                                     PIN_ODR_HIGH(GPIOA_RESET_OUT_1) |        \
                                     PIN_ODR_HIGH(GPIOA_BOOT_OUT_1) |         \
                                     PIN_ODR_HIGH(GPIOA_TX1) |                \
                                     PIN_ODR_HIGH(GPIOA_RX1) |                \
                                     PIN_ODR_HIGH(GPIOA_USB_DM) |             \
                                     PIN_ODR_HIGH(GPIOA_USB_DP) |             \
                                     PIN_ODR_HIGH(GPIOA_SWDIO) |              \
                                     PIN_ODR_HIGH(GPIOA_SWCLK) |              \
                                     PIN_ODR_HIGH(GPIOA_JTDI))
#define VAL_GPIOA_AFRL              (PIN_AFIO_AF(GPIOA_BUTTON, 0) |           \
                                     PIN_AFIO_AF(GPIOA_WS2812, 0) |           \
                                     PIN_AFIO_AF(GPIOA_TX2, 7) |              \
                                     PIN_AFIO_AF(GPIOA_RX2, 7) |              \
                                     PIN_AFIO_AF(GPIOA_DAC, 0) |              \
                                     PIN_AFIO_AF(GPIOA_BOOT_OUT_2, 0) |       \
                                     PIN_AFIO_AF(GPIOA_RESET_OUT_2, 0) |      \
                                     PIN_AFIO_AF(GPIOA_RESET_OUT_1, 0))
#define VAL_GPIOA_AFRH              (PIN_AFIO_AF(GPIOA_BOOT_OUT_1, 0) |       \
                                     PIN_AFIO_AF(GPIOA_TX1, 7) |              \
                                     PIN_AFIO_AF(GPIOA_RX1, 7) |              \
                                     PIN_AFIO_AF(GPIOA_USB_DM, 14) |          \
                                     PIN_AFIO_AF(GPIOA_USB_DP, 14) |          \
                                     PIN_AFIO_AF(GPIOA_SWDIO, 0) |            \
                                     PIN_AFIO_AF(GPIOA_SWCLK, 0) |            \
                                     PIN_AFIO_AF(GPIOA_JTDI, 0))

/*
 * GPIOB setup:
 *
 * PB0  - MIC_OUT                   (input floating). NOTE: no ADC alternate function.
 * PB1  - VIN_SENSE                 (input floating). NOTE: no ADC alternate function. 
 * PB2  - V_TEMP                    (input floating). NOTE: no ADC alternate function. 
 * PB3  - JTDO                      (floating input). NOTE: Could be JTAG/mic clock
 * PB4  - MISO3                     (floating input).
 * PB5  - MODE                      (output push/pull).
 * PB6  - GAIN                      (output push/pull).
 * PB7  - A_R                       (output push/pull).
 * PB8  - BOOT_OUT_3                (input floating).
 * PB9  - RESET_OUT_3               (input floating).
 * PB10 - TX3                       (alternate 7).
 * PB11 - RX3                       (alternate 7).
 * PB12 - NSS2                      (input floating).
 * PB13 - SCK2                      (input floating).
 * PB14 - MISO2                     (input floating).
 * PB15 - MOSI2                     (input floating).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_INPUT(GPIOB_MIC_OUT) |          \
                                     PIN_MODE_INPUT(GPIOB_VIN_SENSE) |        \
                                     PIN_MODE_INPUT(GPIOB_V_TEMP) |           \
                                     PIN_MODE_INPUT(GPIOB_JTDO) |             \
                                     PIN_MODE_INPUT(GPIOB_MISO3) |            \
                                     PIN_MODE_OUTPUT(GPIOB_MODE) |            \
                                     PIN_MODE_OUTPUT(GPIOB_GAIN) |            \
                                     PIN_MODE_OUTPUT(GPIOB_A_R) |             \
                                     PIN_MODE_INPUT(GPIOB_BOOT_OUT_3) |       \
                                     PIN_MODE_INPUT(GPIOB_RESET_OUT_3) |      \
                                     PIN_MODE_ALTERNATE(GPIOB_TX3) |          \
                                     PIN_MODE_ALTERNATE(GPIOB_RX3) |          \
                                     PIN_MODE_INPUT(GPIOB_NSS2) |             \
                                     PIN_MODE_INPUT(GPIOB_SCK2) |             \
                                     PIN_MODE_INPUT(GPIOB_MISO2) |            \
                                     PIN_MODE_INPUT(GPIOB_MOSI2))
#define VAL_GPIOB_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOB_MIC_OUT) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOB_VIN_SENSE) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOB_V_TEMP) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOB_JTDO) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_MISO3) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_MODE) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_GAIN) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_A_R) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOB_BOOT_OUT_3) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOB_RESET_OUT_3) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOB_TX3) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOB_RX3) |          \
                                     PIN_OTYPE_PUSHPULL(GPIOB_NSS2) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_SCK2) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOB_MISO2) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOB_MOSI2))
#define VAL_GPIOB_OSPEEDR           (PIN_OSPEED_100M(GPIOB_MIC_OUT) |         \
                                     PIN_OSPEED_100M(GPIOB_VIN_SENSE) |       \
                                     PIN_OSPEED_100M(GPIOB_V_TEMP) |          \
                                     PIN_OSPEED_100M(GPIOB_JTDO) |            \
                                     PIN_OSPEED_2M(GPIOB_MISO3) |             \
                                     PIN_OSPEED_2M(GPIOB_MODE) |              \
                                     PIN_OSPEED_2M(GPIOB_GAIN) |              \
                                     PIN_OSPEED_2M(GPIOB_A_R) |               \
                                     PIN_OSPEED_2M(GPIOB_BOOT_OUT_3) |        \
                                     PIN_OSPEED_2M(GPIOB_RESET_OUT_3) |       \
                                     PIN_OSPEED_100M(GPIOB_TX3) |             \
                                     PIN_OSPEED_100M(GPIOB_RX3) |             \
                                     PIN_OSPEED_2M(GPIOB_NSS2) |              \
                                     PIN_OSPEED_2M(GPIOB_SCK2) |              \
                                     PIN_OSPEED_2M(GPIOB_MISO2) |             \
                                     PIN_OSPEED_2M(GPIOB_MOSI2))
#define VAL_GPIOB_PUPDR             (PIN_PUPDR_FLOATING(GPIOB_MIC_OUT) |      \
                                     PIN_PUPDR_FLOATING(GPIOB_VIN_SENSE) |    \
                                     PIN_PUPDR_FLOATING(GPIOB_V_TEMP) |       \
                                     PIN_PUPDR_FLOATING(GPIOB_JTDO) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_MISO3) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_MODE) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_GAIN) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_A_R) |          \
                                     PIN_PUPDR_FLOATING(GPIOB_BOOT_OUT_3) |   \
                                     PIN_PUPDR_FLOATING(GPIOB_RESET_OUT_3) |  \
                                     PIN_PUPDR_FLOATING(GPIOB_TX3) |          \
                                     PIN_PUPDR_FLOATING(GPIOB_RX3) |          \
                                     PIN_PUPDR_FLOATING(GPIOB_NSS2) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_SCK2) |         \
                                     PIN_PUPDR_FLOATING(GPIOB_MISO2) |        \
                                     PIN_PUPDR_FLOATING(GPIOB_MOSI2))
#define VAL_GPIOB_ODR               (PIN_ODR_HIGH(GPIOB_MIC_OUT) |            \
                                     PIN_ODR_HIGH(GPIOB_VIN_SENSE) |          \
                                     PIN_ODR_HIGH(GPIOB_V_TEMP) |             \
                                     PIN_ODR_HIGH(GPIOB_JTDO) |               \
                                     PIN_ODR_HIGH(GPIOB_MISO3) |              \
                                     PIN_ODR_HIGH(GPIOB_MODE) |               \
                                     PIN_ODR_HIGH(GPIOB_GAIN) |               \
                                     PIN_ODR_HIGH(GPIOB_A_R) |                \
                                     PIN_ODR_HIGH(GPIOB_BOOT_OUT_3) |         \
                                     PIN_ODR_HIGH(GPIOB_RESET_OUT_3) |        \
                                     PIN_ODR_HIGH(GPIOB_TX3) |                \
                                     PIN_ODR_HIGH(GPIOB_RX3) |                \
                                     PIN_ODR_HIGH(GPIOB_NSS2) |               \
                                     PIN_ODR_HIGH(GPIOB_SCK2) |               \
                                     PIN_ODR_HIGH(GPIOB_MISO2) |              \
                                     PIN_ODR_HIGH(GPIOB_MOSI2))
#define VAL_GPIOB_AFRL              (PIN_AFIO_AF(GPIOB_MIC_OUT, 0) |          \
                                     PIN_AFIO_AF(GPIOB_VIN_SENSE, 0) |        \
                                     PIN_AFIO_AF(GPIOB_V_TEMP, 0) |           \
                                     PIN_AFIO_AF(GPIOB_JTDO, 0) |             \
                                     PIN_AFIO_AF(GPIOB_MISO3, 0) |            \
                                     PIN_AFIO_AF(GPIOB_MODE, 0) |             \
                                     PIN_AFIO_AF(GPIOB_GAIN, 0) |             \
                                     PIN_AFIO_AF(GPIOB_A_R, 0))
#define VAL_GPIOB_AFRH              (PIN_AFIO_AF(GPIOB_BOOT_OUT_3, 0) |       \
                                     PIN_AFIO_AF(GPIOB_RESET_OUT_3, 0) |      \
                                     PIN_AFIO_AF(GPIOB_TX3, 7) |              \
                                     PIN_AFIO_AF(GPIOB_RX3, 7) |              \
                                     PIN_AFIO_AF(GPIOB_NSS2, 0) |             \
                                     PIN_AFIO_AF(GPIOB_SCK2, 0) |             \
                                     PIN_AFIO_AF(GPIOB_MISO2, 0) |            \
                                     PIN_AFIO_AF(GPIOB_MOSI2, 0))

/*
 * GPIOC setup:
 *
 * PC0  - PIN0                      (input pullup).
 * PC1  - PIN1                      (input pullup).
 * PC2  - PIN2                      (input pullup).
 * PC3  - PIN3                      (input pullup).
 * PC4  - PIN4                      (input pullup).
 * PC5  - PIN5                      (input pullup).
 * PC6  - PIN6                      (input pullup).
 * PC7  - PIN7                      (input pullup).
 * PC8  - PIN8                      (input pullup).
 * PC9  - PIN9                      (input pullup).
 * PC10 - PIN10                     (input pullup).
 * PC11 - PIN11                     (input pullup).
 * PC12 - PIN12                     (input pullup).
 * PC13 - BIT0                      (input floating).
 * PC14 - BIT1                      (input floating).
 * PC15 - BIT2                      (input floating).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_INPUT(GPIOC_PIN0) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN1) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN2) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN3) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN4) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN5) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN6) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN7) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN8) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN9) |             \
                                     PIN_MODE_INPUT(GPIOC_PIN10) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN11) |            \
                                     PIN_MODE_INPUT(GPIOC_PIN12) |            \
                                     PIN_MODE_INPUT(GPIOC_BIT0) |             \
                                     PIN_MODE_INPUT(GPIOC_BIT1) |             \
                                     PIN_MODE_INPUT(GPIOC_BIT2))
#define VAL_GPIOC_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOC_PIN0) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN1) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN2) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN3) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN4) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN5) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN6) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN7) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN8) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN9) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN10) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN11) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOC_PIN12) |        \
                                     PIN_OTYPE_PUSHPULL(GPIOC_BIT0) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_BIT1) |         \
                                     PIN_OTYPE_PUSHPULL(GPIOC_BIT2))
#define VAL_GPIOC_OSPEEDR           (PIN_OSPEED_2M(GPIOC_PIN0) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN1) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN2) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN3) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN4) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN5) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN6) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN7) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN8) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN9) |              \
                                     PIN_OSPEED_2M(GPIOC_PIN10) |             \
                                     PIN_OSPEED_2M(GPIOC_PIN11) |             \
                                     PIN_OSPEED_2M(GPIOC_PIN12) |             \
                                     PIN_OSPEED_2M(GPIOC_BIT0) |              \
                                     PIN_OSPEED_2M(GPIOC_BIT1) |              \
                                     PIN_OSPEED_2M(GPIOC_BIT2))
#define VAL_GPIOC_PUPDR             (PIN_PUPDR_PULLUP(GPIOC_PIN0) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN1) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN2) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN3) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN4) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN5) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN6) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN7) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN8) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN9) |           \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN10) |          \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN11) |          \
                                     PIN_PUPDR_PULLUP(GPIOC_PIN12) |          \
                                     PIN_PUPDR_FLOATING(GPIOC_BIT0) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_BIT1) |         \
                                     PIN_PUPDR_FLOATING(GPIOC_BIT2))
#define VAL_GPIOC_ODR               (PIN_ODR_HIGH(GPIOC_PIN0) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN1) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN2) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN3) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN4) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN5) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN6) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN7) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN8) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN9) |               \
                                     PIN_ODR_HIGH(GPIOC_PIN10) |              \
                                     PIN_ODR_HIGH(GPIOC_PIN11) |              \
                                     PIN_ODR_HIGH(GPIOC_PIN12) |              \
                                     PIN_ODR_HIGH(GPIOC_BIT0) |               \
                                     PIN_ODR_HIGH(GPIOC_BIT1) |               \
                                     PIN_ODR_HIGH(GPIOC_BIT2))
#define VAL_GPIOC_AFRL              (PIN_AFIO_AF(GPIOC_PIN0, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN1, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN2, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN3, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN4, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN5, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN6, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN7, 0))
#define VAL_GPIOC_AFRH              (PIN_AFIO_AF(GPIOC_PIN8, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN9, 0) |             \
                                     PIN_AFIO_AF(GPIOC_PIN10, 0) |            \
                                     PIN_AFIO_AF(GPIOC_PIN11, 0) |            \
                                     PIN_AFIO_AF(GPIOC_PIN12, 0) |            \
                                     PIN_AFIO_AF(GPIOC_BIT0, 0) |             \
                                     PIN_AFIO_AF(GPIOC_BIT1, 0) |             \
                                     PIN_AFIO_AF(GPIOC_BIT2, 0))

/*
 * GPIOD setup:
 *
 * PD0  - PIN0                      (input pullup).
 * PD1  - PIN1                      (input pullup).
 * PD2  - PIN2                      (input pullup).
 * PD3  - PIN3                      (input pullup).
 * PD4  - PIN4                      (input pullup).
 * PD5  - PIN5                      (input pullup).
 * PD6  - PIN6                      (input pullup).
 * PD7  - PIN7                      (input pullup).
 * PD8  - PIN8                      (input pullup).
 * PD9  - PIN9                      (input pullup).
 * PD10 - PIN10                     (input pullup).
 * PD11 - PIN11                     (input pullup).
 * PD12 - PIN12                     (input pullup).
 * PD13 - PIN13                     (input pullup).
 * PD14 - PIN14                     (input pullup).
 * PD15 - PIN15                     (input pullup).
 */
#define VAL_GPIOD_MODER             (PIN_MODE_INPUT(GPIOD_PIN0) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN1) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOD_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOD_PIN15))
#define VAL_GPIOD_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOD_PIN0) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN1) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOD_PIN15))
#define VAL_GPIOD_OSPEEDR           (PIN_OSPEED_2M(GPIOD_PIN0) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN1) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN2) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN3) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN4) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN5) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN6) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN7) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN8) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN9) |            \
                                     PIN_OSPEED_2M(GPIOD_PIN10) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN11) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN12) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN13) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN14) |           \
                                     PIN_OSPEED_2M(GPIOD_PIN15))
#define VAL_GPIOD_PUPDR             (PIN_PUPDR_PULLUP(GPIOD_PIN0) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN1) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOD_PIN15))
#define VAL_GPIOD_ODR               (PIN_ODR_HIGH(GPIOD_PIN0) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN1) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOD_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOD_PIN15))
#define VAL_GPIOD_AFRL              (PIN_AFIO_AF(GPIOD_PIN0, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN1, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN2, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN3, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN4, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN5, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN6, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN7, 0))
#define VAL_GPIOD_AFRH              (PIN_AFIO_AF(GPIOD_PIN8, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN9, 0) |           \
                                     PIN_AFIO_AF(GPIOD_PIN10, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN11, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN12, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN13, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN14, 0) |          \
                                     PIN_AFIO_AF(GPIOD_PIN15, 0))

/*
 * GPIOE setup:
 *
 * PE0  - L3GD20_INT1               (input pullup).
 * PE1  - L3GD20_INT2               (input pullup).
 * PE2  - LSM303_DRDY               (input pullup).
 * PE3  - SPI1_CS                   (output pushpull maximum).
 * PE4  - LSM303_INT1               (input pullup).
 * PE5  - LSM303_INT2               (input pullup).
 * PE6  - PIN6                      (input pullup).
 * PE7  - PIN7                      (input pullup).
 * PE8  - LED4_BLUE                 (output pushpull maximum).
 * PE9  - LED3_RED                  (output pushpull maximum).
 * PE10 - LED5_ORANGE               (output pushpull maximum).
 * PE11 - LED7_GREEN                (output pushpull maximum).
 * PE12 - LED9_BLUE                 (output pushpull maximum).
 * PE13 - LED10_RED                 (output pushpull maximum).
 * PE14 - LED8_ORANGE               (output pushpull maximum).
 * PE15 - LED6_GREEN                (output pushpull maximum).
 */
#define VAL_GPIOE_MODER             (PIN_MODE_INPUT(GPIOE_L3GD20_INT1) |    \
                                     PIN_MODE_INPUT(GPIOE_L3GD20_INT2) |    \
                                     PIN_MODE_INPUT(GPIOE_LSM303_DRDY) |    \
                                     PIN_MODE_OUTPUT(GPIOE_SPI1_CS) |       \
                                     PIN_MODE_INPUT(GPIOE_LSM303_INT1) |    \
                                     PIN_MODE_INPUT(GPIOE_LSM303_INT2) |    \
                                     PIN_MODE_INPUT(GPIOE_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOE_PIN7) |           \
                                     PIN_MODE_OUTPUT(GPIOE_LED4_BLUE) |     \
                                     PIN_MODE_OUTPUT(GPIOE_LED3_RED) |      \
                                     PIN_MODE_OUTPUT(GPIOE_LED5_ORANGE) |   \
                                     PIN_MODE_OUTPUT(GPIOE_LED7_GREEN) |    \
                                     PIN_MODE_OUTPUT(GPIOE_LED9_BLUE) |     \
                                     PIN_MODE_OUTPUT(GPIOE_LED10_RED) |     \
                                     PIN_MODE_OUTPUT(GPIOE_LED8_ORANGE) |   \
                                     PIN_MODE_OUTPUT(GPIOE_LED6_GREEN))
#define VAL_GPIOE_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOE_L3GD20_INT1) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_L3GD20_INT2) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_LSM303_DRDY) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_SPI1_CS) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LSM303_INT1) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_LSM303_INT2) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED4_BLUE) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED3_RED) |   \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED5_ORANGE) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED7_GREEN) | \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED9_BLUE) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED10_RED) |  \
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED8_ORANGE) |\
                                     PIN_OTYPE_PUSHPULL(GPIOE_LED6_GREEN))
#define VAL_GPIOE_OSPEEDR           (PIN_OSPEED_2M(GPIOE_L3GD20_INT1) |     \
                                     PIN_OSPEED_2M(GPIOE_L3GD20_INT2) |     \
                                     PIN_OSPEED_2M(GPIOE_LSM303_DRDY) |     \
                                     PIN_OSPEED_100M(GPIOE_SPI1_CS) |       \
                                     PIN_OSPEED_2M(GPIOE_LSM303_INT1) |     \
                                     PIN_OSPEED_2M(GPIOE_LSM303_INT2) |     \
                                     PIN_OSPEED_2M(GPIOE_PIN6) |            \
                                     PIN_OSPEED_2M(GPIOE_PIN7) |            \
                                     PIN_OSPEED_100M(GPIOE_LED4_BLUE) |     \
                                     PIN_OSPEED_100M(GPIOE_LED3_RED) |      \
                                     PIN_OSPEED_100M(GPIOE_LED5_ORANGE) |   \
                                     PIN_OSPEED_100M(GPIOE_LED7_GREEN) |    \
                                     PIN_OSPEED_100M(GPIOE_LED9_BLUE) |     \
                                     PIN_OSPEED_100M(GPIOE_LED10_RED) |     \
                                     PIN_OSPEED_100M(GPIOE_LED8_ORANGE) |   \
                                     PIN_OSPEED_100M(GPIOE_LED6_GREEN))
#define VAL_GPIOE_PUPDR             (PIN_PUPDR_PULLUP(GPIOE_L3GD20_INT1) |  \
                                     PIN_PUPDR_PULLUP(GPIOE_L3GD20_INT2) |  \
                                     PIN_PUPDR_PULLUP(GPIOE_LSM303_DRDY) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_SPI1_CS) |    \
                                     PIN_PUPDR_PULLUP(GPIOE_LSM303_INT1) |  \
                                     PIN_PUPDR_PULLUP(GPIOE_LSM303_INT2) |  \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOE_LED4_BLUE) |    \
                                     PIN_PUPDR_PULLUP(GPIOE_LED3_RED) |     \
                                     PIN_PUPDR_PULLUP(GPIOE_LED5_ORANGE) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_LED7_GREEN) | \
                                     PIN_PUPDR_PULLUP(GPIOE_LED9_BLUE) |    \
                                     PIN_PUPDR_FLOATING(GPIOE_LED10_RED) |  \
                                     PIN_PUPDR_FLOATING(GPIOE_LED8_ORANGE) |\
                                     PIN_PUPDR_FLOATING(GPIOE_LED6_GREEN))
#define VAL_GPIOE_ODR               (PIN_ODR_HIGH(GPIOE_L3GD20_INT1) |      \
                                     PIN_ODR_HIGH(GPIOE_L3GD20_INT2) |      \
                                     PIN_ODR_HIGH(GPIOE_LSM303_DRDY) |      \
                                     PIN_ODR_HIGH(GPIOE_SPI1_CS) |          \
                                     PIN_ODR_HIGH(GPIOE_LSM303_INT1) |      \
                                     PIN_ODR_HIGH(GPIOE_LSM303_INT2) |      \
                                     PIN_ODR_HIGH(GPIOE_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOE_PIN7) |             \
                                     PIN_ODR_LOW(GPIOE_LED4_BLUE) |         \
                                     PIN_ODR_LOW(GPIOE_LED3_RED) |          \
                                     PIN_ODR_LOW(GPIOE_LED5_ORANGE) |       \
                                     PIN_ODR_LOW(GPIOE_LED7_GREEN) |        \
                                     PIN_ODR_LOW(GPIOE_LED9_BLUE) |         \
                                     PIN_ODR_LOW(GPIOE_LED10_RED) |         \
                                     PIN_ODR_LOW(GPIOE_LED8_ORANGE) |       \
                                     PIN_ODR_LOW(GPIOE_LED6_GREEN))
#define VAL_GPIOE_AFRL              (PIN_AFIO_AF(GPIOE_L3GD20_INT1, 0) |    \
                                     PIN_AFIO_AF(GPIOE_L3GD20_INT2, 0) |    \
                                     PIN_AFIO_AF(GPIOE_LSM303_DRDY, 0) |    \
                                     PIN_AFIO_AF(GPIOE_SPI1_CS, 0) |        \
                                     PIN_AFIO_AF(GPIOE_LSM303_INT1, 0) |    \
                                     PIN_AFIO_AF(GPIOE_LSM303_INT2, 0) |    \
                                     PIN_AFIO_AF(GPIOE_PIN6, 0) |           \
                                     PIN_AFIO_AF(GPIOE_PIN7, 0))
#define VAL_GPIOE_AFRH              (PIN_AFIO_AF(GPIOE_LED4_BLUE, 0) |      \
                                     PIN_AFIO_AF(GPIOE_LED3_RED, 0) |       \
                                     PIN_AFIO_AF(GPIOE_LED5_ORANGE, 0) |    \
                                     PIN_AFIO_AF(GPIOE_LED7_GREEN, 0) |     \
                                     PIN_AFIO_AF(GPIOE_LED9_BLUE, 0) |      \
                                     PIN_AFIO_AF(GPIOE_LED10_RED, 0) |      \
                                     PIN_AFIO_AF(GPIOE_LED8_ORANGE, 0) |    \
                                     PIN_AFIO_AF(GPIOE_LED6_GREEN, 0))

/*
 * GPIOF setup:
 *
 * PF0  - OSC_IN                    (input floating).
 * PF1  - OSC_OUT                   (input floating).
 * PF2  - PIN2                      (input pullup).
 * PF3  - PIN3                      (input pullup).
 * PF4  - PIN4                      (input pullup).
 * PF5  - PIN5                      (input pullup).
 * PF6  - PIN6                      (input pullup).
 * PF7  - PIN7                      (input pullup).
 * PF8  - PIN8                      (input pullup).
 * PF9  - PIN9                      (input pullup).
 * PF10 - PIN10                     (input pullup).
 * PF11 - PIN11                     (input pullup).
 * PF12 - PIN12                     (input pullup).
 * PF13 - PIN13                     (input pullup).
 * PF14 - PIN14                     (input pullup).
 * PF15 - PIN15                     (input pullup).
 */
#define VAL_GPIOF_MODER             (PIN_MODE_INPUT(GPIOF_OSC_IN) |         \
                                     PIN_MODE_INPUT(GPIOF_OSC_OUT) |        \
                                     PIN_MODE_INPUT(GPIOF_PIN2) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN3) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN4) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN5) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN6) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN7) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN8) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN9) |           \
                                     PIN_MODE_INPUT(GPIOF_PIN10) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN11) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN12) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN13) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN14) |          \
                                     PIN_MODE_INPUT(GPIOF_PIN15))
#define VAL_GPIOF_OTYPER            (PIN_OTYPE_PUSHPULL(GPIOF_OSC_IN) |     \
                                     PIN_OTYPE_PUSHPULL(GPIOF_OSC_OUT) |    \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN2) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN3) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN4) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN5) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN6) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN7) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN8) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN9) |       \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN10) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN11) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN12) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN13) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN14) |      \
                                     PIN_OTYPE_PUSHPULL(GPIOF_PIN15))
#define VAL_GPIOF_OSPEEDR           (PIN_OSPEED_100M(GPIOF_OSC_IN) |        \
                                     PIN_OSPEED_100M(GPIOF_OSC_OUT) |       \
                                     PIN_OSPEED_2M(GPIOF_PIN2) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN3) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN4) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN5) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN6) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN7) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN8) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN9) |            \
                                     PIN_OSPEED_2M(GPIOF_PIN10) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN11) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN12) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN13) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN14) |           \
                                     PIN_OSPEED_2M(GPIOF_PIN15))
#define VAL_GPIOF_PUPDR             (PIN_PUPDR_FLOATING(GPIOF_OSC_IN) |     \
                                     PIN_PUPDR_FLOATING(GPIOF_OSC_OUT) |    \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN2) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN3) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN4) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN5) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN6) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN7) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN8) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN9) |         \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN10) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN11) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN12) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN13) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN14) |        \
                                     PIN_PUPDR_PULLUP(GPIOF_PIN15))
#define VAL_GPIOF_ODR               (PIN_ODR_HIGH(GPIOF_OSC_IN) |           \
                                     PIN_ODR_HIGH(GPIOF_OSC_OUT) |          \
                                     PIN_ODR_HIGH(GPIOF_PIN2) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN3) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN4) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN5) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN6) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN7) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN8) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN9) |             \
                                     PIN_ODR_HIGH(GPIOF_PIN10) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN11) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN12) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN13) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN14) |            \
                                     PIN_ODR_HIGH(GPIOF_PIN15))
#define VAL_GPIOF_AFRL              (PIN_AFIO_AF(GPIOF_OSC_IN, 0) |         \
                                     PIN_AFIO_AF(GPIOF_OSC_OUT, 0) |        \
                                     PIN_AFIO_AF(GPIOF_PIN2, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN3, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN4, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN5, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN6, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN7, 0))
#define VAL_GPIOF_AFRH              (PIN_AFIO_AF(GPIOF_PIN8, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN9, 0) |           \
                                     PIN_AFIO_AF(GPIOF_PIN10, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN11, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN12, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN13, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN14, 0) |          \
                                     PIN_AFIO_AF(GPIOF_PIN15, 0))


#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
