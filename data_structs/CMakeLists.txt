cmake_minimum_required(VERSION 3.8)

set(This DataStructs)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    vector.hh
    stack.hh
    queue.hh
    
    stack3_as_vector1.hh
    queue_as_stack.hh
    
    graph.hh
)

set(Sources
    vector.cc
    stack.cc
    queue.cc
    
    stack3_as_vector1.cc
    queue_as_stack.cc
    
    graph.cc    
)

add_library(datastructs SHARED ${Sources})

install(TARGETS datastructs DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/lib")
install(FILES ${Headers} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/include")
