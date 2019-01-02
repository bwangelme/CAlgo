cmake_minimum_required(VERSION 3.9)
project(CAlgo CXX)

set(CMAKE_CXX_STANDARD 11)
set(gtest_SOURCE_DIR "ext/googletest-release-1.8.1/")
add_subdirectory(${gtest_SOURCE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
link_directories(${gtest_SOURCE_DIR})

FILE(GLOB Sources main.cpp HeapStruct/*.cpp HashTable/*.cpp TestSample/*.cpp)
ADD_EXECUTABLE(CAlgo ${Sources})

target_link_libraries(CAlgo gtest pthread)
