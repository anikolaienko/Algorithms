cmake_minimum_required(VERSION 3.8)

set(This DataStructs)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    # iterator.hh
    # queue.hh
    # queue_as_stack.hh
    stack.hh
    # stack3_as_vector1.hh
    vector.hh
)

set(Sources
    # iterator.cc
    # queue.cc
    # queue_as_stack.cc
    stack.cc
    # stack3_as_vector1.cc
    vector.cc
)

add_library(DataStructsLib STATIC ${Sources})

SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS DataStructsLib DESTINATION lib)
install(FILES ${Headers} DESTINATION include)
