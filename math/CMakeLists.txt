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

SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS math DESTINATION lib)
install(FILES ${Headers} DESTINATION include)
