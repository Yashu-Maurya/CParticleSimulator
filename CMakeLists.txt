# Use a modern CMake version
cmake_minimum_required(VERSION 4.0)


project(ParticleSimulator LANGUAGES C)


set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SOURCES "src/*.c")

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/include")

# for mac
set(CMAKE_PREFIX_PATH /opt/homebrew)


include(FetchContent)


FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG        5.5 
)


FetchContent_MakeAvailable(raylib)

# find_package(raylib REQUIRED)
add_executable(ParticleSimulator ${SOURCES})

target_include_directories(ParticleSimulator PUBLIC ${INCLUDE_DIR})

target_link_libraries(ParticleSimulator PUBLIC raylib)

message(STATUS "Configured project: ${PROJECT_NAME}")
message(STATUS "Executable will be: ParticleSimulator")
