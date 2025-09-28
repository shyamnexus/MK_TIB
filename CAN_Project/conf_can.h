/**
 * \file
 *
 * \brief CAN configuration for ASF 3.52
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

#ifndef CONF_CAN_H
#define CONF_CAN_H

// CAN baud rate configuration
#define CAN_BAUDRATE_125KBPS      125000
#define CAN_BAUDRATE_250KBPS      250000
#define CAN_BAUDRATE_500KBPS      500000
#define CAN_BAUDRATE_1MBPS        1000000

// CAN mode configuration
#define CAN_MODE_NORMAL           0
#define CAN_MODE_LOOPBACK         1
#define CAN_MODE_LISTENONLY       2

// CAN interrupt configuration
#define CAN_INTERRUPT_RX          0x01
#define CAN_INTERRUPT_TX          0x02
#define CAN_INTERRUPT_ERROR       0x04
#define CAN_INTERRUPT_WAKEUP      0x08

// CAN message ID configuration
#define CAN_STD_ID_MASK           0x7FF
#define CAN_EXT_ID_MASK           0x1FFFFFFF

// CAN message type
#define CAN_MSG_TYPE_DATA         0
#define CAN_MSG_TYPE_REMOTE       1

// CAN message format
#define CAN_MSG_FORMAT_STD        0
#define CAN_MSG_FORMAT_EXT        1

// CAN filter configuration
#define CAN_FILTER_MODE_MASK      0
#define CAN_FILTER_MODE_ID        1

// CAN acceptance filter configuration
#define CAN_ACCEPTANCE_FILTER_0   0
#define CAN_ACCEPTANCE_FILTER_1   1
#define CAN_ACCEPTANCE_FILTER_2   2
#define CAN_ACCEPTANCE_FILTER_3   3

// CAN mailbox configuration
#define CAN_MAILBOX_0             0
#define CAN_MAILBOX_1             1
#define CAN_MAILBOX_2             2
#define CAN_MAILBOX_3             3
#define CAN_MAILBOX_4             4
#define CAN_MAILBOX_5             5
#define CAN_MAILBOX_6             6
#define CAN_MAILBOX_7             7

// CAN status flags
#define CAN_STATUS_TX_COMPLETE    0x01
#define CAN_STATUS_RX_COMPLETE    0x02
#define CAN_STATUS_ERROR          0x04
#define CAN_STATUS_BUS_OFF        0x08
#define CAN_STATUS_WAKEUP         0x10

// CAN error flags
#define CAN_ERROR_BIT_ERROR       0x01
#define CAN_ERROR_FORM_ERROR      0x02
#define CAN_ERROR_STUFF_ERROR     0x04
#define CAN_ERROR_ACK_ERROR       0x08
#define CAN_ERROR_CRC_ERROR       0x10

// CAN clock configuration
#define CAN_CLOCK_MCK             0
#define CAN_CLOCK_PLL0            1
#define CAN_CLOCK_PLL1            2

// CAN prescaler configuration
#define CAN_PRESCALER_1           1
#define CAN_PRESCALER_2           2
#define CAN_PRESCALER_4           4
#define CAN_PRESCALER_8           8
#define CAN_PRESCALER_16          16
#define CAN_PRESCALER_32          32
#define CAN_PRESCALER_64          64

// CAN bit timing configuration
#define CAN_BIT_TIMING_SJW_1      0
#define CAN_BIT_TIMING_SJW_2      1
#define CAN_BIT_TIMING_SJW_3      2
#define CAN_BIT_TIMING_SJW_4      3

#define CAN_BIT_TIMING_BRP_1      1
#define CAN_BIT_TIMING_BRP_2      2
#define CAN_BIT_TIMING_BRP_4      4
#define CAN_BIT_TIMING_BRP_8      8
#define CAN_BIT_TIMING_BRP_16     16
#define CAN_BIT_TIMING_BRP_32     32
#define CAN_BIT_TIMING_BRP_64     64

// CAN segment configuration
#define CAN_SEGMENT_1_TQ          1
#define CAN_SEGMENT_2_TQ          2
#define CAN_SEGMENT_3_TQ          3
#define CAN_SEGMENT_4_TQ          4
#define CAN_SEGMENT_5_TQ          5
#define CAN_SEGMENT_6_TQ          6
#define CAN_SEGMENT_7_TQ          7
#define CAN_SEGMENT_8_TQ          8

// CAN sample point configuration
#define CAN_SAMPLE_POINT_75       75
#define CAN_SAMPLE_POINT_80       80
#define CAN_SAMPLE_POINT_85       85
#define CAN_SAMPLE_POINT_90       90

#endif // CONF_CAN_H