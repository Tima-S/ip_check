cmake_minimum_required(VERSION 3.8)
project(ip_check_lib_tests VERSION 1.1.1)

add_subdirectory(3rd-party/googletest)

set (TEST_SOURCES "src/tests.cpp")

add_executable(ip_check_lib_tests ${TEST_SOURCES})

target_include_directories(ip_check_lib_tests
    PRIVATE "3rd-party/googletest/googletest/include"
    PRIVATE "../src/"
)

target_link_libraries(ip_check_lib_tests
    gtest
    gtest_main
    ip_check_lib
)

