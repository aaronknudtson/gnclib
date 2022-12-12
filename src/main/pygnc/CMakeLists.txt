pybind11_add_module(pygnc Bindings.cpp)
target_include_directories(pygnc PUBLIC "${PROJECT_SOURCE_DIR}/include")
