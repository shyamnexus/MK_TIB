/**
 * \file
 *
 * \brief Clock configuration for 16MHz crystal
 *
 * Copyright (c) 2014-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGE.
 *
 * \asf_license_stop
 *
 */

#ifndef CONF_CLOCK_H
#define CONF_CLOCK_H

// External crystal frequency (16MHz)
#define BOARD_FREQ_SLCK_XTAL      (32768UL)
#define BOARD_FREQ_MAINCK_XTAL   (16000000UL)
#define BOARD_FREQ_MAINCK_XTAL_EXT (16000000UL)
#define BOARD_FREQ_MAINCK_XTAL_OSC (16000000UL)

// PLL configuration for 16MHz crystal
#define BOARD_OSC_STARTUP_US     15625

// System clock configuration
#define CONFIG_SYSCLK_SOURCE      SYSCLK_SRC_PLL0
#define CONFIG_SYSCLK_PRES        SYSCLK_PRES_1
#define CONFIG_PLL0_SOURCE        PLL_SRC_MAINCK_XTAL
#define CONFIG_PLL0_MUL           6
#define CONFIG_PLL0_DIV           1

// Flash wait states for 48MHz operation
#define CONFIG_SYSCLK_FLASH_WAIT_STATES 1

// USB clock configuration (if needed)
#define CONFIG_USBCLK_SOURCE      USBCLK_SRC_PLL0
#define CONFIG_USBCLK_DIV         1

// Peripheral clock configuration
#define CONFIG_PBA_HZ             (CONFIG_SYSCLK_HZ / 2)
#define CONFIG_PBB_HZ             (CONFIG_SYSCLK_HZ / 2)
#define CONFIG_PBC_HZ             (CONFIG_SYSCLK_HZ / 2)
#define CONFIG_PBD_HZ             (CONFIG_SYSCLK_HZ / 2)

// CAN clock configuration
#define CONFIG_CAN_CLOCK_SOURCE   CAN_CLOCK_MCK

#endif // CONF_CLOCK_H