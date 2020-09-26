cmake_minimum_required(VERSION 3.17)
project(Moebius)

set(CMAKE_CXX_STANDARD 14)

add_library(
        Moebius
        src/exceptions/exceptions.cpp
        src/exceptions/exceptions.h
        src/TCPServer/tcpServer.cpp
        src/TCPServer/tcpServer.h
        src/TCPServer/tcpServerConstants.h
        src/utilities/sockets/sockets.h
        src/utilities/sockets/sockets.cpp
        src/TCPClient/tcpClient.cpp
        src/TCPClient/tcpClient.h
        src/TCPClient/tcpClientConstants.h src/utilities/message/message.cpp src/utilities/message/message.h)

add_executable(
        run_tcp_server
        src/run/RunTCPServer.cpp
)

add_executable(
        run_tcp_client
        src/run/RunTCPClient.cpp
)

add_executable(
        run_multiple_tcp_clients
        src/run/RunMultipleTCPClients.cpp
)

target_link_libraries(
        run_tcp_server Moebius
)

target_link_libraries(
        run_tcp_client Moebius
)

target_link_libraries(
        run_multiple_tcp_clients Moebius pthread
)


