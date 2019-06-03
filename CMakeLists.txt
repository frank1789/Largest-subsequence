cmake_minimum_required(VERSION 3.10)
project(LargestSubsequence CXX)

SET(COVERAGE OFF CACHE BOOL "Coverage")


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_REQUIRED_FLAGS -std=c++11)



add_executable(BestSequence Miglior_sequenza.cpp)
target_compile_options(BestSequence PUBLIC -std=c++11 -g -O0 -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)


if (COVERAGE)
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    # Coverage can only be set if -g is used.
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    target_compile_options(BestSequence PRIVATE --coverage)
    target_link_libraries(BestSequence PRIVATE --coverage)
endif()
