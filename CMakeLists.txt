cmake_minimum_required(VERSION 3.19)

project(Gnc_Ex VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_subdirectory(external/eigen)
add_subdirectory(src/main/gnclib)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(gnclib Eigen3::Eigen)

enable_testing()
add_subdirectory(src/test/gnclib)
