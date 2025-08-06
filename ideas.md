pid

ekf

fft

dct

windowing

**Common Windows:**

* **Hamming:** Very popular all-purpose window.
* **Hanning:** Similar to Hamming, good for general use.
* **Blackman-Harris:** Excellent for finding low-level signals near high-level ones (high dynamic range).

vector math

* `mydsp_vec_add_f32()`: Element-wise addition of two vectors.
* `mydsp_vec_mult_f32()`: Element-wise multiplication.
* `mydsp_vec_dot_product_f32()`: Dot product of two vectors.
* `mydsp_vec_scale_f32()`: Multiply a vector by a scalar.
* `mydsp_mean_f32()`: Calculate the mean of a vector.
* `mydsp_std_dev_f32()`: Calculate the standard deviation.
* `mydsp_rms_f32()`: Calculate the Root Mean Square.

matrix math

* `mydsp_mat_init()`: Initialize a matrix structure.
* `mydsp_mat_add_f32()`: Matrix addition.
* `mydsp_mat_mult_f32()`: Matrix multiplication.
* `mydsp_mat_transpose_f32()`: Matrix transpose.
* `mydsp_mat_inv_f32()`: Matrix inversion (this is the hardest one! Start with 2x2 and 3x3 if that's all your EKF needs).

moving average filter

median filter

complementary filter

mahony or madgwick filter

decimation

* **What it does:** Reduces the sampling rate of a signal by an integer factor **M**. For example, converting a 48 kHz audio stream to 8 kHz (a decimation factor of 6).
* **Why it's useful:**
  * Reducing the computational load for subsequent processing.
  * Saving memory or transmission bandwidth.
  * Isolating a lower frequency band of interest.
* **Implementation:** This is a two-step process:
  1. **Low-pass filter:** Apply a sharp low-pass FIR filter (called an anti-aliasing filter) to the input signal to remove all frequencies above the new, lower Nyquist frequency.
  2. **Downsample:** Keep one sample and discard the next **M**−**1** samples.

interpolation

* **What it does:** Increases the sampling rate of a signal by an integer factor **L**.
* **Why it's useful:**
  * Matching the sample rate of one signal to another for processing.
  * In Digital-to-Analog Conversion (DAC) systems to create a smoother output.
* **Implementation:** This is also a two-step process:
  1. **Upsample (Zero-stuffing):** Insert **L**−**1** zeros between each input sample.
  2. **Low-pass filter:** Apply a low-pass FIR filter (called an anti-imaging filter) to remove the spectral images created by the zero-stuffing. This filter's gain must also be **L** to compensate for the energy loss.

convolution

autocorrelation

crosscorrelation

least mean squares

recursive least squares

acoustic echo cancellation

stft

ask

fsk

psk

qam

pll
