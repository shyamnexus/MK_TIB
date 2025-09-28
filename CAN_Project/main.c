/**
 * \file
 *
 * \brief CAN Example for MPLAB Harmony 3.0
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

#include "system_definitions.h"
#include "system_config.h"
#include "system_init.h"
#include "system_tasks.h"

// Global system data
SYSTEM_DATA sysData = {0};

/**
 * \brief CAN RX callback function
 */
void CAN_RX_Callback(DRV_CAN_BUFFER_EVENT event, uintptr_t context)
{
    if (event == DRV_CAN_BUFFER_EVENT_COMPLETE) {
        sysData.canRxFlag = true;
    }
}

/**
 * \brief CAN TX callback function
 */
void CAN_TX_Callback(DRV_CAN_BUFFER_EVENT event, uintptr_t context)
{
    if (event == DRV_CAN_BUFFER_EVENT_COMPLETE) {
        sysData.canTxFlag = true;
    }
}

/**
 * \brief Send CAN message
 */
static void can_send_message(uint32_t id, uint8_t *data, uint8_t length)
{
    DRV_CAN_BUFFER_OBJECT bufferObj;
    
    bufferObj.id = id;
    bufferObj.length = length;
    bufferObj.extended = false;
    
    for (uint8_t i = 0; i < length; i++) {
        bufferObj.data[i] = data[i];
    }
    
    sysData.canTxFlag = false;
    DRV_CAN_Write(sysData.canHandle, &bufferObj);
    
    // Wait for transmission complete
    while (!sysData.canTxFlag);
}

/**
 * \brief Receive CAN message
 */
static bool can_receive_message(CAN_MESSAGE *message)
{
    if (sysData.canRxFlag) {
        sysData.canRxFlag = false;
        *message = sysData.rxMessage;
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
    SYS_Initialize(NULL);
    
    // Initialize CAN driver
    sysData.canHandle = DRV_CAN_Open(DRV_CAN_INDEX_0, DRV_IO_INTENT_READWRITE);
    if (sysData.canHandle == DRV_HANDLE_INVALID) {
        // Handle error
        while(1);
    }
    
    // Set up CAN callbacks
    DRV_CAN_BufferEventHandlerSet(sysData.canHandle, CAN_RX_Callback, 0);
    DRV_CAN_BufferEventHandlerSet(sysData.canHandle, CAN_TX_Callback, 0);
    
    // Initialize message data
    uint8_t test_data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    
    // Main loop
    while (1) {
        // Send test message every 1 second
        SYS_TMR_DelayMS(1000);
        can_send_message(0x123, test_data, 8);
        
        // Check for received messages
        if (can_receive_message(&sysData.rxMessage)) {
            // Process received message
            // Add your message processing logic here
        }
        
        // Run system tasks
        SYS_Tasks();
    }
}