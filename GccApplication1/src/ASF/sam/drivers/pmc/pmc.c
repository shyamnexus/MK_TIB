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

#include "pmc.h"

/**
 * \brief Enable the specified peripheral clock.
 *
 * \param ul_id Peripheral ID (ID_PMC, ID_*).
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
 * \param ul_id Peripheral ID (ID_PMC, ID_*).
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
 * \param ul_id Peripheral ID (ID_PMC, ID_*).
 *
 * \return 1 if the peripheral clock is enabled; otherwise 0.
 */
uint32_t pmc_is_periph_clk_enabled(uint32_t ul_id)
{
    if (ul_id < 32) {
        return (PMC->PMC_PCSR0 & (1 << ul_id)) ? 1 : 0;
    } else {
        return (PMC->PMC_PCSR1 & (1 << (ul_id - 32))) ? 1 : 0;
    }
}

/**
 * \brief Enable the specified system clock.
 *
 * \param ul_id System clock ID.
 */
void pmc_enable_system_clock(uint32_t ul_id)
{
    PMC->PMC_SCER = ul_id;
}

/**
 * \brief Disable the specified system clock.
 *
 * \param ul_id System clock ID.
 */
void pmc_disable_system_clock(uint32_t ul_id)
{
    PMC->PMC_SCDR = ul_id;
}

/**
 * \brief Check if the specified system clock is enabled.
 *
 * \param ul_id System clock ID.
 *
 * \return 1 if the system clock is enabled; otherwise 0.
 */
uint32_t pmc_is_system_clock_enabled(uint32_t ul_id)
{
    return (PMC->PMC_SCSR & ul_id) ? 1 : 0;
}

/**
 * \brief Enable the specified PMC interrupt sources.
 *
 * \param ul_sources Bitwise OR of PMC_INTERRUPT_SOURCE_* values.
 */
void pmc_enable_interrupt(uint32_t ul_sources)
{
    PMC->PMC_IER = ul_sources;
}

/**
 * \brief Disable the specified PMC interrupt sources.
 *
 * \param ul_sources Bitwise OR of PMC_INTERRUPT_SOURCE_* values.
 */
void pmc_disable_interrupt(uint32_t ul_sources)
{
    PMC->PMC_IDR = ul_sources;
}

/**
 * \brief Get the PMC interrupt mask.
 *
 * \return PMC interrupt mask.
 */
uint32_t pmc_get_interrupt_mask(void)
{
    return PMC->PMC_IMR;
}

/**
 * \brief Get the PMC status.
 *
 * \return PMC status.
 */
uint32_t pmc_get_status(void)
{
    return PMC->PMC_SR;
}

/**
 * \brief Enable the specified programmable clock.
 *
 * \param ul_id Programmable clock ID (0, 1, 2).
 */
void pmc_enable_pck(uint32_t ul_id)
{
    PMC->PMC_SCER = PMC_SCER_PCK0 << ul_id;
}

/**
 * \brief Disable the specified programmable clock.
 *
 * \param ul_id Programmable clock ID (0, 1, 2).
 */
void pmc_disable_pck(uint32_t ul_id)
{
    PMC->PMC_SCDR = PMC_SCDR_PCK0 << ul_id;
}

/**
 * \brief Switch the specified programmable clock to slow clock.
 *
 * \param ul_id Programmable clock ID (0, 1, 2).
 * \param ul_pres Programmable clock prescaler.
 */
void pmc_switch_pck_to_sclk(uint32_t ul_id, uint32_t ul_pres)
{
    PMC->PMC_PCK[ul_id] = PMC_PCK_CSS_SLOW_CLK | PMC_PCK_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Switch the specified programmable clock to main clock.
 *
 * \param ul_id Programmable clock ID (0, 1, 2).
 * \param ul_pres Programmable clock prescaler.
 */
void pmc_switch_pck_to_mainck(uint32_t ul_id, uint32_t ul_pres)
{
    PMC->PMC_PCK[ul_id] = PMC_PCK_CSS_MAIN_CLK | PMC_PCK_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Switch the specified programmable clock to PLLA clock.
 *
 * \param ul_id Programmable clock ID (0, 1, 2).
 * \param ul_pres Programmable clock prescaler.
 */
void pmc_switch_pck_to_pllack(uint32_t ul_id, uint32_t ul_pres)
{
    PMC->PMC_PCK[ul_id] = PMC_PCK_CSS_PLLA_CLK | PMC_PCK_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Switch the specified programmable clock to master clock.
 *
 * \param ul_id Programmable clock ID (0, 1, 2).
 * \param ul_pres Programmable clock prescaler.
 */
void pmc_switch_pck_to_mck(uint32_t ul_id, uint32_t ul_pres)
{
    PMC->PMC_PCK[ul_id] = PMC_PCK_CSS_MCK | PMC_PCK_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Check if the specified programmable clock is enabled.
 *
 * \param ul_id Programmable clock ID (0, 1, 2).
 *
 * \return 1 if the programmable clock is enabled; otherwise 0.
 */
uint32_t pmc_is_pck_enabled(uint32_t ul_id)
{
    return (PMC->PMC_SCSR & (PMC_SCSR_PCK0 << ul_id)) ? 1 : 0;
}

/**
 * \brief Switch the master clock to slow clock.
 *
 * \param ul_pres Master clock prescaler.
 */
void pmc_switch_mck_to_sclk(uint32_t ul_pres)
{
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_SLOW_CLK;
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_PRES_Msk) | PMC_MCKR_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Switch the master clock to main clock.
 *
 * \param ul_pres Master clock prescaler.
 */
void pmc_switch_mck_to_mainck(uint32_t ul_pres)
{
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_MAIN_CLK;
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_PRES_Msk) | PMC_MCKR_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Switch the master clock to PLLA clock.
 *
 * \param ul_pres Master clock prescaler.
 */
void pmc_switch_mck_to_pllack(uint32_t ul_pres)
{
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLLA_CLK;
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_PRES_Msk) | PMC_MCKR_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Switch the master clock to PLLA clock divided by 2.
 *
 * \param ul_pres Master clock prescaler.
 */
void pmc_switch_mck_to_plladiv2(uint32_t ul_pres)
{
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_CSS_Msk) | PMC_MCKR_CSS_PLLA_CLK;
    PMC->PMC_MCKR |= PMC_MCKR_PLLADIV2;
    PMC->PMC_MCKR = (PMC->PMC_MCKR & ~PMC_MCKR_PRES_Msk) | PMC_MCKR_PRES_CLK_1 << ul_pres;
}

/**
 * \brief Switch the main clock to fast RC oscillator.
 */
void pmc_switch_mainck_to_fastrc(void)
{
    PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCSEL) | CKGR_MOR_MOSCRCEN;
}

/**
 * \brief Switch the main clock to crystal oscillator.
 */
void pmc_switch_mainck_to_xtal(void)
{
    PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCSEL) | CKGR_MOR_MOSCXTEN;
}

/**
 * \brief Enable the fast RC oscillator.
 *
 * \param ul_rc Fast RC oscillator frequency.
 */
void pmc_osc_enable_fastrc(uint32_t ul_rc)
{
    PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCRCF_Msk) | ul_rc | CKGR_MOR_MOSCRCEN;
}

/**
 * \brief Disable the fast RC oscillator.
 */
void pmc_osc_disable_fastrc(void)
{
    PMC->CKGR_MOR &= ~CKGR_MOR_MOSCRCEN;
}

/**
 * \brief Enable the crystal oscillator.
 *
 * \param ul_xtal_startup_time Crystal oscillator startup time.
 */
void pmc_osc_enable_xtal(uint32_t ul_xtal_startup_time)
{
    PMC->CKGR_MOR = (PMC->CKGR_MOR & ~CKGR_MOR_MOSCXTST_Msk) | ul_xtal_startup_time | CKGR_MOR_MOSCXTEN;
}

/**
 * \brief Disable the crystal oscillator.
 */
void pmc_osc_disable_xtal(void)
{
    PMC->CKGR_MOR &= ~CKGR_MOR_MOSCXTEN;
}

/**
 * \brief Check if the crystal oscillator is ready.
 *
 * \return 1 if the crystal oscillator is ready; otherwise 0.
 */
uint32_t pmc_osc_is_ready_xtal(void)
{
    return (PMC->PMC_SR & PMC_SR_MOSCXTS) ? 1 : 0;
}

/**
 * \brief Check if the fast RC oscillator is ready.
 *
 * \return 1 if the fast RC oscillator is ready; otherwise 0.
 */
uint32_t pmc_osc_is_ready_fastrc(void)
{
    return (PMC->PMC_SR & PMC_SR_MOSCRCS) ? 1 : 0;
}

/**
 * \brief Enable the PLLA.
 *
 * \param mul PLLA multiplier.
 * \param div PLLA divider.
 * \param count PLLA counter.
 */
void pmc_enable_pllack(uint32_t mul, uint32_t div, uint32_t count)
{
    PMC->CKGR_PLLAR = CKGR_PLLAR_ONE | CKGR_PLLAR_MULA(mul) | CKGR_PLLAR_DIVA(div) | CKGR_PLLAR_PLLACOUNT(count);
}

/**
 * \brief Disable the PLLA.
 */
void pmc_disable_pllack(void)
{
    PMC->CKGR_PLLAR = 0;
}

/**
 * \brief Check if the PLLA is locked.
 *
 * \return 1 if the PLLA is locked; otherwise 0.
 */
uint32_t pmc_is_locked_pllack(void)
{
    return (PMC->PMC_SR & PMC_SR_LOCKA) ? 1 : 0;
}

/**
 * \brief Switch the USB clock to PLLA clock.
 *
 * \param ul_usbdiv USB clock divider.
 */
void pmc_switch_udpck_to_pllack(uint32_t ul_usbdiv)
{
    PMC->PMC_USB = (PMC->PMC_USB & ~PMC_USB_USBDIV_Msk) | PMC_USB_USBDIV(ul_usbdiv);
}

/**
 * \brief Switch the USB clock to PLLA clock divided by 2.
 *
 * \param ul_usbdiv USB clock divider.
 */
void pmc_switch_udpck_to_plladiv2(uint32_t ul_usbdiv)
{
    PMC->PMC_USB = (PMC->PMC_USB & ~PMC_USB_USBDIV_Msk) | PMC_USB_USBDIV(ul_usbdiv);
}

/**
 * \brief Switch the USB clock to main clock.
 *
 * \param ul_usbdiv USB clock divider.
 */
void pmc_switch_udpck_to_mainck(uint32_t ul_usbdiv)
{
    PMC->PMC_USB = (PMC->PMC_USB & ~PMC_USB_USBDIV_Msk) | PMC_USB_USBDIV(ul_usbdiv);
}

/**
 * \brief Enable sleep mode.
 *
 * \param ul_ucr Sleep mode configuration.
 */
void pmc_enable_sleepmode(uint32_t ul_ucr)
{
    // Implementation depends on specific sleep mode requirements
}

/**
 * \brief Enable wait mode.
 */
void pmc_enable_waitmode(void)
{
    // Implementation depends on specific wait mode requirements
}

/**
 * \brief Enable backup mode.
 */
void pmc_enable_backupmode(void)
{
    // Implementation depends on specific backup mode requirements
}

/**
 * \brief Set fast startup input.
 *
 * \param ul_inputs Fast startup inputs.
 * \param ul_polarity Fast startup polarity.
 */
void pmc_set_fast_startup_input(uint32_t ul_inputs, uint32_t ul_polarity)
{
    PMC->PMC_FSMR = ul_inputs;
    PMC->PMC_FSPR = ul_polarity;
}

/**
 * \brief Clear fast startup input.
 *
 * \param ul_inputs Fast startup inputs to clear.
 */
void pmc_clr_fast_startup_input(uint32_t ul_inputs)
{
    PMC->PMC_FSMR &= ~ul_inputs;
}

/**
 * \brief Set fast startup mode.
 *
 * \param ul_mode Fast startup mode.
 */
void pmc_set_fast_startup_mode(uint32_t ul_mode)
{
    PMC->PMC_FSMR = (PMC->PMC_FSMR & ~PMC_FSMR_FLPM_Msk) | ul_mode;
}

/**
 * \brief Set write protection.
 *
 * \param ul_enable Enable write protection.
 */
void pmc_set_writeprotect(uint32_t ul_enable)
{
    if (ul_enable) {
        PMC->PMC_WPMR = PMC_WPMR_WPEN | PMC_WPMR_WPKEY_PASSWD;
    } else {
        PMC->PMC_WPMR = PMC_WPMR_WPKEY_PASSWD;
    }
}

/**
 * \brief Get write protection status.
 *
 * \return Write protection status.
 */
uint32_t pmc_get_writeprotect_status(void)
{
    return PMC->PMC_WPSR;
}