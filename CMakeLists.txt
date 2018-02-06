cmake_minimum_required(VERSION 3.9)
project(Test2 C)

set(CMAKE_C_STANDARD 99)

add_executable(test-sll  src/sll.h src/sll.c src/test-sll.c src/integer.c src/integer.h)

add_executable(test-dll src/dll.c src/dll.h src/test-dll.c src/integer.c src/integer.h)

add_executable(test-stack src/dll.c src/dll.h src/stack.c src/stack.h src/test-stack.c src/integer.c src/integer.h)

add_executable(test-queue src/sll.h src/sll.c  src/queue.c src/queue.h src/test-queue.c src/integer.c src/integer.h )