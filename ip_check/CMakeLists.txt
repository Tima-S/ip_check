cmake_minimum_required(VERSION 3.8)

set(IPCHECK_VERSION_MAJOR 1)
set(IPCHECK_VERSION_MINOR 1)

set(IPCHECK_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})

if(NOT IPCHECK_VERSION_PATCH) 
    set (IPCHECK_VERSION_PATCH 1)
endif()

set(TARGET_NAME ipcheck)
project(${TARGET_NAME} VERSION ${IPCHECK_VERSION_MAJOR}.${IPCHECK_VERSION_MINOR}.${IPCHECK_VERSION_PATCH})

configure_file(src/version.h.in src/version.h)


include(CMakeExtraFunctions.cmake)
custom_add_executable_from_dir(${TARGET_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(lib/ip_check_lib)

target_link_libraries(${TARGET_NAME} ip_check_lib)

set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(${TARGET_NAME}
    PRIVATE "${CMAKE_BINARY_DIR}/src"
    PRIVATE "lib/ip_check_lib/src"
)


