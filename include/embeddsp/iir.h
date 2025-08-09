// include/embeddsp/iir.h

#ifndef EMBEDDSP_IIR_H
#define EMBEDDSP_IIR_H

#include <stdint.h>

/**
 * @brief A generic cascaded biquad IIR filter instance structure.
 *
 * This structure holds the state and configuration for a filter composed of
 * one or more second-order sections (biquads) connected in series.
 */
typedef struct {
    uint16_t num_sections;  /**< The number of biquad sections in the cascade. */
    const float* coeffs;    /**< Pointer to coefficient array. Size must be (num_sections * 5). */
    float* state;           /**< Pointer to state array. Size must be (num_sections * 2). */
} iir_biquad_cascaded_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes a cascaded biquad IIR filter structure.
 *
 * This function configures the filter instance by linking it to the user-provided
 * coefficient and state buffers. The coefficients for each biquad section are
 * arranged sequentially in the `coeffs` array.
 *
 * The coefficient order for EACH of the `num_sections` biquads must be:
 * { b0, b1, b2, a1, a2 }
 *
 * The state buffer is also cleared (filled with zeros).
 *
 * @param filter Pointer to the iir_biquad_cascaded_t instance to initialize.
 * @param num_sections The number of biquad sections.
 * @param coeffs Pointer to an array of coefficients. Must have (num_sections * 5) elements.
 * @param state_buffer Pointer to a buffer for state variables. Must have (num_sections * 2) elements.
 */
void iir_init(iir_biquad_cascaded_t* filter, uint16_t num_sections, const float* coeffs, float* state_buffer);

/**
 * @brief Processes one input sample and computes the corresponding output sample.
 *
 * The input sample is processed sequentially through each biquad section. The output
 * of one section becomes the input to the next. The implementation uses the
 * 'Direct Form II Transposed' structure for each biquad.
 *
 * @param filter Pointer to the initialized iir_biquad_cascaded_t instance.
 * @param input The new input sample to be processed.
 * @return The calculated output sample.
 */
float iir_update(iir_biquad_cascaded_t* filter, float input);

/**
 * @brief Resets the filter's state.
 *
 * This function clears the internal state variables (delay line) of the filter by
 * filling them with zeros. This is useful for clearing filter history.
 *
 * @param filter Pointer to the iir_biquad_cascaded_t instance to flush.
 */
void iir_flush(iir_biquad_cascaded_t* filter);


#ifdef __cplusplus
}
#endif

#endif // EMBEDDSP_IIR_H
