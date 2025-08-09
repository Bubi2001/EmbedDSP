/**
 * @file test_fir.c
 * @brief Unit tests for the FIR filter module.
 */

#include "unity.h"
#include "embeddsp/fir.h"
#include <stddef.h>

// --- Test Fixture variables remain the same ---
#define TEST_FILTER_TAPS 5
static const float test_coeffs[TEST_FILTER_TAPS] = {0.1f, 0.2f, 0.4f, 0.2f, 0.1f};
static fir_filter_t test_filter;
static float test_state[TEST_FILTER_TAPS];

// --- setUp and tearDown functions are REMOVED from this file ---

// --- Test Cases (each now handles its own initialization) ---

static void test_fir_initialization(void) {
    // Initialize the filter for this specific test
    fir_init(&test_filter, TEST_FILTER_TAPS, test_coeffs, test_state);

    TEST_ASSERT_EQUAL_UINT16(TEST_FILTER_TAPS, test_filter.num_taps);
    TEST_ASSERT_EQUAL_PTR(test_coeffs, test_filter.coeffs);
    // ... rest of the test ...
    for (int i = 0; i < TEST_FILTER_TAPS; ++i) {
        TEST_ASSERT_EQUAL_FLOAT(0.0f, test_filter.state[i]);
    }
}

static void test_fir_impulse_response(void) {
    // Initialize the filter for this specific test
    fir_init(&test_filter, TEST_FILTER_TAPS, test_coeffs, test_state);
    
    float output = fir_update(&test_filter, 1.0f);
    TEST_ASSERT_EQUAL_FLOAT(test_coeffs[0], output);
    // ... rest of the test ...
}

static void test_fir_step_response(void) {
    // Initialize the filter for this specific test
    fir_init(&test_filter, TEST_FILTER_TAPS, test_coeffs, test_state);
    
    // ... test logic ...
}

static void test_fir_flush_functionality(void) {
    // Initialize the filter for this specific test
    fir_init(&test_filter, TEST_FILTER_TAPS, test_coeffs, test_state);

    (void)fir_update(&test_filter, 5.0f);
    (void)fir_update(&test_filter, 10.0f);

    fir_flush(&test_filter);

    // ... rest of the test ...
}

// --- The Test Suite Runner remains the same ---
void run_fir_tests(void) {
    RUN_TEST(test_fir_initialization);
    RUN_TEST(test_fir_impulse_response);
    RUN_TEST(test_fir_step_response);
    RUN_TEST(test_fir_flush_functionality);
}
