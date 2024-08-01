add_library(
    platform
    platform/${PLATFORM}/trm/trm.c
)

add_library(
    ISA
    ISA/${ISA}/start.S
)
target_link_libraries(ISA PRIVATE platform)
target_link_options(ISA PRIVATE ${CMAKE_C_LINK_FLAGS})

add_library(
    check
    check/check.c
)
target_include_directories(check PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(check PRIVATE platform)

add_subdirectory(target)


