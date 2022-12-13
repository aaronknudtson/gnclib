add_library(
    gnclib
    Physics.cpp
    Solver.cpp
    PhysicsTwoBody.cpp
    Helpers.cpp
)
set_target_properties(gnclib PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(gnclib PUBLIC "${PROJECT_SOURCE_DIR}/include")
