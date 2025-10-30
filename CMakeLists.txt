# Use a modern CMake version
cmake_minimum_required(VERSION 4.0)

project(ParticleSimulator LANGUAGES C OBJC)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.c")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/include")

# for mac
set(CMAKE_PREFIX_PATH /opt/homebrew)

# --- Removed FetchContent commands ---
# We no longer need FetchContent, GIT_PROGRESS, or FETCHCONTENT_QUIET

# Add the raylib subdirectory
# This path must match where you cloned the submodule
add_subdirectory(external/raylib)

# --- No changes below this line ---
add_executable(ParticleSimulator ${SOURCES})

target_include_directories(ParticleSimulator PUBLIC ${INCLUDE_DIR})

# This works because add_subdirectory() makes the "raylib" target available
target_link_libraries(ParticleSimulator PUBLIC raylib)

message(STATUS "Configured project: ${PROJECT_NAME}")
message(STATUS "Executable will be: ParticleSimulator")