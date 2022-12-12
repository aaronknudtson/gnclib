cmake_minimum_required(VERSION 3.19)

project(Gnc_Ex VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# config for gtest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(external/eigen)
add_subdirectory(external/pybind11)
add_subdirectory(src/main/gnclib)
add_subdirectory(src/main/pygnc)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
target_link_libraries(gnclib Eigen3::Eigen)
target_link_libraries(pygnc PRIVATE gnclib Eigen3::Eigen)

# test
enable_testing()
add_subdirectory(src/test/gnclib)
