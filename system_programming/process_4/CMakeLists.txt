cmake_minimum_required(VERSION 3.10)
project(process_4 C)

set(CMAKE_C_STANDARD 11)
include_directories(/home/liuqi/Documents/person)


add_executable(msg msg.c)
add_executable(msg_send msg_send.c)
add_executable(msg_rcv msg_rcv.c)
add_executable(shm_send shm_send.c)
add_executable(shm_rcv shm_rcv.c)
add_executable(shmat_rcv shmat_rcv.c)
add_executable(shmat_snd shmat_snd.c)
add_executable(shm shm.c)


