cmake_minimum_required(VERSION 3.23)

project(LinkedList LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(UUID REQUIRED IMPORTED_TARGET uuid)

add_executable(LinkedList)

target_sources(LinkedList
    PRIVATE
        main.c
        linked_list.c

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES include/linked_list.h
)

target_link_libraries(LinkedList
    PRIVATE
        PkgConfig::UUID
)

target_compile_options(LinkedList PRIVATE -g -O0)