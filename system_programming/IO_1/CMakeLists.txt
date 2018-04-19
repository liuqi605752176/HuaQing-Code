cmake_minimum_required(VERSION 3.10)
project(process_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(open open.c)
add_executable(cp cp.c)
add_executable(fopen fopen.c)