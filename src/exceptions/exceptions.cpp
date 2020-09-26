//
// Created by gaertnerl on 21.09.20.
//

#include "exceptions.h"


const char* moebius::SocketInstantiationException::what() noexcept
{
    return "Could not create Socket for Moebius application.";
}

const char* moebius::SocketBindException::what() noexcept
{
    return "Could not bind Socket for Moebius application.";
}

const char* moebius::SocketListenException::what() noexcept
{
    return "Error when listening for connection in Moebius application.";
}

const char* moebius::AcceptConnectionException::what() noexcept
{
    return "Error when accepting connection in Moebius application.";
}

const char* moebius::SetSocketReusableException::what() noexcept
{
    return "Error when setting socket option.";
}

const char* moebius::CloseSocketException::what() noexcept
{
    return "Error when closing socket.";
}

const char* moebius::ReadSocketException::what() noexcept
{
    return "Error when reading socket.";
}

const char* moebius::WriteSocketException::what() noexcept
{
    return "Error when writing to socket.";
}

const char* moebius::SetSocketNonBlockingException::what() noexcept
{
    return "Error when setting socket to non blocking.";
}

const char* moebius::ClientClosedConnException::what() noexcept
{
    return "Exception while trying to receive data: client closed connection.";
}

const char* moebius::PollTimeoutException::what() noexcept
{
    return "Polling timeout reached.";
}

const char* moebius::PollException::what() noexcept
{
    return "Polling failed.";
}

const char* moebius::ReachedSocketLimit::what() noexcept
{
    return "No socket available to accept connection. Consider increasing number of available sockets.";
}

const char* moebius::SetupServerAddressException::what() noexcept
{
    return "Exception when trying to set up the server address.";
}

const char* moebius::ConnectSocketException::what() noexcept
{
    return "Exception when trying to connect socket to another socket.";
}

const char* moebius::SocketReceivedPOLLNVAL::what() noexcept
{
    return "Socket received POLLNVAL event.";
}

const char* moebius::SocketReceivedInvalidEvent::what() noexcept
{
    return "Socket received exceptional event.";
}