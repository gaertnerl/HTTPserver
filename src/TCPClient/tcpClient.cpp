//
// Created by gaertnerl on 24.09.20.
//


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <string.h>

#include "tcpClient.h"
#include "tcpClientConstants.h"
#include "../utilities/sockets/sockets.h"
#include "../exceptions/exceptions.h"


void moebius::TCPClient::request(Message message)
{
    connect_socket(socket, serv_addr);
    write_to_socket(socket, message);
    Message response = receive_from_socket(socket, 1024);

    if(LOG_REQUEST) std::cout << "REQUEST" << "\n" << "-------" << "\n" << message.as_str() << "\n\n";
    if(LOG_RESPONSE) std::cout << "RESPONSE" << "\n" << "--------" << "\n" << response.as_str() << "\n\n" << std::endl;
}


moebius::TCPClient::TCPClient(const std::string& server_address, int server_port){

    socket = create_tcp_ip4_socket();

    // setup server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(server_port);
    const char* server_address_ = server_address.c_str();
    int result = inet_pton(AF_INET, server_address_, &serv_addr.sin_addr);
    if(result < 0) throw SetupServerAddressException();

    request(Message("hello from client"));
    close_socket(socket);
}
