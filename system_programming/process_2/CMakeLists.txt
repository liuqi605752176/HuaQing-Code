cmake_minimum_required(VERSION 3.10)
project(process_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(daemon daemon.c)
add_executable(pthread pthread.c)
add_executable(sem sem.c)
add_executable(pthread_mutex pthread_mutex.c)
add_executable(main_thread main_thread.c)
add_executable(thread_exit thread_exit.c)
add_executable(thread_join thread_join.c)
add_executable(thread_cancel thread_cancel.c)
add_executable(thread_kill thread_kill.c)
add_executable(mutex mutex.c)



find_package(Threads REQUIRED)
target_link_libraries(thread_join Threads::Threads)