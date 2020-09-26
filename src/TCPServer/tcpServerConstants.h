//
// Created by gaertnerl on 22.09.20.
//

#ifndef MOEBIUS_TCPSERVERCONSTANTS_H
#define MOEBIUS_TCPSERVERCONSTANTS_H

// number of connections that can be queued by the listening sockets
#define SOCKET_BACKLOG 1000

// the timeout (milliseconds) after a POLL operation automatically fails
// set to -1 to disable polling timeouts
#define POLL_TIMEOUT 1000 * 60 * 10

// buffer size in bytes
#define BUFFER_SIZE 100

// max number of available sockets
#define MAX_CONNECTED_SOCKETS 100

// size of buffer that reads in clients request in bytes
#define REQUEST_BUFFER_SIZE 1000000

#endif //MOEBIUS_TCPSERVERCONSTANTS_H
