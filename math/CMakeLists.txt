cmake_minimum_required(VERSION 3.8)

set(This Math)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(Headers
    factorial.hh
)

set(Sources
   factorial.cc
)

add_library(math SHARED ${Sources})

install(TARGETS math DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/lib")
install(FILES ${Headers} DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/include")
