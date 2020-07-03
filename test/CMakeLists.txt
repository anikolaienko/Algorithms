cmake_minimum_required(VERSION 3.8)

set(This AlgorithmsTests)

set(Sources
    # data_structs/stack3_as_vector1_tests.cc
    # data_structs/queue_as_stack_tests.cc
    data_structs/stack_tests.cc
    # bitwise/bitwise_tests.cc
    # TODO: uncomment permutation/permutate_string_tests.cc
)

add_executable(${This} ${Sources})
find_library(DataStructs datastructs "data_structs/lib")
target_link_libraries(${This} PUBLIC
    gtest_main
    ${DataStructs}
)

add_test(
    NAME ${This}
    COMMAND ${This}
)