//
// Created by gaertnerl on 23.09.20.
//


#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

#include "sockets.h"
#include "../../exceptions/exceptions.h"



/*
 *  +++++++++++++++++++++++++++++++++++++++++++++++++++++
 *  functions to set up initial listening socket
 *  +++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

int moebius::create_listening_socket()
{
    return create_tcp_ip4_socket();
}

void moebius::bind_listening_socket(int listening_socket_fd, struct sockaddr_in address)
{
    int binding = bind(listening_socket_fd,(struct sockaddr *)&address,sizeof(address));
    if (binding < 0) throw SocketBindException();
}

void moebius::listen_for_connections(int listening_socket_fd, int backlog)
{
    int listen_success = listen(listening_socket_fd, backlog);
    if (listen_success < 0) throw SocketListenException();
}

/*
 *  +++++++++++++++++++++++++++++++++++++++++++++++++++++
 *   functions to modify behaviour of sockets
 *   NOTE: accepting sockets will inherit these
 *   modifications from the listening socket
 *   +++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

void moebius::set_socket_nonblocking(int socket_fd)
{
    int enable = 1;
    int result = ioctl(socket_fd, FIONBIO, (char *) &enable);
    if (result < 0) throw SetSocketNonBlockingException();
}

void moebius::enable_reuse_address(int socket_desc)
{
    int enable = 1;
    int result = setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));
    if(result < 0) throw moebius::SetSocketReusableException();
}


/*
 *  +++++++++++++++++++++++++++++++++++++++++++++++++++++
 *  general socket function
 *  +++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

void moebius::close_socket(int socket_desc)
{
    int result = close(socket_desc);
    if(result < 0) throw moebius::CloseSocketException();
}

int moebius::accept_connection(int listening_socket, struct sockaddr_in address, int address_length)
{
    int connected_socket = accept(listening_socket, (struct sockaddr *)&address, (socklen_t*)&address_length);
    if (connected_socket < 0) throw AcceptConnectionException();
    return connected_socket;
}

moebius::Message moebius::receive_from_socket(int socket_fd, int buffer_size)
{
    char buffer[buffer_size];
    int result = recv(socket_fd, buffer, buffer_size, 0);
    if(result < 0) throw ReadSocketException();
    if(result == 0) throw ClientClosedConnException();
    return Message(buffer, result);
}

moebius::Message moebius::receive_from_socket(int socket_fd, int buffer_size, char buffer[])
{
    int result = recv(socket_fd, buffer, buffer_size, 0);
    if(result < 0) throw ReadSocketException();
    if(result == 0) throw ClientClosedConnException();
    return Message(buffer, result);
}

void moebius::write_to_socket(int socket, moebius::Message message)
{
    char* ptr = message.create_char_ptr();
    int result = send(socket , ptr, message.length(), 0);
    delete ptr;
    if(result < 0) throw WriteSocketException();
}

int moebius::create_tcp_ip4_socket()
{
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) throw SocketInstantiationException();
    return client_socket;
}

void moebius::connect_socket(int socket_fd, struct sockaddr_in address)
{
    int result = connect(socket_fd, (struct sockaddr *)&address, sizeof(address));
    if(result < 0) throw ConnectSocketException();
}