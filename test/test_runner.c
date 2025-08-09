/**
 * @file test_runner.c
 * @brief Main entry point for running all unit tests for the EmbedDSP library.
 *
 * This file gathers all test suites from the various test files
 * (e.g., test_fir.c, test_iir.c) and executes them using the Unity
 * test framework.
 */

#include "unity.h"

// --- Forward declarations of test suite runners ---
// For each new test file (e.g., test_fir.c), add a forward declaration
// to its test runner function here.
void run_fir_tests(void);
void run_iir_tests(void);
//void run_pid_tests(void);

/**
 * @brief setUp function, called before each test case.
 *
 * This function is automatically called by the Unity framework before each
 * test case (any function starting with "test_"). It's a great place
 * to put any code that needs to be run to set up the test environment.
 * For now, it's empty.
 */
void setUp(void) {
    // Set up code, if any, goes here
}

/**
 * @brief tearDown function, called after each test case.
 *
 * This function is automatically called by the Unity framework after each
 * test case. It's used for cleaning up resources allocated in setUp() or
 * during the test. For now, it's empty.
 */
void tearDown(void) {
    // Clean up code, if any, goes here
}

/**
 * @brief Main function for the test runner.
 *
 * This function initializes the Unity framework, calls all the test suite
 * runners, and reports the results.
 *
 * @return int The exit code from the Unity framework.
 */
int main(void) {
    // UNITY_BEGIN() must be the first function called in main().
    UNITY_BEGIN();

    // --- Call test suite runners here ---
    // As you create new test files, add a call to their runner function here.
    // For example, when you create test_fir.c, you will uncomment the line below.
    run_fir_tests();
    run_iir_tests();
    // run_pid_tests();

    // UNITY_END() must be the last function called in main().
    // It will report the test results and return the final status.
    return UNITY_END();
}
