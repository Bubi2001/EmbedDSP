/**
 * @file test_iir.c
 * @brief Unit tests for the cascaded biquad IIR filter module.
 */

#include "unity.h"
#include "embeddsp/iir.h"
#include <stddef.h>

// --- Test Fixture variables remain the same ---
#define TEST_IIR_SECTIONS 2
static const float test_coeffs_iir[TEST_IIR_SECTIONS * 5] = { /* ...coeffs... */ };
static const float expected_impulse_response[10] = { /* ...values... */ };
static const float expected_step_response[10] = { /* ...values... */ };
#define DC_GAIN 1.0f
static iir_biquad_cascaded_t test_filter;
static float test_state_iir[TEST_IIR_SECTIONS * 2];

// --- setUp and tearDown functions are REMOVED from this file ---

// --- Test Cases (each now handles its own initialization) ---

static void test_iir_initialization(void) {
    // Initialize the filter for this specific test
    iir_init(&test_filter, TEST_IIR_SECTIONS, test_coeffs_iir, test_state_iir);
    
    // ... rest of the test ...
}

static void test_iir_impulse_response(void) {
    // Initialize the filter for this specific test
    iir_init(&test_filter, TEST_IIR_SECTIONS, test_coeffs_iir, test_state_iir);
    
    // ... test logic ...
}

static void test_iir_step_response_settles_at_dc_gain(void) {
    // Initialize the filter for this specific test
    iir_init(&test_filter, TEST_IIR_SECTIONS, test_coeffs_iir, test_state_iir);

    // ... test logic ...
}

static void test_iir_flush_functionality(void) {
    // Initialize the filter for this specific test
    iir_init(&test_filter, TEST_IIR_SECTIONS, test_coeffs_iir, test_state_iir);
    
    (void)iir_update(&test_filter, 10.0f);
    (void)iir_update(&test_filter, -5.0f);

    iir_flush(&test_filter);
    
    // ... rest of the test ...
}

// --- The Test Suite Runner remains the same ---
void run_iir_tests(void) {
    RUN_TEST(test_iir_initialization);
    RUN_TEST(test_iir_impulse_response);
    RUN_TEST(test_iir_step_response_settles_at_dc_gain);
    RUN_TEST(test_iir_flush_functionality);
}
