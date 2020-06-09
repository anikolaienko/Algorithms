cmake_minimum_required(VERSION 3.8)

set(This Algorithms)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# add_subdirectory(googletest)

set(Headers
    math/factorial.hh
)

set(Sources
    math/factorial.cc
)

include_directories(math/include)

add_library(${This} STATIC ${Sources} ${Headers})

set(ExName Permutations)

set(ExSources
    permutation/permutate_string.cc
)

add_executable(${ExName} ${ExSources})