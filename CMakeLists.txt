cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

project(Laba_005 VERSION 0.1.0)

find_package(GTest CONFIG REQUIRED)

add_library(${PROJECT_NAME} STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include/header.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/functions.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests.cpp
)


if(BUILD_TESTS)
    add_executable(tests
        include/header.hpp
        src/functions.cpp
        tests/tests.cpp
    )
    enable_testing()
    target_link_libraries(tests ${PROJECT_NAME} GTest::gtest_main)
    add_test(NAME unit_tests COMMAND tests)
endif()