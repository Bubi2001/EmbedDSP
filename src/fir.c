/**
 * @file fir.c
 * @brief Implementation of the generic FIR filter module.
 */

#include "embeddsp/fir.h"
#include <stddef.h> // Required for NULL

/**
 * @brief Initializes a FIR filter instance.
 *
 * This function configures a FIR filter instance by linking it to user-provided
 * coefficient and state buffers. It also clears the state buffer and sets up
 * the initial state of the filter.
 *
 * @param[out] fir           Pointer to the FIR filter instance structure to initialize.
 * @param[in]  order         The order of the filter.
 * @param[in]  coeffs        Pointer to an array of filter coefficients. The size of this
 * array must be (order + 1).
 * @param[in]  state_buffer  Pointer to a float array to be used as the internal
 * state/delay line. The size of this array MUST be
 * (order + 1).
 *
 * @return 0 on success, -1 on failure (e.g., null pointers).
 */
int EmbedDSP_FIR_Init(EmbedDSP_FIR_t* fir, uint16_t order, float* coeffs, float* state_buffer) {
    // --- 1. Input Validation ---
    // Always check for null pointers to prevent crashes.
    if (!fir || !coeffs || !state_buffer) {
        return -1; // Return error code
    }

    // --- 2. Configure the filter structure ---
    fir->order = order;
    fir->num_taps = order + 1;
    fir->coeffs = coeffs;
    fir->state = state_buffer;
    fir->write_index = 0;

    // --- 3. Clear the state buffer ---
    // It's crucial to start with a clean delay line to avoid unpredictable output.
    for (uint16_t i = 0; i < fir->num_taps; i++) {
        fir->state[i] = 0.0f;
    }

    return 0; // Success
}


/**
 * @brief Processes a single input sample through the FIR filter.
 *
 * This function executes the core FIR filter logic (convolution) using a
 * circular buffer for the state management, which is efficient for embedded systems.
 *
 * @param[in,out] fir    Pointer to the initialized FIR filter instance.
 * @param[in]     input  The new input sample to process.
 *
 * @return The filtered output sample.
 */
float EmbedDSP_FIR_Process(EmbedDSP_FIR_t* fir, float input) {
    // --- 1. Store the new input sample in the circular state buffer ---
    // The `state` buffer acts as a delay line. We add the new sample
    // at the current write_index.
    fir->state[fir->write_index] = input;

    // --- 2. Perform the convolution (dot product) ---
    // The output is the sum of the products of the coefficients and the
    // corresponding state values (taps).
    float output = 0.0f;
    uint16_t read_index = fir->write_index;

    for (uint16_t i = 0; i < fir->num_taps; i++) {
        // Multiply the i-th coefficient with the corresponding state value.
        // The read_index wraps around the circular buffer.
        output += fir->coeffs[i] * fir->state[read_index];

        // Move the read index to the next oldest sample, wrapping around if necessary.
        if (read_index == 0) {
            // If we are at the beginning of the buffer, wrap to the end.
            read_index = fir->num_taps - 1;
        } else {
            read_index--;
        }
    }

    // --- 3. Update the write index for the next sample ---
    // We move the write index to the next position in the circular buffer.
    fir->write_index++;
    if (fir->write_index >= fir->num_taps) {
        // If we've reached the end, wrap back to the beginning.
        fir->write_index = 0;
    }

    // --- 4. Return the calculated output ---
    return output;
}
