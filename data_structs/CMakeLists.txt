cmake_minimum_required(VERSION 3.8)

set(This DataStructs)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    queue.hh
    queue_as_stack.hh
    stack.hh
    stack3_as_vector1.hh
    vector.hh
)

set(Sources
    queue.cc
    queue_as_stack.cc
    stack.cc
    stack3_as_vector1.cc
    vector.cc
)

add_library(datastructs SHARED ${Sources})

install(TARGETS datastructs DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/lib")
install(FILES ${Headers} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/include")
