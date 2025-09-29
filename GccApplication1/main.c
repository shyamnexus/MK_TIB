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

// Global variables for CAN communication
volatile uint32_t g_ul_can_rx_status = 0;
can_mb_conf_t g_can_tx_mailbox;
can_mb_conf_t g_can_rx_mailbox;

// CAN message data
uint8_t can_tx_data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uint8_t can_rx_data[8];

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

int main(void)
{
    /* Initialize the SAM system */
    SystemInit();
    
    /* Initialize CAN communication */
    can_init_application();
    
    /* Main application loop */
    uint32_t counter = 0;
    
    while (1) 
    {
        // Send CAN message every 1000 iterations
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
