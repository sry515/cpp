cmake_minimum_required(VERSION 3.22)
project(cpp_workspace)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_workspace main.cpp cpp_server/tcp_client.c cpp_server/tcp_client.c cpp_server/tcp_client.c cpp_server/tcp_server.c operator_linux_file/write_file.c operator_linux_file/read_file.c operator_linux_file/fd_seri.c)
