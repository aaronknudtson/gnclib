cmake_minimum_required(VERSION 3.19)

project(Gnc_Ex VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_subdirectory(src/main/gnclib)

enable_testing()
add_subdirectory(src/test/gnclib)
