#include <iostream>


#include "messenger_sources.hpp"

namespace messenger {

//Console
ConsoleSource::ConsoleSource()
: m_isEnd(false)
{}

std::string ConsoleSource::Read()
{
    std::string msg;
    std::cout << "Message: ";
    std::getline(std::cin, msg);

    if (msg == ".") {
        m_isEnd = true;
    }

    msg.append("\n");
    return msg;
}

bool ConsoleSource::End()
{
    return m_isEnd;
}


//File
FileSource::FileSource(const char* a_filename)
: m_file(a_filename)
, m_isEnd(false)
{}

FileSource::~FileSource()
{
    m_file.close();
}

std::string FileSource::Read()
{
    std::string msg;
    std::getline(m_file, msg);

    if (m_file.eof()) {
        m_isEnd = true;
    }

    msg.append("\n");
    return msg;
}

bool FileSource::End()
{
    return m_isEnd;
}


} //messenger