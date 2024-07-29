cmake_minimum_required(VERSION 3.29)

project(abstract-machine LANGUAGES CXX C ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ISA riscv)
set(TARGET cpu-test/dummy)
set(PLATFORM nemu)

if (ISA STREQUAL riscv)
    include(cmake/toolchain/riscv.cmake)
    add_definitions(-DISA_RISC_V)
endif()

add_subdirectory(src)
