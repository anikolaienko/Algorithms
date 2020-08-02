cmake_minimum_required(VERSION 3.8)

set(This Algorithms)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# set(CMAKE_VERBOSE_MAKEFILE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(data_structs)
add_subdirectory(math)

include_directories(math/include)
include_directories(data_structs/include)

set(ExName permutate)
set(ExSources
    permutation/permutate_string.cc
)

add_library(${ExName} STATIC ${ExSources})

find_library(MathLib math "math/lib" NO_DEFAULT_PATH)
target_link_libraries(${ExName} ${MathLib})

add_subdirectory(test)
