cmake_minimum_required(VERSION 3.16)

project(summation_exercises)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
add_executable(Sum source/Summation.cpp)
#target_compile_options(Sum PRIVATE -O1)