/**
 * \file can_loopback_test.h
 * 
 * \brief CAN Loopback Test Header File for ATSAME4
 * 
 * This header file provides declarations for comprehensive CAN loopback
 * testing functionality on the ATSAME4 microcontroller.
 */

#ifndef CAN_LOOPBACK_TEST_H_INCLUDED
#define CAN_LOOPBACK_TEST_H_INCLUDED

#include "can_app.h"

// Test result tracking structure
typedef struct {
    uint32_t total_tests;
    uint32_t passed_tests;
    uint32_t failed_tests;
    uint32_t timeout_errors;
    uint32_t data_mismatch_errors;
    uint32_t id_mismatch_errors;
} can_test_results_t;

// Function declarations
void can_loopback_test_init(void);
uint8_t can_loopback_test_run_single(uint32_t test_id, uint8_t *test_data, uint8_t data_length, uint32_t timeout_ms);
void can_loopback_test_suite(void);
can_test_results_t* can_loopback_test_get_results(void);
void can_loopback_test_reset_results(void);
uint8_t can_loopback_test_is_in_progress(void);
void can_loopback_test_continuous(void);
void can_loopback_test_stress(void);

#endif /* CAN_LOOPBACK_TEST_H_INCLUDED */