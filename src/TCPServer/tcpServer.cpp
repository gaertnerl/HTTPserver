//
// Created by gaertnerl on 22.09.20.
//


#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/poll.h>
#include <iostream>

#include "../utilities/message/message.h"
#include "../utilities/sockets/sockets.h"
#include "../exceptions/exceptions.h"
#include "tcpServer.h"
#include "tcpServerConstants.h"


moebius::Message moebius::TCPServer::generate_response(moebius::Message message)
{
    return Message("HTTP/1.0 200 OK\r\n\r\nHello from server");
}

void moebius::TCPServer::handle_socket_communication(int socket_index)
{
    int socket_fd = fd_arr[socket_index].fd;

    try{
        Message received = receive_from_socket(socket_fd, buffer_size, buffer);
        Message response = generate_response(received);
        write_to_socket(socket_fd, response);
    }
    catch(const ClientClosedConnException&) {
        std::cout << "client closed before server could respond\n" << std::endl;
    }
    handled_sockets.push(socket_index);
}

void moebius::TCPServer::remove_handled_sockets()
{
    int count = 0;
    while(!handled_sockets.empty())
    {
        remove_socket(handled_sockets.front() - count);
        handled_sockets.pop();
        count ++;
    }
}

void moebius::TCPServer::accept_new_connections()
{
    while (true)
    {
        if(num_fds >= MAX_CONNECTED_SOCKETS) throw ReachedSocketLimit();
        try {
            // add new socket to file descriptor field if not full
            int socket_fd = accept_connection(listening_socket, address, address_length);
            add_socket(socket_fd);
        }
        catch (const AcceptConnectionException&){
            // errno is EWOULDBLOCK if all connections were accepted
            if(errno != EWOULDBLOCK) throw AcceptConnectionException();
            break;
        }
    }
}

void moebius::TCPServer::serve()
{
    // variable for the result of poll operation
    int result;

    do
    {
        result = poll(fd_arr, num_fds, POLL_TIMEOUT);
        if(result < 0) throw PollException();
        if(result == 0) throw PollTimeoutException();

        int current_size = num_fds;
        // iterate over all sockets, including the listening socket
        // we dont assume that the listening socket is the first element of fd_arr,
        // however we could to avoid an if statement... TODO
        for(int socket_index = 0; socket_index < current_size; socket_index++)
        {
            // if descriptor does not return POLLIN jump to next descriptor
            if(fd_arr[socket_index].revents == 0) continue;

            // if its not 0 it should be POLLIN, otherwise throw exception
            if(fd_arr[socket_index].revents != POLLIN) {
                if(fd_arr[socket_index].revents == POLLNVAL) throw SocketReceivedPOLLNVAL();
                else continue;
            };

            if(fd_arr[socket_index].fd == listening_socket)
                accept_new_connections();

            else
                handle_socket_communication(socket_index);
        }
        remove_handled_sockets();
    }
    while(true);
}

void moebius::TCPServer::setup_address()
{
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    address_length = sizeof(address);
}

void moebius::TCPServer::add_socket(int socket_fd)
{
    fd_arr[num_fds].fd = socket_fd;
    fd_arr[num_fds].events = POLLIN;
    num_fds++;
}

void moebius::TCPServer::remove_socket(int index)
{
    close_socket(fd_arr[index].fd);
    for(int j = index; j < num_fds - 1; j++)
        fd_arr[j] = fd_arr[j+1];

    fd_arr[num_fds-1].fd = 0;
    fd_arr[num_fds-1].revents = 0;
    fd_arr[num_fds-1].events = 0;

    num_fds --;
}

moebius::TCPServer::TCPServer(int port)
{
    // initialize all poll structs, otherwise they start off with invalid values for 'revent'
    memset(fd_arr, 0 , sizeof(fd_arr));

    // the number of socket descriptors that are in use right now
    num_fds = 0;

    this->port = port;
    setup_address();

    // create and bind listening socket
    listening_socket = create_listening_socket();
    enable_reuse_address(listening_socket);
    set_socket_nonblocking(listening_socket);
    bind_listening_socket(listening_socket, address);
    listen_for_connections(listening_socket, SOCKET_BACKLOG);
    add_socket(listening_socket);

    serve();
    close_socket(listening_socket);
}