#ifndef EMBEDDSP_FIR_H
#define EMBEDDSP_FIR_H

#include <stdint.h>

/**
 * @brief A generic FIR filter instance structure.
 *
 * This structure holds the state and configuration of a single FIR filter.
 * The user is responsible for allocating the memory for the coefficients array
 * and the state buffer before calling the initialization function.
 */
typedef struct fir_filter_t {
    const float* coeffs;    /**< Pointer to the array of filter coefficients (taps). Must have 'num_taps' elements. */
    float* state;           /**< Pointer to the state buffer (delay line). Must have 'num_taps' elements. */
    uint16_t num_taps;      /**< The number of taps in the filter (the filter order is num_taps - 1). */
    uint16_t state_index;   /**< The current index in the circular state buffer. */
} fir_filter_t;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes an FIR filter structure.
 *
 * This function configures the filter instance by linking it to the user-provided
 * coefficient and state buffers. It also clears the state buffer (fills it with zeros).
 *
 * @param filter Pointer to the fir_filter_t instance to initialize.
 * @param num_taps The number of coefficients (and the size of the state buffer).
 * @param coeffs Pointer to an array of 'num_taps' filter coefficients. This memory must be managed by the caller.
 * @param state_buffer Pointer to an array of 'num_taps' floats for the state buffer. This memory must be managed by the caller.
 */
void fir_init(fir_filter_t* filter, uint16_t num_taps, const float* coeffs, float* state_buffer);

/**
 * @brief Processes one input sample and computes the corresponding output sample.
 *
 * This is the main filter processing function. It takes a new input sample,
 * updates the filter's internal state, and calculates the filtered output
 * using the FIR equation:
 * y[n] = \sum_{k=0}^{N-1} h[k] \cdot x[n-k]
 * where N is 'num_taps'.
 *
 * @param filter Pointer to the initialized fir_filter_t instance.
 * @param input The new input sample to be processed.
 * @return The calculated output sample.
 */
float fir_update(fir_filter_t* filter, float input);

/**
 * @brief Resets the filter's state.
 *
 * This function clears the internal state buffer (delay line) of the filter by
 * filling it with zeros. The coefficients and configuration remain unchanged.
 *
 * @param filter Pointer to the fir_filter_t instance to flush.
 */
void fir_flush(fir_filter_t* filter);

#ifdef __cplusplus
}
#endif

#endif // EMBEDDSP_FIR_H
