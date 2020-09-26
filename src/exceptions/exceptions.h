//
// Created by gaertnerl on 21.09.20.
//

#ifndef MOEBIUS_EXCEPTIONS_H
#define MOEBIUS_EXCEPTIONS_H

#include <exception>

namespace moebius{

class SocketInstantiationException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class SocketBindException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class SocketListenException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class AcceptConnectionException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class SetSocketReusableException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class CloseSocketException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class ReadSocketException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class WriteSocketException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class SetSocketNonBlockingException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class ClientClosedConnException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class PollException : public std::exception{
public:
    virtual const char* what() noexcept;
};

class PollTimeoutException : public std::exception {
public:
    virtual const char* what() noexcept;
};

class ReachedSocketLimit : public std::exception {
public:
    virtual const char* what() noexcept;
};

class SetupServerAddressException : public std::exception{
public:
    virtual const char* what() noexcept;
};

class ConnectSocketException : public std::exception{
public:
    virtual const char* what() noexcept;
};

class SocketReceivedInvalidEvent : public std::exception{
public:
    virtual const char* what() noexcept;
};

class SocketReceivedPOLLNVAL : public std::exception{
public:
    virtual const char* what() noexcept;
};
}
#endif