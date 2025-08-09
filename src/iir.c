#include "embeddsp/iir.h"
#include <string.h>

/**
 * @brief Initializes a cascaded biquad IIR filter.
 */
void iir_init(iir_biquad_cascaded_t* filter, uint16_t num_sections, const float* coeffs, float* state_buffer) {
    if (!filter || !coeffs || !state_buffer || num_sections == 0) {
        return;
    }

    filter->num_sections = num_sections;
    filter->coeffs = coeffs;
    filter->state = state_buffer;

    iir_flush(filter);
}

/**
 * @brief Resets the filter's state.
 */
void iir_flush(iir_biquad_cascaded_t* filter) {
    if (!filter || !filter->state) {
        return;
    }
    // Clear the entire state buffer for all sections
    memset(filter->state, 0, filter->num_sections * 2 * sizeof(float));
}

/**
 * @brief Processes one sample through the cascaded IIR filter.
 */
float iir_update(iir_biquad_cascaded_t* filter, float input) {
    float current_sample = input;

    // Process the sample through each biquad section in the cascade
    for (uint16_t i = 0; i < filter->num_sections; ++i) {
        // Get pointers to the coefficients and state for the current section
        const float* section_coeffs = &filter->coeffs[i * 5];
        float* section_state = &filter->state[i * 2];

        // Aliases for clarity
        const float b0 = section_coeffs[0];
        const float b1 = section_coeffs[1];
        const float b2 = section_coeffs[2];
        const float a1 = section_coeffs[3];
        const float a2 = section_coeffs[4];
        float z1 = section_state[0];
        float z2 = section_state[1];

        // Apply the Direct Form II Transposed difference equation
        // y[n] = b0*x[n] + z1[n-1]
        float output = (b0 * current_sample) + z1;

        // Update state variables for the next sample
        // z1[n] = b1*x[n] - a1*y[n] + z2[n-1]
        z1 = (b1 * current_sample) - (a1 * output) + z2;
        // z2[n] = b2*x[n] - a2*y[n]
        z2 = (b2 * current_sample) - (a2 * output);

        // Store the new state
        section_state[0] = z1;
        section_state[1] = z2;

        // The output of this section is the input for the next
        current_sample = output;
    }

    return current_sample; // The final output after all sections
}
