cmake_minimum_required(VERSION 3.0)

project(lib)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_library(lib SHARED lib.cpp)