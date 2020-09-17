cmake_minimum_required(VERSION 3.0)
project(multiplication_table CXX)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
    INTERFACE
    "include")