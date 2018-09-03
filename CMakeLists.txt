cmake_minimum_required(VERSION 3.9)
project(CAlgo CXX)

set(CMAKE_CXX_STANDARD 11)
set(gtest_SOURCE_DIR "ext/googletest/")
add_subdirectory(${gtest_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
link_directories(${gtest_SOURCE_DIR})

add_executable(CAlgo main.cpp
        HashTable/hash_table.h
        HashTable/hash_table.cpp
        unittest_sample/intro.cpp
        unittest_sample/intro.h
        unittest_sample/intro_check.cpp)

target_link_libraries(CAlgo gtest pthread)
