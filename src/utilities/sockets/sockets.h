//
// Created by gaertnerl on 23.09.20.
//

#ifndef MOEBIUS_SOCKETS_H
#define MOEBIUS_SOCKETS_H

#include <netinet/in.h>
#include "../message/message.h"

namespace moebius {

    int accept_connection(int listening_socket, struct sockaddr_in address, int address_length);

    void set_socket_nonblocking(int socket_fd);

    int create_listening_socket();

    int create_tcp_ip4_socket();

    void bind_listening_socket(int listening_socket_fd, struct sockaddr_in address);

    void listen_for_connections(int listening_socket_fd, int backlog);

    void enable_reuse_address(int socket_fd);

    moebius::Message receive_from_socket(int socket_fd, int buffer_size);

    moebius::Message receive_from_socket(int socket_fd, int buffer_size, char buffer[]);

    void write_to_socket(int socket_fd, moebius::Message message);

    void close_socket(int socket_fd);

    void connect_socket(int socket_fd, struct sockaddr_in address);

}

#endif //MOEBIUS_SOCKETS_H
