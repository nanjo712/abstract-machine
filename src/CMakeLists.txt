add_library(
    platform
    platform/${PLATFORM}/trm/trm.c
)

add_library(
    ISA
    ISA/${ISA}/start.S
)
target_link_libraries(ISA PRIVATE platform)

add_library(
    check
    check/check.c
)
target_include_directories(check PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(check PRIVATE platform)

add_executable(
    am_target 
    target/${TARGET}.c 
)
target_link_libraries(am_target PRIVATE check platform ISA)

# convert to binary and hex
add_custom_command(
    TARGET am_target POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary am_target.elf am_target.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex am_target.elf am_target.hex
    COMMAND ${CMAKE_OBJDUMP} -d am_target.elf > am_target.dump
    COMMAND ${CMAKE_SIZE} am_target.elf
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Convert to binary and hex"
)


