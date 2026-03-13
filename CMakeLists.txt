cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 23)

# Sets the minimum deployment target
# macOS 10.11 is the minimum required by JUCE
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE STRING "" FORCE)
# Builds a binary that works on Apple Silicon (arm64) and Intel-based Macs
set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "" FORCE)

project(WVFLDR VERSION 0.0.1)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)


add_subdirectory(modules/JUCE)
add_subdirectory(src)

