# This CMakeLists.txt builds a single executable named 'run_tests'
# that contains all the unit tests for the EmbedDSP library.

# Find all test source files in the current directory, including the
# Unity framework source file.
file(GLOB TEST_SOURCES
    "*.c"
    "vendor/Unity/src/unity.c"
)

# Define the test executable target.
add_executable(run_tests ${TEST_SOURCES})

# Add the path to the Unity headers to our include path so we can #include "unity.h"
target_include_directories(run_tests
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/vendor/Unity/src"
)

# Link the test executable against our main 'embeddsp' library.
# This is crucial as it makes all the functions from src/ available to our tests.
# The 'EmbedDSP::embeddsp' is a modern CMake alias defined in the root CMakeLists.txt.
target_link_libraries(run_tests PRIVATE EmbedDSP::embeddsp)

# Register the executable with CTest.
# This allows us to run all tests simply by calling `ctest` or `make test`
# from the build directory.
add_test(
    NAME EmbedDSP_Unit_Tests  # A descriptive name for the test suite in CTest
    COMMAND run_tests         # The command to run is our executable
)
