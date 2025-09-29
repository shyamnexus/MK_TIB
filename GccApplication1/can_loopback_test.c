/**
 * \file can_loopback_test.c
 * 
 * \brief Comprehensive CAN Loopback Test Implementation for ATSAME4
 * 
 * This file provides a complete CAN loopback testing solution for the ATSAME4
 * microcontroller. Since the ATSAME4 doesn't have built-in hardware loopback
 * mode, this implementation provides software-based loopback testing.
 */

#include "sam.h"
#include "can.h"
#include "can_app.h"

// Test result tracking
typedef struct {
    uint32_t total_tests;
    uint32_t passed_tests;
    uint32_t failed_tests;
    uint32_t timeout_errors;
    uint32_t data_mismatch_errors;
    uint32_t id_mismatch_errors;
} can_test_results_t;

// Global test variables
static can_test_results_t g_test_results = {0};
static volatile uint8_t g_test_in_progress = 0;
static volatile uint32_t g_test_timeout_counter = 0;

/**
 * \brief Initialize comprehensive CAN loopback test
 */
void can_loopback_test_init(void)
{
    // Initialize test results
    g_test_results.total_tests = 0;
    g_test_results.passed_tests = 0;
    g_test_results.failed_tests = 0;
    g_test_results.timeout_errors = 0;
    g_test_results.data_mismatch_errors = 0;
    g_test_results.id_mismatch_errors = 0;
    
    g_test_in_progress = 0;
    g_test_timeout_counter = 0;
    
    // Initialize CAN for loopback testing
    can_init_loopback_test();
}

/**
 * \brief Run a single loopback test with specific data
 * 
 * @param test_id CAN message ID for the test
 * @param test_data Pointer to test data array
 * @param data_length Length of test data (1-8 bytes)
 * @param timeout_ms Timeout in milliseconds
 * @return 1 if test passed, 0 if test failed
 */
uint8_t can_loopback_test_run_single(uint32_t test_id, uint8_t *test_data, uint8_t data_length, uint32_t timeout_ms)
{
    can_message_t received_msg;
    uint32_t timeout_counter = 0;
    uint32_t timeout_limit = timeout_ms * 1000; // Convert to loop iterations
    
    g_test_results.total_tests++;
    g_test_in_progress = 1;
    
    // Send test message
    if (!can_loopback_test_send(test_id, test_data, data_length)) {
        g_test_results.failed_tests++;
        g_test_in_progress = 0;
        return 0;
    }
    
    // Wait for reception with timeout
    while (timeout_counter < timeout_limit && !g_can_loopback_test_complete) {
        timeout_counter++;
        
        // Check for received message
        if (can_loopback_test_receive(&received_msg)) {
            // Verify message ID
            if (received_msg.id != test_id) {
                g_test_results.id_mismatch_errors++;
                g_test_results.failed_tests++;
                g_test_in_progress = 0;
                return 0;
            }
            
            // Verify data length
            if (received_msg.length != data_length) {
                g_test_results.data_mismatch_errors++;
                g_test_results.failed_tests++;
                g_test_in_progress = 0;
                return 0;
            }
            
            // Verify data integrity
            if (!can_loopback_test_verify(test_data, received_msg.data, data_length)) {
                g_test_results.data_mismatch_errors++;
                g_test_results.failed_tests++;
                g_test_in_progress = 0;
                return 0;
            }
            
            // Test passed
            g_test_results.passed_tests++;
            g_test_in_progress = 0;
            return 1;
        }
    }
    
    // Timeout occurred
    if (timeout_counter >= timeout_limit) {
        g_test_results.timeout_errors++;
        g_test_results.failed_tests++;
    }
    
    g_test_in_progress = 0;
    return 0;
}

/**
 * \brief Run comprehensive loopback test suite
 * 
 * This function runs multiple test cases with different data patterns
 * to thoroughly test the CAN loopback functionality.
 */
void can_loopback_test_suite(void)
{
    uint8_t test_data[8];
    uint8_t test_result;
    
    // Test Case 1: Simple data pattern
    test_data[0] = 0xAA;
    test_data[1] = 0x55;
    test_data[2] = 0x12;
    test_data[3] = 0x34;
    test_result = can_loopback_test_run_single(0x123, test_data, 4, 100);
    
    // Test Case 2: All zeros
    for (uint8_t i = 0; i < 8; i++) {
        test_data[i] = 0x00;
    }
    test_result = can_loopback_test_run_single(0x456, test_data, 8, 100);
    
    // Test Case 3: All ones
    for (uint8_t i = 0; i < 8; i++) {
        test_data[i] = 0xFF;
    }
    test_result = can_loopback_test_run_single(0x789, test_data, 8, 100);
    
    // Test Case 4: Incremental pattern
    for (uint8_t i = 0; i < 8; i++) {
        test_data[i] = i;
    }
    test_result = can_loopback_test_run_single(0xABC, test_data, 8, 100);
    
    // Test Case 5: Random-like pattern
    test_data[0] = 0x12;
    test_data[1] = 0x34;
    test_data[2] = 0x56;
    test_data[3] = 0x78;
    test_data[4] = 0x9A;
    test_data[5] = 0xBC;
    test_data[6] = 0xDE;
    test_data[7] = 0xF0;
    test_result = can_loopback_test_run_single(0xDEF, test_data, 8, 100);
    
    // Test Case 6: Single byte
    test_data[0] = 0x42;
    test_result = can_loopback_test_run_single(0x111, test_data, 1, 100);
    
    // Test Case 7: Two bytes
    test_data[0] = 0xAB;
    test_data[1] = 0xCD;
    test_result = can_loopback_test_run_single(0x222, test_data, 2, 100);
    
    // Test Case 8: Maximum length with alternating pattern
    for (uint8_t i = 0; i < 8; i++) {
        test_data[i] = (i % 2) ? 0xAA : 0x55;
    }
    test_result = can_loopback_test_run_single(0x333, test_data, 8, 100);
}

/**
 * \brief Get current test results
 * 
 * @return Pointer to test results structure
 */
can_test_results_t* can_loopback_test_get_results(void)
{
    return &g_test_results;
}

/**
 * \brief Reset test results
 */
void can_loopback_test_reset_results(void)
{
    g_test_results.total_tests = 0;
    g_test_results.passed_tests = 0;
    g_test_results.failed_tests = 0;
    g_test_results.timeout_errors = 0;
    g_test_results.data_mismatch_errors = 0;
    g_test_results.id_mismatch_errors = 0;
}

/**
 * \brief Check if test is currently in progress
 * 
 * @return 1 if test in progress, 0 if not
 */
uint8_t can_loopback_test_is_in_progress(void)
{
    return g_test_in_progress;
}

/**
 * \brief Run continuous loopback test
 * 
 * This function runs loopback tests continuously with different
 * data patterns and CAN IDs to stress test the system.
 */
void can_loopback_test_continuous(void)
{
    static uint32_t test_counter = 0;
    uint8_t test_data[8];
    uint32_t test_id;
    
    // Generate test data based on counter
    for (uint8_t i = 0; i < 8; i++) {
        test_data[i] = (uint8_t)((test_counter + i) & 0xFF);
    }
    
    // Generate test ID based on counter
    test_id = 0x100 + (test_counter % 0x800); // Use IDs 0x100-0x8FF
    
    // Run the test
    can_loopback_test_run_single(test_id, test_data, 8, 50);
    
    test_counter++;
}

/**
 * \brief Run stress test with high frequency
 * 
 * This function runs rapid loopback tests to stress test
 * the CAN controller and verify it can handle high message rates.
 */
void can_loopback_test_stress(void)
{
    static uint32_t stress_counter = 0;
    uint8_t test_data[8];
    
    // Generate rapid test data
    for (uint8_t i = 0; i < 8; i++) {
        test_data[i] = (uint8_t)(stress_counter & 0xFF);
    }
    
    // Run stress test with short timeout
    can_loopback_test_run_single(0x999, test_data, 8, 10);
    
    stress_counter++;
}