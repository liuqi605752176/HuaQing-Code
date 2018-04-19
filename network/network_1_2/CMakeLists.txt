cmake_minimum_required(VERSION 3.10)
project(network C)

set(CMAKE_C_STANDARD 11)
include_directories(/home/liuqi/Documents/person)


add_executable(htnos htons.c)
add_executable(inet_addr inet_addr.c)

add_executable(udp_client udp_client.c)
add_executable(udp_server udp_server.c)

add_executable(client client.c)
add_executable(server server.c)

add_executable(tcp_server tcp_server.c)
add_executable(tcp_client tcp_client.c)

add_executable(tcp_fork tcp_fork.c)

add_executable(ftp_tcp_client ftp_tcp_client.c)
add_executable(ftp_tcp_server ftp_tcp_server.c)