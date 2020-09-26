//
// Created by gaertnerl on 22.09.20.
//

#ifndef RUN_TCPSERVER_H
#define RUN_TCPSERVER_H

#include <netinet/in.h>
#include <sys/poll.h>
#include <queue>

#include "../utilities/message/message.h"
#include "tcpServerConstants.h"


namespace moebius {

    class TCPServer {
    public:

        explicit TCPServer(int port = 8080);

    private:

        int port;
        struct sockaddr_in address{};
        int address_length;

        //buffer to read in received data
        char buffer[REQUEST_BUFFER_SIZE] = {};
        int buffer_size = REQUEST_BUFFER_SIZE;

        // increase number of sockets by one to account for listening socket
        struct pollfd fd_arr[MAX_CONNECTED_SOCKETS + 1];
        int listening_socket = -1;
        int num_fds;
        std::queue<int> handled_sockets;

        // methods to modify fd_arr member
        void add_socket(int socket_fd);
        void remove_socket(int socket_index);
        void remove_handled_sockets();
        void handle_socket_communication(int socket_index);
        static Message generate_response(moebius::Message message);
        void accept_new_connections();
        void setup_address();
        void serve();

    };
}

#endif //RUN_TCPSERVER_H
