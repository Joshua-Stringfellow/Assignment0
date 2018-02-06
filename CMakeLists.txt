cmake_minimum_required(VERSION 3.9)
project(Test2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Test2 src/main.c src/sll.h src/sll.c src/dll.c src/dll.h src/test-dll.c src/test-sll.c)