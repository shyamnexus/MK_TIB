/**
 * \file
 *
 * \brief CAN Example for ASF 3.52
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

#include <asf.h>
#include "conf_board.h"
#include "conf_clock.h"
#include "conf_can.h"

// CAN message structure
typedef struct {
	uint32_t id;
	uint8_t data[8];
	uint8_t length;
} can_message_t;

// Global variables
static can_message_t rx_message;
static can_message_t tx_message;
static volatile bool can_rx_flag = false;
static volatile bool can_tx_flag = false;

/**
 * \brief CAN RX interrupt handler
 */
static void can_rx_handler(void)
{
	can_rx_flag = true;
}

/**
 * \brief CAN TX interrupt handler
 */
static void can_tx_handler(void)
{
	can_tx_flag = true;
}

/**
 * \brief Initialize CAN module
 */
static void can_init(void)
{
	// Configure CAN pins
	gpio_configure_pin(CAN_TX_PIN, CAN_TX_FLAGS);
	gpio_configure_pin(CAN_RX_PIN, CAN_RX_FLAGS);
	
	// Initialize CAN controller
	can_init(CAN_BAUDRATE_500KBPS, CAN_MODE_NORMAL);
	
	// Enable CAN interrupts
	can_enable_interrupt(CAN_INTERRUPT_RX);
	can_enable_interrupt(CAN_INTERRUPT_TX);
	
	// Set interrupt handlers
	can_set_rx_handler(can_rx_handler);
	can_set_tx_handler(can_tx_handler);
}

/**
 * \brief Send CAN message
 */
static void can_send_message(uint32_t id, uint8_t *data, uint8_t length)
{
	tx_message.id = id;
	tx_message.length = length;
	
	for (uint8_t i = 0; i < length; i++) {
		tx_message.data[i] = data[i];
	}
	
	can_tx_flag = false;
	can_send(&tx_message);
	
	// Wait for transmission complete
	while (!can_tx_flag);
}

/**
 * \brief Receive CAN message
 */
static bool can_receive_message(can_message_t *message)
{
	if (can_rx_flag) {
		can_rx_flag = false;
		*message = rx_message;
		return true;
	}
	return false;
}

/**
 * \brief Main function
 */
int main(void)
{
	// Initialize system
	sysclk_init();
	board_init();
	
	// Initialize CAN
	can_init();
	
	// Enable global interrupts
	cpu_irq_enable();
	
	// Initialize message data
	uint8_t test_data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
	
	// Main loop
	while (1) {
		// Send test message every 1 second
		delay_ms(1000);
		can_send_message(0x123, test_data, 8);
		
		// Check for received messages
		if (can_receive_message(&rx_message)) {
			// Process received message
			// Add your message processing logic here
		}
	}
}