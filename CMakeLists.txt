# CMakeList.txt : CMake project for simulation-platform, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.20)

project ("simulation-platform")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Add source to this project's executable.
add_executable (simulation-platform "src/simulation-platform.cpp" "src/simulation-platform.h")

#Add GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET simulation-platform PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

enable_testing()
add_subdirectory(tests)