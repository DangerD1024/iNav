/*
 * This file is part of INAV.
 *
 * INAV is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INAV is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INAV.  If not, see <http://www.gnu.org/licenses/>.
 */

// Matek H7A3-SLIM, STM32H7A3RIT6, 16MHz HSE
// Pinout taken from ArduPilot libraries/AP_HAL_ChibiOS/hwdef/MatekH7A3/hwdef.inc

#pragma once

#define TARGET_BOARD_IDENTIFIER "H7A3"
#define USBD_PRODUCT_STRING     "MATEKH7A3"

#define USE_TARGET_CONFIG

// PA8/PC9 (MCO1/MCO2) are used by I2C3
#define DISABLE_MCO_OUTPUTS

// PA13/PA14 are shared with SWD
#define LED0                    PA14  // Blue, ACT
#define LED1                    PA13  // Green, B/E

#define BEEPER                  PB9
#define BEEPER_INVERTED
#define BEEPER_PWM_FREQUENCY    2500

// *************** SPI1 IMU & OSD *******************
#define USE_SPI
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7

// ICM42688P
#define USE_IMU_ICM42605
#define IMU_ICM42605_ALIGN      CW180_DEG_FLIP
#define ICM42605_SPI_BUS        BUS_SPI1
#define ICM42605_CS_PIN         PC4

#define USE_MAX7456
#define MAX7456_SPI_BUS         BUS_SPI1
#define MAX7456_CS_PIN          PB2

// *************** SPI2 Blackbox NAND flash *********
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB10
#define SPI2_MISO_PIN           PC2
#define SPI2_MOSI_PIN           PC3

#define USE_FLASHFS
#define USE_FLASH_W25N01G
#define W25N01G_SPI_BUS         BUS_SPI2
#define W25N01G_CS_PIN          PC15

#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT

// *************** I2C3 Baro/Mag ********************
#define USE_I2C
#define USE_I2C_DEVICE_3
#define I2C3_SCL                PA8
#define I2C3_SDA                PC9

#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C3
#define USE_BARO_SPL06
#define USE_BARO_BMP280
#define USE_BARO_MS5611
#define USE_BARO_DPS310

#define USE_MAG
#define MAG_I2C_BUS             BUS_I2C3
#define USE_MAG_ALL

#define TEMPERATURE_I2C_BUS     BUS_I2C3
#define PITOT_I2C_BUS           BUS_I2C3

#define USE_RANGEFINDER
#define RANGEFINDER_I2C_BUS     BUS_I2C3

// *************** UART *****************************
#define USE_VCP

#define USE_UART1
#define UART1_TX_PIN            PB14
#define UART1_RX_PIN            PB15

#define USE_UART2
#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

#define USE_UART3
#define UART3_TX_PIN            PC10
#define UART3_RX_PIN            PC11

#define USE_UART4
#define UART4_TX_PIN            PA0
#define UART4_RX_PIN            PA1

#define USE_UART5
#define UART5_TX_PIN            PC12
#define UART5_RX_PIN            PD2

#define USE_UART6
#define UART6_TX_PIN            PC6
#define UART6_RX_PIN            PC7

#define SERIAL_PORT_COUNT       7

#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define SERIALRX_UART           SERIAL_PORT_USART2

// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE                ADC1

#define ADC_CHANNEL_1_PIN           PC0  // VBAT
#define ADC_CHANNEL_2_PIN           PC1  // CURR
#define ADC_CHANNEL_3_PIN           PA4  // VB2
#define ADC_CHANNEL_4_PIN           PC5  // CU2

#define VBAT_ADC_CHANNEL            ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL   ADC_CHN_2

#define VBAT_SCALE_DEFAULT          2100
#define CURRENT_METER_SCALE         250

// *************** PINIO ***************************
#define USE_PINIO
#define USE_PINIOBOX
#define PINIO1_PIN                  PC13  // 9V VTX/Cam switch, LOW (default) = 9V on

// *************** LEDSTRIP ************************
// No dedicated LED pad, S11 can be assigned to LED with timer_output_mode
#define USE_LED_STRIP
#define WS2811_PIN                  PB8

#define DEFAULT_FEATURES            (FEATURE_OSD | FEATURE_TELEMETRY | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TX_PROF_SEL | FEATURE_BLACKBOX)

#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD BIT(2)

#define MAX_PWM_OUTPUT_PORTS        11
#define USE_DSHOT
#define USE_ESC_SENSOR
