add_library(
    gnclib
    Physics.cpp
    Solver.cpp
    PhysicsTwoBody.cpp
    PhysicsTwoBodyDrag.cpp
)

target_include_directories(gnclib PUBLIC "${PROJECT_SOURCE_DIR}/include")
