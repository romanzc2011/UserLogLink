cmake_minimum_required(VERSION 3.23)

project(UserNodeLink LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(UUID REQUIRED IMPORTED_TARGET uuid)

add_executable(UserNodeLink)

target_sources(UserNodeLink
    PRIVATE
        main.c
        user_node_link.c

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES include/user_node_link.h
)

target_link_libraries(UserNodeLink
    PRIVATE
        PkgConfig::UUID
)

target_compile_options(UserNodeLink PRIVATE -g -O0)