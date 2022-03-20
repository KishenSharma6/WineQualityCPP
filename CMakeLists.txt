cmake_minimum_required(VERSION 3.0.0)
project(Wine VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(headers)
link_directories("/opt/homebrew/lib")
include_directories("/opt/homebrew/include")

set(SOURCES src/main.cpp
            src/etl.cpp
            headers/etl.h
            src/linearRegression.cpp
            headers/linearRegression.h
            /opt/homebrew/include/boost/algorithm/string.hpp)

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_executable(wine ${SOURCES})


