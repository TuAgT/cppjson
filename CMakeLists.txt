cmake_minimum_required(VERSION 3.0...4.1)
project(myJson)

set(CMAKE_CXX_STANDARD 20)

add_executable(myJson main.cpp
        src/json.h
        src/json.cpp
        )

add_subdirectory(test)
