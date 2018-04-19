cmake_minimum_required(VERSION 3.10)
project(process_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(thread_cond thread_cond.c)
add_executable(pipe pipe.c)
add_executable(mkfifo_write mkfifo_write.c)
add_executable(mkfifo_read mkfifo_read.c)
add_executable(sigset sigset.c)
add_executable(mykill mykill.c)




find_package(Threads REQUIRED)
target_link_libraries(thread_cond Threads::Threads)