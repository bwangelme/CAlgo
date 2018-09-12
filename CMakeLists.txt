cmake_minimum_required(VERSION 3.9)
project(CAlgo CXX)

set(CMAKE_CXX_STANDARD 11)
set(gtest_SOURCE_DIR "ext/googletest-release-1.8.1/")
add_subdirectory(${gtest_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
link_directories(${gtest_SOURCE_DIR})

add_executable(CAlgo main.cpp
        HashTable/hash_table.h
        HashTable/hash_table.cpp
        HashTable/hash_table_unittest.cpp
        TestSample/sample1.cpp
        TestSample/sample1.h
        TestSample/sample1_unittest.cpp
        HashTable/utils.cpp
        HashTable/utils_unittest.cpp
        TestSample/sample2.cpp
        TestSample/sample2.h
        TestSample/sample2_unittest.cpp
        HashTable/hash_quad.cpp
        HashTable/hash_quad.h
        HashTable/hash_quad_unittest.cpp HashTable/utils.h)

target_link_libraries(CAlgo gtest pthread)
