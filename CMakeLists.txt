cmake_minimum_required(VERSION 3.23)

project(UserLogLink LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_check_modules(UUID REQUIRED IMPORTED_TARGET uuid)

add_executable(UserLogLink)

target_sources(UserLogLink
    PRIVATE
        main.c
        user_log_link.c

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS include
        FILES include/user_log_link.h
)

target_link_libraries(UserLogLink
    PRIVATE
        PkgConfig::UUID
)

target_compile_options(UserLogLink PRIVATE -g -O0)