cmake_minimum_required(VERSION 3.10)
project(System_INTO)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Binary)

add_executable(System_INTO
    ${CMAKE_SOURCE_DIR}/Core/Primary_Core/cpp_primary_core_0_1.cpp
)

target_include_directories(System_INTO PRIVATE
    ${CMAKE_SOURCE_DIR}/Toolbox
)