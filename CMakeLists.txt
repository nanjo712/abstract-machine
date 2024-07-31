cmake_minimum_required(VERSION 3.29)

project(abstract-machine LANGUAGES CXX C ASM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# cache variable ISA
set(ISA riscv CACHE STRING "Instruction Set Architecture")
set(TARGET cpu-test/dummy CACHE STRING "Target")
set(PLATFORM nemu CACHE STRING "Platform")

if (ISA STREQUAL riscv)
    include(cmake/toolchain/riscv.cmake)
    add_definitions(-DISA_RISC_V)
endif()

add_subdirectory(src)
