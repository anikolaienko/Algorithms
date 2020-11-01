cmake_minimum_required(VERSION 3.8)

set(This Misc)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    tictactoe.hh
)

set(Sources
    tictactoe.cc
)

add_library(misc SHARED ${Sources})

install(TARGETS misc DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/lib")
install(FILES ${Headers} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/include")
