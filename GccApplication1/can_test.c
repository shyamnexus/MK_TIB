/**
 * \file can_test.c
 * 
 * \brief Simple CAN Test Application
 * 
 * This is a minimal CAN test application for SAM4E8C at 16MHz.
 * It demonstrates basic CAN initialization and communication.
 */

#include "sam.h"
#include "can.h"

// Simple CAN test variables
volatile uint32_t can_test_rx_flag = 0;
can_mb_conf_t test_tx_mailbox;
can_mb_conf_t test_rx_mailbox;

/**
 * \brief Simple CAN initialization for testing
 */
void can_test_init(void)
{
    // Enable CAN0 peripheral clock
    pmc_enable_periph_clk(ID_CAN0);
    
    // Initialize CAN0 with 500kbps
    can_init(CAN0, 16000000, CAN_BPS_500K);
    
    // Reset all mailboxes
    can_reset_all_mailbox(CAN0);
    
    // Configure mailbox 0 for transmission
    test_tx_mailbox.ul_mb_idx = 0;
    test_tx_mailbox.uc_obj_type = CAN_MB_TX_MODE;
    test_tx_mailbox.uc_tx_prio = 15;
    test_tx_mailbox.uc_id_ver = 0; // Standard frame
    test_tx_mailbox.ul_id = 0x100; // Test CAN ID
    test_tx_mailbox.ul_id_msk = 0;
    can_mailbox_init(CAN0, &test_tx_mailbox);
    
    // Configure mailbox 1 for reception
    test_rx_mailbox.ul_mb_idx = 1;
    test_rx_mailbox.uc_obj_type = CAN_MB_RX_MODE;
    test_rx_mailbox.ul_id_msk = CAN_MAM_MIDvA_Msk | CAN_MAM_MIDvB_Msk;
    test_rx_mailbox.ul_id = CAN_MID_MIDvA(0x100); // Accept ID 0x100
    can_mailbox_init(CAN0, &test_rx_mailbox);
}

/**
 * \brief Send a simple test message
 */
void can_test_send(void)
{
    // Prepare test data
    test_tx_mailbox.ul_datal = 0x12345678;
    test_tx_mailbox.ul_datah = 0x87654321;
    test_tx_mailbox.uc_length = 8;
    
    // Write to mailbox and send
    can_mailbox_write(CAN0, &test_tx_mailbox);
    can_global_send_transfer_cmd(CAN0, CAN_TCR_MB0);
}

/**
 * \brief Check if message was received
 */
uint8_t can_test_received(void)
{
    uint32_t status = can_mailbox_get_status(CAN0, 1);
    return (status & CAN_MSR_MRDY) ? 1 : 0;
}

/**
 * \brief Read received message
 */
void can_test_read(void)
{
    if (can_test_received()) {
        can_mailbox_read(CAN0, &test_rx_mailbox);
        can_test_rx_flag = 1;
    }
}

/**
 * \brief Simple CAN test main function
 */
int can_test_main(void)
{
    // Initialize system
    SystemInit();
    
    // Initialize CAN
    can_test_init();
    
    // Test variables
    uint32_t counter = 0;
    
    while (1) {
        // Send test message every 10000 iterations
        if (counter % 10000 == 0) {
            can_test_send();
        }
        
        // Check for received messages
        can_test_read();
        
        // Process received message if available
        if (can_test_rx_flag) {
            // Message received - process it here
            can_test_rx_flag = 0;
        }
        
        counter++;
        
        // Simple delay
        for (volatile uint32_t i = 0; i < 1000; i++);
    }
    
    return 0;
}