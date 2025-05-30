cmake_minimum_required(VERSION 3.10)

project(headerviz)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(include)
include_directories(libs)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(hdviz ${SRC_FILES})
