cmake_minimum_required(VERSION 3.8)

set(This AlgorithmsTests)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_FIND_LIBRARY_PREFIXES lib)
SET(CMAKE_FIND_LIBRARY_SUFFIXES .so .dylib)

set(Sources
    data_structs/stack3_as_vector1_tests.cc
    data_structs/queue_as_stack_tests.cc
    data_structs/stack_tests.cc
    data_structs/queue_tests.cc
    data_structs/vector_tests.cc
    data_structs/weighted_edge_tests.cc
    data_structs/graph_tests.cc
    
    bitwise/bitwise_tests.cc
    bitwise/swap_two_numbers_tests.cc
    
    permutation/permutate_string_tests.cc
    
    convertion/to_bit_string_tests.cc

    geometry/segments_intersection_tests.cc

    math/factorial_trailing_zeros_tests.cc 

    search/word_counter_simple_tests.cc
)

add_executable(${This} ${Sources})

find_library(MathLib math "${PROJECT_SOURCE_DIR}/math/lib" NO_DEFAULT_PATH)
find_library(DataStructsLib datastructs "${PROJECT_SOURCE_DIR}/data_structs/lib" NO_DEFAULT_PATH)
find_library(SearchLib search "${PROJECT_SOURCE_DIR}/search/lib" NO_DEFAULT_PATH)

target_link_libraries(${This} PUBLIC
    gtest_main
    ${MathLib}
    ${DataStructsLib}
    ${SearchLib}
)

add_test(
    NAME ${This}
    COMMAND ${This}
)