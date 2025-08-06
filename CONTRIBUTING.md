# Contributing to EmbedDSP

First off, thank you for considering contributing to `EmbedDSP`! It's people like you that make open source such a great community. Your contributions are valuable and will help make this library better for everyone.

This document provides guidelines for contributing to the project. Please read it to ensure a smooth and effective collaboration process.

## Code of Conduct

This project and everyone participating in it is governed by the [EmbedDSP Code of Conduct](CODE_OF_CONDUCT.md). By participating, you are expected to uphold this code. Please report unacceptable behavior.

## How Can I Contribute?

There are many ways to contribute, from writing code and documentation to reporting bugs and suggesting new features.

### Reporting Bugs

If you find a bug, please ensure it hasn't already been reported by searching the [Issues](https://github.com/Bubi2001/EmbedDSP/issues) on GitHub.

If you can't find an open issue addressing the problem, please [open a new one](https://github.com/Bubi2001/EmbedDSP/issues/new). Be sure to include:

* A **clear and descriptive title** .
* A detailed description of the problem, including the **MCU or platform** you are using, if relevant.
* **Code snippets** or a minimal reproducible example that demonstrates the issue.
* The **expected behavior** and what happened instead.

### Suggesting Enhancements

If you have an idea for a new feature or an improvement to an existing one:

1. Search the [Issues](https://github.com/Bubi2001/EmbedDSP/issues) to see if the enhancement has already been suggested.
2. If not, open a new issue describing your suggestion. Provide as much context as possible, including:
   * A clear description of the proposed enhancement.
   * The motivation behind it. Why would this be useful?
   * A potential implementation approach, if you have one in mind.

### Your First Code Contribution

Unsure where to begin? Look for issues tagged with `good first issue` or `help wanted`. These are tasks that have been identified as good entry points for new contributors.

## Development Workflow

Ready to contribute code? Here’s how to set up your environment and submit your changes.

### 1. Fork the Repository

Click the "Fork" button at the top right of the [EmbedDSP repository page](https://www.google.com/search?q=https://github.com/YourUsername/EmbedDSP "null"). This will create a copy of the repository in your own GitHub account.

### 2. Clone Your Fork

Clone your forked repository to your local machine:

```bash
git clone https://github.com/YourUsername/EmbedDSP.git
cd EmbedDSP
```

### 3. Initialize Submodules

The project uses Git submodules for the testing framework. Make sure to initialize them:

```bash
git submodule update --init --recursive
```

### 4. Create a New Branch

Create a new branch for your changes. Use a descriptive name, like `fix/fir-filter-bug` or `feature/add-kalman-filter`.

```bash
git checkout -b your-branch-name
```

### 5. Make Your Changes

Now, write your code!

* Follow the existing coding style.
* Ensure your code is well-commented, especially public-facing functions in header files.
* If you are adding a new feature, add a corresponding example in the `examples/` directory.
* If you are adding or changing functionality, **you** must add or update the **unit tests** in the `test/` directory.

### 6. Build and Test Your Changes

Before submitting, ensure all tests pass.

```bash
# Create a build directory
cmake -B build

# Build the project
cmake --build build

# Run the tests
cd build
ctest --verbose
```

All tests must pass before a pull request can be merged.

### 7. Commit Your Changes

Commit your changes with a clear and descriptive commit message.

```bash
git add .
git commit -m "feat: Add new biquad IIR filter module"
```

### 8. Push to Your Fork

Push your branch to your forked repository on GitHub:

```bash
git push origin your-branch-name
```

### 9. Submit a Pull Request

Go to your forked repository on GitHub and click the "Compare & pull request" button.

* Provide a clear title and description for your pull request.
* Reference any issues that your pull request resolves (e.g., `Fixes #123`).
* The project's automated CI tests will run. Make sure they all pass.

A project maintainer will review your pull request, provide feedback, and merge it once it's ready.

Coding Style Guide
To maintain a consistent style across the project, please follow these guidelines:

Language: Use standard C99. Avoid compiler-specific extensions.

Naming: Public functions should use PascalCase for logical parts, separated by underscores (e.g., EmbedDSP_FIR_Init()). Local variables should use snake_case.

Braces: Use inline braces (1TBS/K&R style), where the opening brace is on the same line as the statement.

```c
if (some_condition) {
    some_code();
} else {
    some_other_code();
}
```

Indentation: Use 4 spaces for indentation, not tabs.

Comments: Use `//` for single-line comments and `/* ... */` for multi-line comments. Document all public functions in the header files.

Thank you for your contribution!
