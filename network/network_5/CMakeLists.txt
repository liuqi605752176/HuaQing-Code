cmake_minimum_required(VERSION 3.10)
project(network_5 C)

set(CMAKE_C_STANDARD 99)




add_executable(client client.c my_dict.h)
add_executable(server server.c my_dict.h)

