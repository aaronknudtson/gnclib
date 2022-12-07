add_library(
    gnclib
    OrbitSim.cpp
)

target_include_directories(gnclib PUBLIC "${PROJECT_SOURCE_DIR}/include")
