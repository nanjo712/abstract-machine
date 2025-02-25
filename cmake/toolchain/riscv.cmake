# RISC-V Tool Chain Settings
set(CMAKE_SYSTEM_NAME               Generic)
set(CMAKE_SYSTEM_PROCESSOR          riscv32)

set(COMPILER_PREFIX    riscv64-unknown-elf)

# Specify the toolchain
set(CMAKE_C_COMPILER   ${COMPILER_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${COMPILER_PREFIX}-g++)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_AR           ${COMPILER_PREFIX}-ar)
set(CMAKE_OBJCOPY      ${COMPILER_PREFIX}-objcopy)
set(CMAKE_OBJDUMP      ${COMPILER_PREFIX}-objdump)
set(CMAKE_LINKER       ${COMPILER_PREFIX}-ld)
set(CMAKE_SIZE         ${COMPILER_PREFIX}-size)

# newlib settings
include_directories(/usr/local/riscv64-unknown-elf/include)
link_directories(/usr/local/riscv64-unknown-elf/lib/rv32im/ilp32)      

set(CMAKE_EXECUTABLE_SUFFIX_ASM  ".elf")    
set(CMAKE_EXECUTABLE_SUFFIX_C    ".elf")
set(CMAKE_EXECUTABLE_SUFFIX_CXX  ".elf")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# SoC settings
set(SOC_FLAGS "-march=rv32im -mabi=ilp32")

# Language settings 
set(CMAKE_ASM_FLAGS "${SOC_FLAGS} -fno-pic -O2")
set(CMAKE_C_FLAGS   "${SOC_FLAGS} -O2 -static -Wall -Werror -mcmodel=medany -mstrict-align")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -fno-pic -fno-builtin -fno-stack-protector -Wno-main -U_FORTIFY_SOURCE")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -fvisibility=hidden -fno-asynchronous-unwind-tables")
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -fdata-sections -ffunction-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -ffreestanding -fno-rtti -fno-exceptions -fno-threadsafe-statics ")  

# Linker settings
set(CMAKE_C_LINK_FLAGS    "-Wl,-T${CMAKE_CURRENT_SOURCE_DIR}/linker.ld -Wl,--defsym=_pmem_start=0x80000000 -Wl,--defsym=_entry_offset=0x0")
set(CMAKE_C_LINK_FLAGS    "${CMAKE_C_LINK_FLAGS} -Wl,-e _start -Wl,-build-id=none")
set(CMAKE_C_LINK_FLAGS    "${CMAKE_C_LINK_FLAGS} -nostartfiles -Wl,--gc-sections")
set(CMAKE_C_LINK_FLAGS    "${CMAKE_C_LINK_FLAGS} -Wl,-melf32lriscv")    
set(CMAKE_CXX_LINK_FLAGS  "${CMAKE_C_LINK_FLAGS} ")




