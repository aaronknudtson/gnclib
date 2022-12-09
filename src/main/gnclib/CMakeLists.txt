add_library(
    gnclib
    Physics.cpp
    Solver.cpp
)

target_include_directories(gnclib PUBLIC "${PROJECT_SOURCE_DIR}/include")
