cmake_minimum_required (VERSION 3.1)
project(LargestSubsequence LANGUAGES CXX)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET(COVERAGE OFF CACHE BOOL "Coverage")

# sources file
set(SOURCES Miglior_sequenza.cpp)
add_executable(BestSequence ${SOURCES})
target_compile_options(BestSequence PUBLIC -std=c++11 -g -O0 -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
set_target_properties(BestSequence
    PROPERTIES
    COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
    LINK_FLAGS    "-lgcov --coverage"
)
