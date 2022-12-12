add_executable(
    gnclib_test 
    gnclib_test.cpp
)
target_link_libraries(
    gnclib_test 
    PRIVATE
    GTest::gtest_main
    gnclib
)
target_include_directories(gnclib_test PUBLIC "${PROJECT_SOURCE_DIR}/include")

include(GoogleTest)
gtest_discover_tests(gnclib_test)
