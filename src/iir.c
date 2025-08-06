/**
 * @file iir.c
 * @brief Implementation of the generic cascaded biquad IIR filter module.
 */

#include "embeddsp/iir.h"
#include <stddef.h> // Required for NULL

/**
 * @brief Initializes a cascaded IIR filter instance.
 *
 * @param[out] iir           Pointer to the IIR filter instance structure to initialize.
 * @param[in]  num_sections  The number of biquad sections for the filter.
 * @param[in]  coeffs        Pointer to an array of biquad coefficient structures. The size
 * of this array must be `num_sections`.
 * @param[in]  state_buffer  Pointer to an array of biquad state structures. The size of
 * this array MUST be `num_sections`.
 *
 * @return 0 on success, -1 on failure (e.g., null pointers).
 */
int EmbedDSP_IIR_Init(EmbedDSP_IIR_t* iir, uint16_t num_sections, EmbedDSP_IIR_BiquadCoeffs_t* coeffs, EmbedDSP_IIR_BiquadState_t* state_buffer) {
    // --- 1. Input Validation ---
    if (!iir || !coeffs || !state_buffer) {
        return -1;
    }

    // --- 2. Configure the filter structure ---
    iir->num_sections = num_sections;
    iir->coeffs = coeffs;
    iir->state = state_buffer;

    // --- 3. Clear the state buffer ---
    // Initialize all delay elements to zero for a predictable start.
    for (uint16_t i = 0; i < num_sections; i++) {
        iir->state[i].z1 = 0.0f;
        iir->state[i].z2 = 0.0f;
    }

    return 0; // Success
}

/**
 * @brief Processes a single input sample through the cascaded IIR filter.
 *
 * Implements the Direct Form II Transposed structure for each biquad section.
 * The output of one section becomes the input for the next.
 *
 * Difference Equations:
 * y[n] = b0*x[n] + z1[n-1]
 * z1[n] = b1*x[n] - a1*y[n] + z2[n-1]
 * z2[n] = b2*x[n] - a2*y[n]
 *
 * @param[in,out] iir    Pointer to the initialized IIR filter instance.
 * @param[in]     input  The new input sample to process.
 *
 * @return The filtered output sample.
 */
float EmbedDSP_IIR_Process(EmbedDSP_IIR_t* iir, float input) {
    float section_input = input;
    float section_output;

    // Process the sample through each biquad section in the cascade
    for (uint16_t i = 0; i < iir->num_sections; i++) {
        // Get pointers to the current section's coefficients and state
        EmbedDSP_IIR_BiquadCoeffs_t* c = &iir->coeffs[i];
        EmbedDSP_IIR_BiquadState_t* s = &iir->state[i];

        // Calculate the output for the current section
        section_output = (section_input * c->b0) + s->z1;

        // Update the state variables for the next sample
        s->z1 = (section_input * c->b1) - (section_output * c->a1) + s->z2;
        s->z2 = (section_input * c->b2) - (section_output * c->a2);

        // The output of this section becomes the input for the next one
        section_input = section_output;
    }

    // The final output is the output of the last section
    return section_output;
}
