cmake_minimum_required(VERSION 3.8)

set(This AlgorithmsTests)

SET(CMAKE_FIND_LIBRARY_PREFIXES lib)
SET(CMAKE_FIND_LIBRARY_SUFFIXES .so .dylib)
# SET(CMAKE_VERBOSE_MAKEFILE ON)

set(Sources
    # data_structs/stack3_as_vector1_tests.cc
    # data_structs/queue_as_stack_tests.cc
    data_structs/stack_tests.cc
    data_structs/queue_tests.cc
    data_structs/vector_tests.cc
    data_structs/weighted_edge_tests.cc
    bitwise/bitwise_tests.cc
    permutation/permutate_string_tests.cc
)

add_executable(${This} ${Sources})

find_library(MathLib math "math/lib" NO_DEFAULT_PATH)
find_library(DataStructsLib datastructs "data_structs/lib" NO_DEFAULT_PATH)

target_link_libraries(${This} PUBLIC
    gtest_main
    ${MathLib}
    ${DataStructsLib}
)

add_test(
    NAME ${This}
    COMMAND ${This}
)