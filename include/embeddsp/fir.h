#ifndef EMBEDDSP_FIR_H
#define EMBEDDSP_FIR_H

#include <stdint.h> // For standard integer types like uint16_t

/**
 * @brief FIR filter instance structure.
 *
 * This structure holds the state of a single FIR filter instance.
 * It does NOT contain the state (delay line) or coefficient buffers itself.
 * Instead, it holds pointers to buffers provided by the user. This avoids
 * dynamic memory allocation and allows for flexible filter orders.
 */
typedef struct {
    uint16_t order;         // The order of the filter (number of taps - 1).
    uint16_t num_taps;      // The number of taps (order + 1).
    float* coeffs;          // Pointer to the coefficient buffer (provided by user).
    float* state;           // Pointer to the state/delay line buffer (provided by user).
    uint16_t write_index;   // The current write index for the circular state buffer.
} EmbedDSP_FIR_t;


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
int EmbedDSP_FIR_Init(EmbedDSP_FIR_t* fir, uint16_t order, float* coeffs, float* state_buffer);


/**
 * @brief Processes a single input sample through the FIR filter.
 *
 * @param[in,out] fir    Pointer to the initialized FIR filter instance.
 * @param[in]     input  The new input sample to process.
 *
 * @return The filtered output sample.
 */
float EmbedDSP_FIR_Process(EmbedDSP_FIR_t* fir, float input);

#endif // EMBEDDSP_FIR_H
