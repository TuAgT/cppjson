# 编译静态库
add_library(json STATIC json.cpp)

#
include_directories(PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(myJson main.cpp
        json.h
        json.cpp
)