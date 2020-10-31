cmake_minimum_required(VERSION 3.8)

set(This Search)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    word_counter.hh
    word_counter_simple.hh
    word_counter_cached.hh
)

set(Sources
    word_counter_simple.cc
    word_counter_cached.cc
)

add_library(search SHARED ${Sources})

install(TARGETS search DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/lib")
install(FILES ${Headers} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/include")
