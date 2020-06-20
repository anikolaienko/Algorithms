cmake_minimum_required(VERSION 3.8)

set(This AlgorithmsTests)

set(Sources
    permutation/permutate_string_tests.cc
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    permutate
)

add_test(
    NAME ${This}
    COMMAND ${This}
)