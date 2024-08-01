set(
    CPU_TEST_TARGET_LIST
    ./pascal.c
    ./bit.c
    ./matrix-mul.c
    ./mov-c.c
    ./add.c
    ./crc32.c
    ./fact.c
    ./div.c
    ./wanshu.c
    ./to-lower-case.c
    ./leap-year.c
    # ./hello-str.c
    ./load-store.c
    ./unalign.c
    ./recursion.c
    ./shuixianhua.c
    ./sum.c
    ./min3.c
    ./movsx.c
    ./sub-longlong.c
    ./quick-sort.c
    ./dummy.c
    ./add-longlong.c
    ./mersenne.c
    ./mul-longlong.c
    ./shift.c
    ./goldbach.c
    ./select-sort.c
    ./switch.c
    ./fib.c
    # ./string.c
    ./if-else.c
    ./max.c
    ./prime.c
    ./bubble-sort.c
)

foreach(target ${CPU_TEST_TARGET_LIST})
    get_filename_component(target_name ${target} NAME_WE)
    add_executable(
        ${target_name}
        ${target}
    )
    target_link_libraries(${target_name} PRIVATE check platform ISA)
    add_custom_command(
        TARGET ${target_name} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -S --set-section-flags .bss=alloc,contents -O binary ${target_name}.elf ${target_name}.bin
        COMMAND ${CMAKE_OBJCOPY} -S --set-section-flags .bss=alloc,contents -O ihex ${target_name}.elf ${target_name}.hex
        COMMAND ${CMAKE_OBJDUMP} -D ${target_name}.elf > ${target_name}.dump
        COMMAND ${CMAKE_SIZE} ${target_name}.elf
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Convert to binary and hex"
    )
endforeach(target ${CPU_TEST_TARGET_LIST})
