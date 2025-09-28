/**
 * \file
 *
 * \brief Board configuration for CAN project
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

#ifndef CONF_BOARD_H
#define CONF_BOARD_H

// CAN pin definitions
#define CAN_TX_PIN               PIN_PA24
#define CAN_RX_PIN               PIN_PA25

// CAN pin flags
#define CAN_TX_FLAGS             (PIO_PERIPH_A | PIO_DEFAULT)
#define CAN_RX_FLAGS             (PIO_PERIPH_A | PIO_DEFAULT)

// LED pin for status indication
#define LED_PIN                  PIN_PB27
#define LED_FLAGS                (PIO_OUTPUT_0 | PIO_DEFAULT)

// Button pin for testing
#define BUTTON_PIN               PIN_PA02
#define BUTTON_FLAGS             (PIO_INPUT | PIO_PULLUP | PIO_DEBOUNCE)

// Enable board features
#define CONF_BOARD_ENABLE_CAN
#define CONF_BOARD_ENABLE_LED
#define CONF_BOARD_ENABLE_BUTTON

#endif // CONF_BOARD_H