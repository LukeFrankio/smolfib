cmake_minimum_required(VERSION 3.15)
project(fib_minimal LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(fib src/main.cpp)

# Header-only fib library (inline in include/fib.h)
add_library(fiblib INTERFACE)
target_include_directories(fiblib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(fib_big src/fib_big.cpp)
target_link_libraries(fib_big PRIVATE fiblib)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
add_executable(fib_tests tests/fib_tests.cpp)
target_link_libraries(fib_tests PRIVATE fiblib GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(fib_tests)
