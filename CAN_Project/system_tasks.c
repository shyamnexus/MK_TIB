/**
 * \file
 *
 * \brief System Tasks
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 */

#include "system_definitions.h"
#include "system_config.h"

/**
 * \brief Run system tasks
 */
void SYS_Tasks(void)
{
    // Update system state
    if (sysData.state == SYSTEM_STATE_INIT) {
        sysData.state = SYSTEM_STATE_RUNNING;
    }
    
    // Run driver tasks
    DRV_CAN_Tasks();
    DRV_GPIO_Tasks();
    
    // Run system service tasks
    SYS_TMR_Tasks();
    SYS_TASKS_Tasks();
}