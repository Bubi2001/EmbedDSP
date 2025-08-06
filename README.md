# EmbedDSP 🎼

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C/C++ CI](https://github.com/Bubi2001/EmbedDSP/actions/workflows/ci.yml/badge.svg)](https://github.com/Bubi2001/EmbedDSP/actions/workflows/ci.yml)

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

| Module             | Status     | Description                                                |
| :----------------- | :--------: | :----------------------------------------------------------------- |
| **FIR Filter**     | 🟡 In Progress | A generic, Nth-order Finite Impulse Response filter.           |
| **IIR Filter**     | 🟡 In Progress | A generic, cascaded biquad Infinite Impulse Response filter.   |
| **PID Controller** | ❌ Planned   | A Proportional-Integral-Derivative controller with anti-windup, derivative on measurement and a low-pass filter on the derivative path. |
| **FFT**            | ❌ Planned   | A Fast Fourier Transform algorithm for spectral analysis.       |

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
