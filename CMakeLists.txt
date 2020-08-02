cmake_minimum_required(VERSION 3.8)

set(This Algorithms)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

enable_testing()

include_directories(math/include)
include_directories(data_structs/include)

add_subdirectory(googletest)
add_subdirectory(data_structs)
add_subdirectory(math)
add_subdirectory(test)

set(ExName permutate)
set(ExSources
    permutation/permutate_string.cc
)
add_library(${ExName} STATIC ${ExSources})

# find_library(MathLib math "${PROJECT_SOURCE_DIR}/math/lib" NO_DEFAULT_PATH)
# target_link_libraries(${ExName} ${MathLib})