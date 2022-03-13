cmake_minimum_required(VERSION 3.0.0)
project(Wine VERSION 0.1.0)

include_directories(headers)

set(SOURCES src/main.cpp
            src/etl.cpp
            headers/etl.h
            /opt/homebrew/Cellar/boost/1.78.0_1/include/boost/algorithm/string.hpp)

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_executable(wine ${SOURCES})


