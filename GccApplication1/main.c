/*
 * GccApplication1.c
 *
 * Created: 29-09-2025 05:23:00
 * Author : conta
 * 
 * CAN Communication Example for SAM4E8C at 16MHz
 * This example demonstrates basic CAN communication using CAN0
 */ 

#include "sam.h"
#include "can.h"
#include "board.h"
#include "can_app.h"
#include "can_loopback_test.h"

// Global variables for CAN communication
volatile uint32_t g_ul_can_rx_status = 0;
can_mb_conf_t g_can_tx_mailbox;
can_mb_conf_t g_can_rx_mailbox;

// CAN message data
uint8_t can_tx_data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uint8_t can_rx_data[8];

// CAN Loopback Test Variables
volatile uint8_t g_can_loopback_test_active = 0;
volatile uint8_t g_can_loopback_test_complete = 0;
volatile uint32_t g_can_loopback_test_counter = 0;
can_message_t g_can_loopback_tx_msg;
can_message_t g_can_loopback_rx_msg;

/**
 * \brief CAN0 interrupt handler
 */
void CAN0_Handler(void)
{
    uint32_t ul_status;
    
    // Get CAN0 status
    ul_status = can_get_status(CAN0);
    
    // Check if mailbox 1 received a message
    if (ul_status & CAN_SR_MB1) {
        // Read the received message
        g_can_rx_mailbox.ul_mb_idx = 1;
        g_can_rx_mailbox.ul_status = can_mailbox_get_status(CAN0, 1);
        can_mailbox_read(CAN0, &g_can_rx_mailbox);
        
        // Copy received data
        can_rx_data[0] = (uint8_t)(g_can_rx_mailbox.ul_datal & 0xFF);
        can_rx_data[1] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 8) & 0xFF);
        can_rx_data[2] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 16) & 0xFF);
        can_rx_data[3] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 24) & 0xFF);
        can_rx_data[4] = (uint8_t)(g_can_rx_mailbox.ul_datah & 0xFF);
        can_rx_data[5] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 8) & 0xFF);
        can_rx_data[6] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 16) & 0xFF);
        can_rx_data[7] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 24) & 0xFF);
        
        g_ul_can_rx_status = 1;
    }
}

/**
 * \brief Initialize CAN0 for communication
 */
void can_init_application(void)
{
    // Enable CAN0 peripheral clock
    pmc_enable_periph_clk(ID_CAN0);
    
    // Initialize CAN0 with 500kbps baud rate (suitable for 16MHz)
    // For 16MHz: BRP=1, SJW=1, TSEG1=13, TSEG2=2 gives 500kbps
    can_init(CAN0, 16000000, CAN_BPS_500K);
    
    // Reset all mailboxes
    can_reset_all_mailbox(CAN0);
    
    // Configure mailbox 0 for transmission
    g_can_tx_mailbox.ul_mb_idx = 0;
    g_can_tx_mailbox.uc_obj_type = CAN_MB_TX_MODE;
    g_can_tx_mailbox.uc_tx_prio = 15;
    g_can_tx_mailbox.uc_id_ver = 0; // Standard frame
    g_can_tx_mailbox.ul_id = 0x123; // CAN ID
    g_can_tx_mailbox.ul_id_msk = 0;
    can_mailbox_init(CAN0, &g_can_tx_mailbox);
    
    // Configure mailbox 1 for reception
    g_can_rx_mailbox.ul_mb_idx = 1;
    g_can_rx_mailbox.uc_obj_type = CAN_MB_RX_MODE;
    g_can_rx_mailbox.ul_id_msk = CAN_MAM_MIDvA_Msk | CAN_MAM_MIDvB_Msk;
    g_can_rx_mailbox.ul_id = CAN_MID_MIDvA(0x123); // Accept messages with ID 0x123
    can_mailbox_init(CAN0, &g_can_rx_mailbox);
    
    // Enable CAN0 mailbox 1 interrupt for reception
    can_enable_interrupt(CAN0, CAN_IER_MB1);
    
    // Enable CAN0 interrupt in NVIC
    NVIC_EnableIRQ(CAN0_IRQn);
}

/**
 * \brief Send CAN message
 */
void can_send_message(uint32_t id, uint8_t *data, uint8_t length)
{
    // Prepare transmission mailbox
    g_can_tx_mailbox.ul_id = id;
    g_can_tx_mailbox.uc_length = length;
    
    // Copy data to mailbox
    g_can_tx_mailbox.ul_datal = (uint32_t)data[0] | 
                               ((uint32_t)data[1] << 8) | 
                               ((uint32_t)data[2] << 16) | 
                               ((uint32_t)data[3] << 24);
    g_can_tx_mailbox.ul_datah = (uint32_t)data[4] | 
                               ((uint32_t)data[5] << 8) | 
                               ((uint32_t)data[6] << 16) | 
                               ((uint32_t)data[7] << 24);
    
    // Write to mailbox
    can_mailbox_write(CAN0, &g_can_tx_mailbox);
    
    // Send transfer command
    can_global_send_transfer_cmd(CAN0, CAN_TCR_MB0);
}

/**
 * \brief Check if CAN message was received
 */
uint8_t can_message_received(void)
{
    return g_ul_can_rx_status;
}

/**
 * \brief Clear CAN receive flag
 */
void can_clear_rx_flag(void)
{
    g_ul_can_rx_status = 0;
}

/**
 * \brief Get received CAN message
 */
void can_get_received_message(can_message_t *msg)
{
    if (msg != NULL) {
        msg->id = g_can_rx_mailbox.ul_id;
        msg->length = g_can_rx_mailbox.uc_length;
        
        // Copy received data
        msg->data[0] = (uint8_t)(g_can_rx_mailbox.ul_datal & 0xFF);
        msg->data[1] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 8) & 0xFF);
        msg->data[2] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 16) & 0xFF);
        msg->data[3] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 24) & 0xFF);
        msg->data[4] = (uint8_t)(g_can_rx_mailbox.ul_datah & 0xFF);
        msg->data[5] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 8) & 0xFF);
        msg->data[6] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 16) & 0xFF);
        msg->data[7] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 24) & 0xFF);
    }
}

/**
 * \brief Initialize CAN for loopback testing
 * 
 * This function sets up the CAN controller for loopback testing by:
 * 1. Configuring one mailbox for transmission
 * 2. Configuring another mailbox for reception
 * 3. Setting up the same CAN ID for both TX and RX
 */
void can_init_loopback_test(void)
{
    // Enable CAN0 peripheral clock
    pmc_enable_periph_clk(ID_CAN0);
    
    // Initialize CAN0 with 500kbps baud rate
    can_init(CAN0, 16000000, CAN_BPS_500K);
    
    // Reset all mailboxes
    can_reset_all_mailbox(CAN0);
    
    // Configure mailbox 0 for transmission (loopback test)
    g_can_tx_mailbox.ul_mb_idx = 0;
    g_can_tx_mailbox.uc_obj_type = CAN_MB_TX_MODE;
    g_can_tx_mailbox.uc_tx_prio = 15;
    g_can_tx_mailbox.uc_id_ver = 0; // Standard frame
    g_can_tx_mailbox.ul_id = 0x123; // Test CAN ID
    g_can_tx_mailbox.ul_id_msk = 0;
    can_mailbox_init(CAN0, &g_can_tx_mailbox);
    
    // Configure mailbox 1 for reception (loopback test)
    g_can_rx_mailbox.ul_mb_idx = 1;
    g_can_rx_mailbox.uc_obj_type = CAN_MB_RX_MODE;
    g_can_rx_mailbox.ul_id_msk = CAN_MAM_MIDvA_Msk | CAN_MAM_MIDvB_Msk;
    g_can_rx_mailbox.ul_id = CAN_MID_MIDvA(0x123); // Accept messages with ID 0x123
    can_mailbox_init(CAN0, &g_can_rx_mailbox);
    
    // Enable CAN0 mailbox 1 interrupt for reception
    can_enable_interrupt(CAN0, CAN_IER_MB1);
    
    // Enable CAN0 interrupt in NVIC
    NVIC_EnableIRQ(CAN0_IRQn);
    
    // Initialize loopback test variables
    g_can_loopback_test_active = 0;
    g_can_loopback_test_complete = 0;
    g_can_loopback_test_counter = 0;
}

/**
 * \brief Send a message for loopback testing
 * 
 * @param id CAN message ID
 * @param data Pointer to data array
 * @param length Data length (1-8 bytes)
 * @return 1 if message sent successfully, 0 if failed
 */
uint8_t can_loopback_test_send(uint32_t id, uint8_t *data, uint8_t length)
{
    if (length > 8) return 0;
    
    // Store the transmitted message for verification
    g_can_loopback_tx_msg.id = id;
    g_can_loopback_tx_msg.length = length;
    for (uint8_t i = 0; i < length; i++) {
        g_can_loopback_tx_msg.data[i] = data[i];
    }
    
    // Prepare transmission mailbox
    g_can_tx_mailbox.ul_id = id;
    g_can_tx_mailbox.uc_length = length;
    
    // Copy data to mailbox
    g_can_tx_mailbox.ul_datal = (uint32_t)data[0] | 
                               ((uint32_t)data[1] << 8) | 
                               ((uint32_t)data[2] << 16) | 
                               ((uint32_t)data[3] << 24);
    g_can_tx_mailbox.ul_datah = (uint32_t)data[4] | 
                               ((uint32_t)data[5] << 8) | 
                               ((uint32_t)data[6] << 16) | 
                               ((uint32_t)data[7] << 24);
    
    // Write to mailbox
    can_mailbox_write(CAN0, &g_can_tx_mailbox);
    
    // Send transfer command
    can_global_send_transfer_cmd(CAN0, CAN_TCR_MB0);
    
    // Set loopback test as active
    g_can_loopback_test_active = 1;
    g_can_loopback_test_complete = 0;
    
    return 1;
}

/**
 * \brief Check for received message in loopback test
 * 
 * @param msg Pointer to message structure to store received data
 * @return 1 if message received, 0 if no message
 */
uint8_t can_loopback_test_receive(can_message_t *msg)
{
    if (g_ul_can_rx_status && g_can_loopback_test_active) {
        // Copy received message
        if (msg != NULL) {
            msg->id = g_can_rx_mailbox.ul_id;
            msg->length = g_can_rx_mailbox.uc_length;
            
            // Copy received data
            msg->data[0] = (uint8_t)(g_can_rx_mailbox.ul_datal & 0xFF);
            msg->data[1] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 8) & 0xFF);
            msg->data[2] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 16) & 0xFF);
            msg->data[3] = (uint8_t)((g_can_rx_mailbox.ul_datal >> 24) & 0xFF);
            msg->data[4] = (uint8_t)(g_can_rx_mailbox.ul_datah & 0xFF);
            msg->data[5] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 8) & 0xFF);
            msg->data[6] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 16) & 0xFF);
            msg->data[7] = (uint8_t)((g_can_rx_mailbox.ul_datah >> 24) & 0xFF);
        }
        
        // Store received message for verification
        g_can_loopback_rx_msg.id = g_can_rx_mailbox.ul_id;
        g_can_loopback_rx_msg.length = g_can_rx_mailbox.uc_length;
        for (uint8_t i = 0; i < g_can_rx_mailbox.uc_length; i++) {
            g_can_loopback_rx_msg.data[i] = (uint8_t)((g_can_rx_mailbox.ul_datal >> (i * 8)) & 0xFF);
            if (i >= 4) {
                g_can_loopback_rx_msg.data[i] = (uint8_t)((g_can_rx_mailbox.ul_datah >> ((i-4) * 8)) & 0xFF);
            }
        }
        
        // Clear receive flag
        g_ul_can_rx_status = 0;
        g_can_loopback_test_complete = 1;
        
        return 1;
    }
    
    return 0;
}

/**
 * \brief Complete the loopback test
 */
void can_loopback_test_complete(void)
{
    g_can_loopback_test_active = 0;
    g_can_loopback_test_complete = 0;
}

/**
 * \brief Verify loopback test data integrity
 * 
 * @param tx_data Pointer to transmitted data
 * @param rx_data Pointer to received data
 * @param length Data length to compare
 * @return 1 if data matches, 0 if mismatch
 */
uint8_t can_loopback_test_verify(uint8_t *tx_data, uint8_t *rx_data, uint8_t length)
{
    if (tx_data == NULL || rx_data == NULL || length > 8) {
        return 0;
    }
    
    for (uint8_t i = 0; i < length; i++) {
        if (tx_data[i] != rx_data[i]) {
            return 0;
        }
    }
    
    return 1;
}

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
    
    /* Initialize CAN for loopback testing */
    can_init_loopback_test();
    
    /* Main application loop with CAN loopback test */
    uint32_t counter = 0;
    uint32_t test_counter = 0;
    uint8_t test_data[8];
    can_message_t received_msg;
    uint8_t test_passed = 0;
    uint8_t test_failed = 0;
    
    while (1) 
    {
        // Perform CAN loopback test every 5000 iterations
        if (counter % 5000 == 0) {
            // Prepare test data
            test_data[0] = (uint8_t)(test_counter & 0xFF);
            test_data[1] = (uint8_t)((test_counter >> 8) & 0xFF);
            test_data[2] = (uint8_t)((test_counter >> 16) & 0xFF);
            test_data[3] = (uint8_t)((test_counter >> 24) & 0xFF);
            test_data[4] = 0xAA;
            test_data[5] = 0x55;
            test_data[6] = 0x12;
            test_data[7] = 0x34;
            
            // Send test message
            if (can_loopback_test_send(0x123, test_data, 8)) {
                // Wait for reception (with timeout)
                uint32_t timeout = 0;
                while (timeout < 100000 && !g_can_loopback_test_complete) {
                    timeout++;
                    // Check for received message
                    if (can_loopback_test_receive(&received_msg)) {
                        // Verify received data matches transmitted data
                        if (can_loopback_test_verify(test_data, received_msg.data, 8) &&
                            received_msg.id == 0x123 && received_msg.length == 8) {
                            test_passed++;
                        } else {
                            test_failed++;
                        }
                        break;
                    }
                }
                
                // Complete the test
                can_loopback_test_complete();
                
                // Increment test counter
                test_counter++;
            }
        }
        
        // Regular CAN communication (every 1000 iterations)
        if (counter % 1000 == 0) {
            // Update data with counter value
            can_tx_data[0] = (uint8_t)(counter & 0xFF);
            can_tx_data[1] = (uint8_t)((counter >> 8) & 0xFF);
            can_tx_data[2] = (uint8_t)((counter >> 16) & 0xFF);
            can_tx_data[3] = (uint8_t)((counter >> 24) & 0xFF);
            
            // Send CAN message
            can_send_message(0x123, can_tx_data, 8);
        }
        
        // Check if message was received
        if (can_message_received()) {
            // Process received message here
            // can_rx_data[] contains the received data
            
            // Clear the receive flag
            can_clear_rx_flag();
        }
        
        counter++;
        
        // Simple delay
        for (volatile uint32_t i = 0; i < 1000; i++);
    }
}
