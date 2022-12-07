add_executable(
    GncLibTests
    GncLibTests-main.cpp
)
target_link_libraries(GncLibTests PRIVATE gnclib)
target_include_directories(GncLibTests PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_test(NAME GncLib COMMAND GncLibTests)
