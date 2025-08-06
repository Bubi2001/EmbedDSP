# EmbedDSP 🎼

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C/C++ CI](https://github.com/Bubi2001/EmbedDSP/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/Bubi2001/EmbedDSP/actions/workflows/ci.yml)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/Bubi2001/EmbedDSP)](https://github.com/Bubi2001/EmbedDSP/releases)
[![GitHub last commit](https://img.shields.io/github/last-commit/Bubi2001/EmbedDSP)](https://github.com/Bubi2001/EmbedDSP/commits/main)
[![GitHub repo size](https://img.shields.io/github/repo-size/Bubi2001/EmbedDSP)](https://github.com/Bubi2001/EmbedDSP)
[![GitHub contributors](https://img.shields.io/github/contributors/Bubi2001/EmbedDSP)](https://github.com/Bubi2001/EmbedDSP/graphs/contributors)

> An open-source C library of DSP algorithms, crafted like a luthier's toolkit: precise, reliable, and built for performance on resource-constrained systems.

---

## The Luthier's Philosophy

This project is inspired by the art of a luthier: a craftsperson who builds and repairs string instruments. The philosophy is to provide a set of perfectly tuned, high-quality tools that work in harmony to shape, refine, and control signals with precision and elegance.

Each module in `EmbedDSP` is designed to be one of those specialized tools: lightweight, deterministic, and easy to integrate. They are the fundamental building blocks for crafting your own real-time audio effects, control systems, and sensor processing applications on microcontrollers.

## Key Features

- **Lightweight & Modular:** Each DSP algorithm is a self-contained module, designed to be easily included in your project with minimal overhead.
- **No Dynamic Memory:** Uses a static, caller-allocates-memory pattern. No `malloc` calls ensures deterministic, real-time safe performance suitable for any bare-metal or RTOS environment.
- **Portable C99:** Written in standard C99 with no external dependencies for maximum portability across different MCUs and toolchains.
- **Core DSP Algorithms:** Provides a collection of the most essential DSP building blocks for filtering, control, and analysis.
- **Fully Tested & Documented:** Each module is rigorously tested with a dedicated unit test suite and comes with clear documentation.
- **Permissive MIT License:** Allows unrestricted use in both hobbyist and commercial projects without limitations.

## Available Modules

This is the collection of DSP algorithms available in the library.

| Module | Status | Description |
| :----------------- | :--------: | :----------------------------------------------------------------- |
| **FIR Filter** | 🟡 In Progress | A generic, Nth-order Finite Impulse Response filter.|
| **IIR Filter** | 🟡 In Progress | A generic, cascaded biquad Infinite Impulse Response filter. |
| **Vector Math** | ❌ Planned | A generic collection of vector arithmetic: addition, element-wise multiplication, dot product, cross product, scale... |
| **Matrix Math** | ❌ Planned | A generic collection of matrix arithmetic: initialisation, addition, multiplication, transpose, inversion... |
| **PID Controller** | ❌ Planned | A Proportional-Integral-Derivative controller with anti-windup, derivative on measurement and a low-pass filter on the derivative path. |
| **Extended Kalman Filter** | ❌ Planned | A state predictor to extract Pitch and Roll angles from accelerometer and gyroscope data. |
| **FFT** | ❌ Planned   | A Fast Fourier Transform algorithm for spectral analysis. |
| **DCT** | ❌ Planned | A mathematical technique used to convert a signal or image from the spatial domain to the frequency domain, primarily for data compression. It is widely utilized in digital media formats like JPEG for images and MP3 for audio, helping to reduce file sizes while maintaining quality. |
| **Windowing** | ❌ Planned | Windows to be used in FFTs: Hamming, Hanning & Blackman-Harris |
| **Moving Average Filter** | ❌ Planned | A moving average filter is a statistical tool used to smooth out data by averaging a set number of data points over time, which helps to reduce noise and highlight trends. |
| **Median Filter** | ❌ Planned | The median filter is a non-linear digital filtering technique, often used to remove noise from an image, signal, and video. |
| **Complemntary Filter** | ❌ Planned | A weighted sum between Aceelerometer and Gyroscope readings to extract Pitch and Roll angles. |
| **Mahony Filter** | ❌ Planned | A type of sensor fusion algorithm primarily used for attitude estimation in inertial navigation systems. |
| **Madgwick Filter** | ❌ Planned | A type of sensor fusion algorithm primarily used for attitude estimation in inertial navigation systems. |
| **Decimation** | ❌ Planned | A process of reducing the sampling rate of a signal by selectively removing samples, often used to decrease data size while preserving essential information. |
| **Interpolation** | ❌ Planned | A technique to estimate unknown values between discrete data points, commonly used to increase the sampling rate of a signal. |
| **Convolution** | ❌ Planned | A mathematical operation that combines two signals to produce a third signal, representing the amount of overlap between the two as one signal slides over the other. |
| **Auto-Correlation** | ❌ Planned | A statistical method that measures the similarity between a signal and a delayed version of itself over varying time lags, used to identify repeating patterns or periodicity in the data. |
| **Cross-Correlation** | ❌ Planned |  A statistical technique that measures the similarity between two different signals as one is shifted over time, used to identify the time delay or relationship between the signals. |
| **Least Mean Squares** | ❌ Planned | An adaptive filtering algorithm that minimizes the mean square error between the desired output and the actual output by iteratively adjusting filter coefficients based on the input signal. |
| **Recursive Least Squares** | ❌ Planned | An adaptive filtering algorithm that updates filter coefficients recursively to minimize the weighted least squares error, allowing for faster convergence and better performance in non-stationary environments compared to LMS. |
| **Acoustic Echo Cancellation** | ❌ Planned | A signal processing technique that removes echo from audio signals in real-time, typically used in telecommunication systems to enhance voice clarity by distinguishing between the original sound and the echoed sound. |
| **STFT** | ❌ Planned | A time-frequency analysis technique that divides a signal into overlapping segments and applies the Fourier transform to each segment, allowing for the examination of how the frequency content of the signal changes over time. |
| **ASK** | ❌ Planned | A modulation technique that encodes digital data by varying the amplitude of a carrier wave, where different amplitudes represent different binary values, typically used in simple communication systems. |
| **FSK** | ❌ Planned | A modulation technique that encodes digital data by varying the frequency of a carrier wave, where different frequencies represent different binary values, commonly used in data transmission and radio communications. |
| **PSK** | ❌ Planned | A modulation technique that encodes digital data by varying the phase of a carrier wave, where different phase shifts represent different binary values, widely used in digital communication systems for its robustness against noise. |
| **QAM** | ❌ Planned | A modulation technique that combines both amplitude and phase variations of a carrier wave to encode data, allowing for the transmission of multiple bits per symbol, commonly used in digital communication systems for efficient bandwidth utilization. |
| **PLL** | ❌ Planned | A control system that synchronizes an output signal's phase with a reference signal's phase, used for frequency synthesis, demodulation, and clock recovery in communication systems. |

## Getting Started

Integrating an `EmbedDSP` module into your embedded project is designed to be simple.

1. **Clone the repository:**

    ```bash
    git clone https://github.com/Bubi2001/EmbedDSP.git
    ```

2. **Copy the source files.** Copy the contents of the `src/` and `include/` directories into your project's source tree.
3. **Add to your build.** Add the copied `.c` files to your project's build system (e.g., Makefile, IDE project) and add the `include` path to your compiler's include directories.
4. **Use the module** in your application.

    ```c
    #include "embeddsp/iir.h"

    // Define a 4th-order filter (2 biquad sections)
    #define NUM_SECTIONS 2

    // User allocates memory for the filter instance, coeffs, and state
    EmbedDSP_IIR_t my_iir_filter;
    EmbedDSP_IIR_BiquadCoeffs_t my_coeffs[NUM_SECTIONS];
    EmbedDSP_IIR_BiquadState_t  my_state[NUM_SECTIONS];

    void main(void) {
        // ... load coefficients into my_coeffs ...

        // Initialize the filter
        EmbedDSP_IIR_Init(&my_iir_filter, NUM_SECTIONS, my_coeffs, my_state);

        // Process audio samples in a loop
        while(1) {
            float input_sample = get_audio_sample();
            float output_sample = EmbedDSP_IIR_Process(&my_iir_filter, input_sample);
            send_audio_sample(output_sample);
        }
    }
    ```

5. For complete projects demonstrating how to use the modules, please see the `/examples` directory.

## Contributing

Contributions are what make the open-source community an amazing place to learn, inspire, and create. If you have ideas for new algorithms, improvements, or bug fixes, please see the [CONTRIBUTING.md](CONTRIBUTING.md) file for guidelines.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- To the pioneers of digital signal processing whose work laid the foundation for modern embedded audio and control.
- To the open-source community for building the tools and sharing the knowledge that make projects like this possible.
