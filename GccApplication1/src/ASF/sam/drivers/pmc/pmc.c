/**
 * \file
 *
 * \brief Power Management Controller (PMC) driver for SAM.
 *
 * Copyright (c) 2011-2018 Microchip Technology Inc. and its subsidiaries.
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
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include "pmc.h"
#include "sam4e8c.h"

/**
 * \brief Enable the specified peripheral clock.
 *
 * \param ul_id Peripheral ID (ID_xxx).
 */
void pmc_enable_periph_clk(uint32_t ul_id)
{
    if (ul_id < 32) {
        PMC->PMC_PCER0 = 1 << ul_id;
    } else {
        PMC->PMC_PCER1 = 1 << (ul_id - 32);
    }
}

/**
 * \brief Disable the specified peripheral clock.
 *
 * \param ul_id Peripheral ID (ID_xxx).
 */
void pmc_disable_periph_clk(uint32_t ul_id)
{
    if (ul_id < 32) {
        PMC->PMC_PCDR0 = 1 << ul_id;
    } else {
        PMC->PMC_PCDR1 = 1 << (ul_id - 32);
    }
}

/**
 * \brief Check if the specified peripheral clock is enabled.
 *
 * \param ul_id Peripheral ID (ID_xxx).
 *
 * \return 1 if the peripheral clock is enabled, 0 otherwise.
 */
bool pmc_is_periph_clk_enabled(uint32_t ul_id)
{
    if (ul_id < 32) {
        return (PMC->PMC_PCSR0 & (1 << ul_id)) != 0;
    } else {
        return (PMC->PMC_PCSR1 & (1 << (ul_id - 32))) != 0;
    }
}