cmake_minimum_required(VERSION 3.17)
project(Moebius)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(googletest)

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
        src/TCPClient/tcpClientConstants.h src/utilities/message/message.cpp src/utilities/message/message.h src/utilities/http/httpMessages.cpp src/utilities/http/httpMessages.h src/utilities/http/httpHeaders.cpp src/utilities/http/httpHeaders.h src/utilities/map/map.cpp src/utilities/map/map.h tests/utilTests/httpHeaderTests.cpp src/utilities/http/httpMethods.cpp src/utilities/http/httpMethods.h src/utilities/http/httpParser.cpp src/utilities/http/httpParser.h src/HTTPServer/HTTPServer.cpp src/HTTPServer/HTTPServer.h src/utilities/response/Responder.cpp src/utilities/response/Responder.h src/utilities/request/Request.cpp src/utilities/request/Request.h src/utilities/tcp/TCPResponder.cpp src/utilities/tcp/TCPRequest.h src/utilities/tcp/TCPRequest.cpp src/utilities/tcp/TCPResponder.h src/utilities/http/HTTPRequest.cpp src/utilities/http/HTTPRequest.h src/utilities/http/HTTPResponder.cpp src/utilities/http/HTTPResponder.h)

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

add_executable(
        run_http_server
        src/run/runHTTPServer.cpp
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

target_link_libraries(
        run_http_server Moebius
)

add_subdirectory(tests)

