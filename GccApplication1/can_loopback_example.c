/**
 * \file can_loopback_example.c
 * 
 * \brief CAN Loopback Test Example for ATSAME4
 * 
 * This example demonstrates how to use the CAN loopback test functionality
 * on the ATSAME4 microcontroller. It shows different testing scenarios
 * and how to interpret the results.
 */

#include "sam.h"
#include "can.h"
#include "can_app.h"
#include "can_loopback_test.h"

/**
 * \brief Example main function demonstrating CAN loopback testing
 */
int can_loopback_example_main(void)
{
    // Initialize system
    SystemInit();
    
    // Initialize CAN loopback test
    can_loopback_test_init();
    
    // Main loop counter
    uint32_t main_counter = 0;
    can_test_results_t *results;
    
    while (1) {
        // Run comprehensive test suite every 10000 iterations
        if (main_counter % 10000 == 0) {
            // Reset results before running tests
            can_loopback_test_reset_results();
            
            // Run the complete test suite
            can_loopback_test_suite();
            
            // Get and analyze results
            results = can_loopback_test_get_results();
            
            // Here you could add logic to handle test results
            // For example, set LEDs, send UART messages, etc.
            if (results->failed_tests == 0) {
                // All tests passed - could set a green LED
            } else {
                // Some tests failed - could set a red LED
            }
        }
        
        // Run continuous testing every 1000 iterations
        if (main_counter % 1000 == 0) {
            can_loopback_test_continuous();
        }
        
        // Run stress test every 100 iterations
        if (main_counter % 100 == 0) {
            can_loopback_test_stress();
        }
        
        // Simple delay
        for (volatile uint32_t i = 0; i < 1000; i++);
        
        main_counter++;
    }
    
    return 0;
}

/**
 * \brief Example function showing how to run a custom loopback test
 */
void can_loopback_custom_test_example(void)
{
    uint8_t custom_data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    uint8_t test_result;
    
    // Initialize loopback test
    can_loopback_test_init();
    
    // Run a custom test with specific data
    test_result = can_loopback_test_run_single(0x123, custom_data, 8, 100);
    
    if (test_result) {
        // Test passed - handle success case
        // Could set LED, send UART message, etc.
    } else {
        // Test failed - handle failure case
        // Could set different LED, log error, etc.
    }
}

/**
 * \brief Example function showing how to monitor test results
 */
void can_loopback_monitor_results_example(void)
{
    can_test_results_t *results;
    static uint32_t last_total_tests = 0;
    
    // Get current results
    results = can_loopback_test_get_results();
    
    // Check if new tests have been run
    if (results->total_tests > last_total_tests) {
        // New test results available
        
        // Calculate success rate
        uint32_t success_rate = 0;
        if (results->total_tests > 0) {
            success_rate = (results->passed_tests * 100) / results->total_tests;
        }
        
        // Here you could:
        // - Send results via UART
        // - Update display
        // - Set status LEDs
        // - Log to memory
        // - Send via CAN to other nodes
        
        // Example: Simple status indication
        if (success_rate >= 95) {
            // Excellent performance
        } else if (success_rate >= 80) {
            // Good performance
        } else {
            // Poor performance - investigate issues
        }
        
        last_total_tests = results->total_tests;
    }
}

/**
 * \brief Example function showing error analysis
 */
void can_loopback_analyze_errors_example(void)
{
    can_test_results_t *results = can_loopback_test_get_results();
    
    if (results->timeout_errors > 0) {
        // Timeout errors detected
        // Possible causes:
        // - CAN controller not responding
        // - Interrupt not working properly
        // - Clock issues
        // - Hardware problems
    }
    
    if (results->data_mismatch_errors > 0) {
        // Data integrity issues
        // Possible causes:
        // - Memory corruption
        // - DMA issues
        // - Clock domain problems
        // - Electromagnetic interference
    }
    
    if (results->id_mismatch_errors > 0) {
        // ID filtering issues
        // Possible causes:
        // - Mailbox configuration problems
        // - Filter setup issues
        // - Hardware malfunction
    }
}