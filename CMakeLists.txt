cmake_minimum_required(VERSION 3.20)

project(simulation-platform)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



add_library(simulation
    src/Particle.cc
    src/Vector3.cc
    src/ForceCalculator.cc
    src/ParticleSimulation.cc
)

target_include_directories(simulation
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main executable
add_executable(simulation-platform
    src/simulation-platform.cpp
)

target_link_libraries(simulation-platform
    PRIVATE
        simulation
)

# GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
set_target_properties(
    gtest
    gtest_main
    PROPERTIES
        CXX_CLANG_TIDY ""
)
# Tests
enable_testing()
add_subdirectory(tests)