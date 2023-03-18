#include <iostream>

#include "messenger_destinations.hpp"

namespace messenger {

//Console
void ConsoleDestination::Write(const std::string& a_msg)
{
    std::cout << a_msg;
}


//File
FileDestination::FileDestination(const char* a_filename)
: m_file(a_filename)
{}

void FileDestination::Write(const std::string& a_msg)
{
    m_file << a_msg;
}


//Socket
SocketDestination::SocketDestination(const char* a_IPaddress, int a_port)
: m_socket(a_IPaddress, a_port)
{}

void SocketDestination::Write(const std::string& a_msg)
{
    m_socket.Send(a_msg);
}

} //messenger