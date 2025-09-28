/**
 * \file
 *
 * \brief System Configuration Header
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 */

#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include "harmony_config.h"
#include "system_definitions.h"

// System Clock Configuration
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

#endif // SYSTEM_CONFIG_H