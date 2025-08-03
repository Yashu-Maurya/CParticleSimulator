# Use a modern CMake version
cmake_minimum_required(VERSION 3.15)

# Define the project name and specify its language is C
project(ParticleSimulator LANGUAGES C)

# Set the C language standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# --- Automatic Source File Detection ---
# Find all .c files within the 'src' directory and store them in the SOURCES variable
file(GLOB_RECURSE SOURCES "src/*.c")

# --- Header File Configuration ---
# Add the 'src/include' directory to the list of places to search for header files
# This lets you use #include "my_header.h"
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/include")

# --- Raylib Library Configuration ---
# Tell CMake where to find Homebrew packages (for Apple Silicon Macs)
set(CMAKE_PREFIX_PATH /opt/homebrew)

# Find the Raylib package. The "REQUIRED" keyword will cause an error if it's not found.
find_package(raylib REQUIRED)

# --- Executable and Linking ---
# Create an executable named "ParticleSimulator" from the source files found earlier
add_executable(ParticleSimulator ${SOURCES})

# Add the header directory to your project's include path
target_include_directories(ParticleSimulator PUBLIC ${INCLUDE_DIR})

# Link the Raylib library to your project
target_link_libraries(ParticleSimulator PUBLIC raylib)

# A message to confirm the project and executable name
message(STATUS "Configured project: ${PROJECT_NAME}")
message(STATUS "Executable will be: ParticleSimulator")