/**
 * \file can_app.h
 * 
 * \brief CAN Application Header File
 * 
 * This file contains function declarations and definitions for CAN communication
 * on SAM4E8C microcontroller running at 16MHz.
 */

#ifndef CAN_APP_H_INCLUDED
#define CAN_APP_H_INCLUDED

#include "sam.h"
#include "can.h"

// CAN message structure
typedef struct {
    uint32_t id;
    uint8_t data[8];
    uint8_t length;
} can_message_t;

// Function declarations
void can_init_application(void);
void can_send_message(uint32_t id, uint8_t *data, uint8_t length);
uint8_t can_message_received(void);
void can_clear_rx_flag(void);
void can_get_received_message(can_message_t *msg);

// Global variables (extern declarations)
extern volatile uint32_t g_ul_can_rx_status;
extern can_mb_conf_t g_can_tx_mailbox;
extern can_mb_conf_t g_can_rx_mailbox;
extern uint8_t can_tx_data[8];
extern uint8_t can_rx_data[8];

#endif /* CAN_APP_H_INCLUDED */