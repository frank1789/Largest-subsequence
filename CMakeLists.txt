cmake_minimum_required(VERSION 3.10)
project(LargestSubsequence CXX)

SET(COVERAGE OFF CACHE BOOL "Coverage")


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_REQUIRED_FLAGS -std=c++11)



add_executable(BestSequence Miglior_sequenza.cpp)

if (COVERAGE)
        target_compile_options(BestSequence --coverage)
endif()
