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
    utils
    check/check.c
    klib/int64.c
)
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
target_link_libraries(utils PRIVATE platform)


