//
// Created by gaertnerl on 25.09.20.
//


#include <pthread.h>
#include <iostream>
#include <thread>
#include <chrono>

#include "../TCPClient/tcpClient.h"

#define CLIENT_COUNT 50


void * run_client(void * arg)
{
    moebius::TCPClient tcpClient = moebius::TCPClient();
}

int main(int argc, char const *argv[])
{
    pthread_t threads[CLIENT_COUNT];
    for(long i = 0; i < CLIENT_COUNT; i++ ) {
        int rc = pthread_create(&threads[i], nullptr, run_client, nullptr);
        if (rc) {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
        else{
            std::cout << "started client: " <<  i << std::endl;
        }
        // sleep because server can not process requests if they come at the exact same time TODO: find out why
        std::this_thread::sleep_for(std::chrono::microseconds (0));
    }
    return 0;
}
