/**
 * \file
 *
 * \brief System Initialization
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 */

#include "system_definitions.h"
#include "system_config.h"

/**
 * \brief Initialize system
 */
void SYS_Initialize(void *data)
{
    // Initialize system clock
    SYS_CLK_Initialize(NULL);
    
    // Initialize system services
    SYS_TMR_Initialize();
    SYS_TASKS_Initialize();
    
    // Initialize drivers
    DRV_CAN_Initialize();
    DRV_GPIO_Initialize();
    
    // Configure system state
    sysData.state = SYSTEM_STATE_INIT;
}