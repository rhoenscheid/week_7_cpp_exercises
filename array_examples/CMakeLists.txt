cmake_minimum_required(VERSION 3.16)

project(array_exercises)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
add_executable(structArray source/structs_and_arrays.cpp)
#target_compile_options(structArray PRIVATE -O3)