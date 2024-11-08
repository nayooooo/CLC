cmake_minimum_required(VERSION 3.10.0)
project(test01 VERSION 1.0.0
        DESCRIPTION "test"
        LANGUAGES "C")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_CLC_LIST ${PROJECT_SOURCE_DIR}/../*.c)
file(GLOB SRC_TEST_LIST test01.c)
set(SRC "")
list(APPEND SRC ${SRC_CLC_LIST})
list(APPEND SRC ${SRC_TEST_LIST})
include_directories(${PROJECT_SOURCE_DIR}/..)

add_executable(${PROJECT_NAME} ${SRC})
