/**
 * \file
 *
 * \brief Power Management Controller (PMC) driver for SAM4E.
 *
 * Copyright (c) 2013-2018 Microchip Technology Inc. and its subsidiaries.
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

#ifndef PMC_H
#define PMC_H

#include "compiler.h"
#include "status_codes.h"
#include "interrupt_sam_nvic.h"

// Include the component header for register definitions
#include "component/pmc.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief PMC peripheral IDs
 */
#define ID_PMC   0

/**
 * \brief PMC interrupt sources
 */
#define PMC_INTERRUPT_SOURCE_MOSCXTS    PMC_IER_MOSCXTS
#define PMC_INTERRUPT_SOURCE_LOCKA      PMC_IER_LOCKA
#define PMC_INTERRUPT_SOURCE_MCKRDY     PMC_IER_MCKRDY
#define PMC_INTERRUPT_SOURCE_PCKRDY0    PMC_IER_PCKRDY0
#define PMC_INTERRUPT_SOURCE_PCKRDY1    PMC_IER_PCKRDY1
#define PMC_INTERRUPT_SOURCE_PCKRDY2    PMC_IER_PCKRDY2
#define PMC_INTERRUPT_SOURCE_MOSCSELS   PMC_IER_MOSCSELS
#define PMC_INTERRUPT_SOURCE_MOSCRCS    PMC_IER_MOSCRCS
#define PMC_INTERRUPT_SOURCE_CFDEV      PMC_IER_CFDEV

/**
 * \brief PMC status register bit masks
 */
#define PMC_STATUS_MOSCXTS    PMC_SR_MOSCXTS
#define PMC_STATUS_LOCKA      PMC_SR_LOCKA
#define PMC_STATUS_MCKRDY     PMC_SR_MCKRDY
#define PMC_STATUS_OSCSELS    PMC_SR_OSCSELS
#define PMC_STATUS_PCKRDY0    PMC_SR_PCKRDY0
#define PMC_STATUS_PCKRDY1    PMC_SR_PCKRDY1
#define PMC_STATUS_PCKRDY2    PMC_SR_PCKRDY2
#define PMC_STATUS_MOSCSELS   PMC_SR_MOSCSELS
#define PMC_STATUS_MOSCRCS    PMC_SR_MOSCRCS
#define PMC_STATUS_CFDEV      PMC_SR_CFDEV
#define PMC_STATUS_CFDS       PMC_SR_CFDS
#define PMC_STATUS_FOS        PMC_SR_FOS

/**
 * \brief PMC peripheral clock enable/disable functions
 */
void pmc_enable_periph_clk(uint32_t ul_id);
void pmc_disable_periph_clk(uint32_t ul_id);
uint32_t pmc_is_periph_clk_enabled(uint32_t ul_id);

/**
 * \brief PMC system clock functions
 */
void pmc_enable_system_clock(uint32_t ul_id);
void pmc_disable_system_clock(uint32_t ul_id);
uint32_t pmc_is_system_clock_enabled(uint32_t ul_id);

/**
 * \brief PMC interrupt functions
 */
void pmc_enable_interrupt(uint32_t ul_sources);
void pmc_disable_interrupt(uint32_t ul_sources);
uint32_t pmc_get_interrupt_mask(void);
uint32_t pmc_get_status(void);

/**
 * \brief PMC programmable clock functions
 */
void pmc_enable_pck(uint32_t ul_id);
void pmc_disable_pck(uint32_t ul_id);
void pmc_switch_pck_to_sclk(uint32_t ul_id, uint32_t ul_pres);
void pmc_switch_pck_to_mainck(uint32_t ul_id, uint32_t ul_pres);
void pmc_switch_pck_to_pllack(uint32_t ul_id, uint32_t ul_pres);
void pmc_switch_pck_to_mck(uint32_t ul_id, uint32_t ul_pres);
uint32_t pmc_is_pck_enabled(uint32_t ul_id);

/**
 * \brief PMC master clock functions
 */
void pmc_switch_mck_to_sclk(uint32_t ul_pres);
void pmc_switch_mck_to_mainck(uint32_t ul_pres);
void pmc_switch_mck_to_pllack(uint32_t ul_pres);
void pmc_switch_mck_to_plladiv2(uint32_t ul_pres);

/**
 * \brief PMC oscillator functions
 */
void pmc_switch_mainck_to_fastrc(void);
void pmc_switch_mainck_to_xtal(void);
void pmc_osc_enable_fastrc(uint32_t ul_rc);
void pmc_osc_disable_fastrc(void);
void pmc_osc_enable_xtal(uint32_t ul_xtal_startup_time);
void pmc_osc_disable_xtal(void);
uint32_t pmc_osc_is_ready_xtal(void);
uint32_t pmc_osc_is_ready_fastrc(void);

/**
 * \brief PMC PLL functions
 */
void pmc_enable_pllack(uint32_t mul, uint32_t div, uint32_t count);
void pmc_disable_pllack(void);
uint32_t pmc_is_locked_pllack(void);

/**
 * \brief PMC USB clock functions
 */
void pmc_switch_udpck_to_pllack(uint32_t ul_usbdiv);
void pmc_switch_udpck_to_plladiv2(uint32_t ul_usbdiv);
void pmc_switch_udpck_to_mainck(uint32_t ul_usbdiv);

/**
 * \brief PMC low power mode functions
 */
void pmc_enable_sleepmode(uint32_t ul_ucr);
void pmc_enable_waitmode(void);
void pmc_enable_backupmode(void);

/**
 * \brief PMC fast startup mode functions
 */
void pmc_set_fast_startup_input(uint32_t ul_inputs, uint32_t ul_polarity);
void pmc_clr_fast_startup_input(uint32_t ul_inputs);
void pmc_set_fast_startup_mode(uint32_t ul_mode);

/**
 * \brief PMC write protection functions
 */
void pmc_set_writeprotect(uint32_t ul_enable);
uint32_t pmc_get_writeprotect_status(void);

#ifdef __cplusplus
}
#endif

#endif /* PMC_H */