#ifndef EMBEDDSP_IIR_H
#define EMBEDDSP_IIR_H

#include <stdint.h> // For standard integer types like uint16_t

/**
 * @brief Coefficients for a single IIR biquad section.
 *
 * For a standard transfer function H(z) = (b0 + b1*z^-1 + b2*z^-2) / (1 + a1*z^-1 + a2*z^-2),
 * these are the coefficients. Note that a0 is assumed to be 1.
 */
typedef struct {
    float b0, b1, b2; // Feedforward coefficients
    float a1, a2;     // Feedback coefficients
} EmbedDSP_IIR_BiquadCoeffs_t;

/**
 * @brief State variables for a single IIR biquad section (Direct Form II Transposed).
 */
typedef struct {
    float z1, z2; // Delay elements (state)
} EmbedDSP_IIR_BiquadState_t;

/**
 * @brief IIR filter instance structure.
 *
 * This structure holds the state of a cascaded IIR filter. It contains pointers
 * to user-provided arrays for the coefficients and state of each biquad section.
 * This avoids dynamic memory allocation.
 */
typedef struct {
    uint16_t num_sections; // Number of biquad sections in the cascade.
    EmbedDSP_IIR_BiquadCoeffs_t* coeffs; // Pointer to the array of coefficient sets.
    EmbedDSP_IIR_BiquadState_t* state;  // Pointer to the array of state variables.
} EmbedDSP_IIR_t;


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
int EmbedDSP_IIR_Init(EmbedDSP_IIR_t* iir, uint16_t num_sections, EmbedDSP_IIR_BiquadCoeffs_t* coeffs, EmbedDSP_IIR_BiquadState_t* state_buffer);


/**
 * @brief Processes a single input sample through the cascaded IIR filter.
 *
 * @param[in,out] iir    Pointer to the initialized IIR filter instance.
 * @param[in]     input  The new input sample to process.
 *
 * @return The filtered output sample.
 */
float EmbedDSP_IIR_Process(EmbedDSP_IIR_t* iir, float input);

#endif // EMBEDDSP_IIR_H
