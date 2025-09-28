/**
 * \file
 *
 * \brief MPLAB Harmony Configuration for CAN Project
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
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
 */

#ifndef HARMONY_CONFIG_H
#define HARMONY_CONFIG_H

// Harmony Framework Configuration
#define DRV_CAN_INSTANCES_NUMBER     1
#define DRV_CAN_CLIENTS_NUMBER       1
#define DRV_CAN_QUEUE_SIZE           10
#define DRV_CAN_QUEUE_SIZE_TX        5
#define DRV_CAN_QUEUE_SIZE_RX        5

// System Configuration
#define SYS_CLK_FREQ                 48000000UL
#define SYS_CLK_BUS_PERIPHERAL_1     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_2     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_3     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_4     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_5     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_6     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_7     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_8     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_9     24000000UL
#define SYS_CLK_BUS_PERIPHERAL_10    24000000UL

// CAN Configuration
#define CAN_BAUDRATE_125KBPS         125000
#define CAN_BAUDRATE_250KBPS         250000
#define CAN_BAUDRATE_500KBPS         500000
#define CAN_BAUDRATE_1MBPS           1000000

// CAN Pin Configuration
#define CAN_TX_PIN                   PIN_PA24
#define CAN_RX_PIN                   PIN_PA25

// LED Configuration
#define LED_PIN                      PIN_PB27

// Button Configuration
#define BUTTON_PIN                   PIN_PA02

// Interrupt Configuration
#define SYS_INT_PRIORITY_LEVEL_0     0
#define SYS_INT_PRIORITY_LEVEL_1     1
#define SYS_INT_PRIORITY_LEVEL_2     2
#define SYS_INT_PRIORITY_LEVEL_3     3
#define SYS_INT_PRIORITY_LEVEL_4     4
#define SYS_INT_PRIORITY_LEVEL_5     5
#define SYS_INT_PRIORITY_LEVEL_6     6
#define SYS_INT_PRIORITY_LEVEL_7     7

// Task Configuration
#define SYS_TASK_MAX_NUM             5
#define SYS_TASK_STACK_SIZE          1024

// Timer Configuration
#define SYS_TMR_CLOCK_FREQ           48000000UL
#define SYS_TMR_TICK_FREQ            1000UL

#endif // HARMONY_CONFIG_H