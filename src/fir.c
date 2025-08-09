#include "embeddsp/fir.h"
#include <string.h>

/**
 * @brief Initializes an FIR filter structure.
 */
void fir_init(fir_filter_t* filter, uint16_t num_taps, const float* coeffs, float* state_buffer) {
    // Assert that pointers are not null, and num_taps is valid
    if (!filter || !coeffs || !state_buffer || num_taps == 0) {
        return;
    }

    filter->num_taps = num_taps;
    filter->coeffs = coeffs;
    filter->state = state_buffer;

    // Reset the filter state
    fir_flush(filter);
}

/**
 * @brief Resets the filter's state.
 */
void fir_flush(fir_filter_t* filter) {
    if (!filter || !filter->state) {
        return;
    }
    
    // Clear the state buffer and reset the index
    memset(filter->state, 0, filter->num_taps * sizeof(float));
    filter->state_index = 0;
}

/**
 * @brief Processes one input sample and computes the corresponding output sample.
 */
float fir_update(fir_filter_t* filter, float input) {
    // The state buffer is treated as a circular buffer.
    // The state_index points to the location where the oldest sample is stored,
    // which is the location where the new input sample will be written.

    // Store the new input sample in the state buffer
    filter->state[filter->state_index] = input;

    // Calculate the filter output using convolution sum
    // y[n] = h[0]*x[n] + h[1]*x[n-1] + ... + h[N-1]*x[n-N+1]
    float output = 0.0f;
    uint16_t current_pos = filter->state_index;

    for (uint16_t i = 0; i < filter->num_taps; ++i) {
        // Multiply coefficient with the corresponding state sample
        // state[current_pos] corresponds to x[n-i]
        output += filter->coeffs[i] * filter->state[current_pos];
        
        // Decrement position in the circular buffer
        // The newest sample is at state_index, next newest is at state_index-1 (with wrap-around) etc.
        if (current_pos == 0) {
            current_pos = filter->num_taps - 1;
        } else {
            current_pos--;
        }
    }
    
    // Increment the state index for the next call, with wrap-around
    filter->state_index++;
    if (filter->state_index >= filter->num_taps) {
        filter->state_index = 0;
    }
    
    return output;
}
