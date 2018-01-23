cmake_minimum_required(VERSION 3.9)
project(Test2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Test2 main.c sll.h sll.c)