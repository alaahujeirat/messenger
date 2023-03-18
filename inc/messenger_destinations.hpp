#ifndef MESSENGER_DESTINATIONS_HPP
#define MESSENGER_DESTINATIONS_HPP

#include <fstream>

#include "messenger_dest_abc.hpp"
#include "tcp_client.hpp"

namespace messenger {

class ConsoleDestination: public DestinationBase {
public:
    ConsoleDestination() = default;
    ConsoleDestination(const ConsoleDestination& a_other) = default;
    ConsoleDestination& operator=(const ConsoleDestination& a_other) = default;
    ~ConsoleDestination() = default;

    void Write(const std::string& a_msg) override;
};


class FileDestination: public DestinationBase {
public:
    FileDestination(const char* a_filename);
    FileDestination(const FileDestination& a_other) = default;
    FileDestination& operator=(const FileDestination& a_other) = default;
    ~FileDestination() = default;

    void Write(const std::string& a_msg) override;

private:
    std::fstream m_file;
};


class SocketDestination: public DestinationBase {
public:
    SocketDestination(const char* a_IPaddress, int a_port);
    SocketDestination(const SocketDestination& a_other) = default;
    SocketDestination& operator=(const SocketDestination& a_other) = default;
    ~SocketDestination() = default;

    void Write(const std::string& a_msg) override;

private:
    net::TCPClientSocket m_socket;
};


} //messenger

#endif