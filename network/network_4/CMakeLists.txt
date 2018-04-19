cmake_minimum_required(VERSION 3.10)
project(network_4 C)

set(CMAKE_C_STANDARD 99)

add_executable(udp_select udp_select.c)
add_executable(tcp_select tcp_select.c)
add_executable(epoll epoll.c)
