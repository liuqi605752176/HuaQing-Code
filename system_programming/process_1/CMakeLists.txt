cmake_minimum_required(VERSION 3.10)
project(process_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(getpid getpid.c)
add_executable(fork fork.c)
add_executable(exec exec.c)
add_executable(wait wait.c)
add_executable(waitpid waitpid.c)
add_executable(exit exit.c)

