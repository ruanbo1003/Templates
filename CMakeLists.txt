cmake_minimum_required(VERSION 3.21)
project(Templates)

set(CMAKE_CXX_STANDARD 20)
include_directories("./src")

add_executable(Templates src/main.cpp src/basics/function_templates.cpp src/main.h src/basics/multiple_template_parameters.cpp src/basics/head.h)
