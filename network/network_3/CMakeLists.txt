cmake_minimum_required(VERSION 3.10)
project(network_3 C)

set(CMAKE_C_STANDARD 99)
include_directories(/home/liuqi/Documents/person)


add_executable(ftp_tcp_client ftp_tcp_client.c my_ftp.h)
add_executable(ftp_tcp_server ftp_tcp_server.c my_ftp.h)

