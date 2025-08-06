#=============================================================================
# EmbedDSP Project CMakeLists.txt
#
# NOTE: This CMake setup is for library development, running examples, and
#       building tests.
#
# For end-users, this library is intended to be used by directly including
# the source (.c) and header (.h) files in their target MCU project.
#=============================================================================

# 1. Project Preamble
#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.14)

project(EmbedDSP
    VERSION 0.1.0
    DESCRIPTION "A lightweight C library of DSP algorithms for embedded systems"
    LANGUAGES C)

# Set the C standard to C99 for portability.
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

#=============================================================================
# 2. Options
#=============================================================================
option(EMBEDDSP_BUILD_EXAMPLES "Build the example applications" ON)
option(EMBEDDSP_BUILD_TESTS "Build the unit tests" ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose build type: Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()

#=============================================================================
# 3. Library Target
#=============================================================================

file(GLOB LIB_SOURCES "src/*.c")

# Add the library target. This allows us to link against it in our tests
# and examples here in this repository.
add_library(embeddsp STATIC ${LIB_SOURCES})
add_library(EmbedDSP::embeddsp ALIAS embeddsp)

# The public include directory. Needed for our own examples and tests.
target_include_directories(embeddsp
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set compiler warnings for internal development
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(embeddsp PRIVATE -Wall -Wextra -Wpedantic)
endif()

#=============================================================================
# 4. Subdirectories (for development)
#=============================================================================

if(EMBEDDSP_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
