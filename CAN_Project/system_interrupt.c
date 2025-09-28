/**
 * \file
 *
 * \brief System Interrupts
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 */

#include "system_definitions.h"
#include "system_config.h"

/**
 * \brief CAN interrupt handler
 */
void CAN_InterruptHandler(void)
{
    DRV_CAN_Tasks();
}

/**
 * \brief System interrupt handler
 */
void SYS_InterruptHandler(void)
{
    // Handle system interrupts
    SYS_TMR_Tasks();
}