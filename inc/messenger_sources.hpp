#ifndef MESSENGER_SOURCES_HPP
#define MESSENGER_SOURCES_HPP

#include <fstream>

#include "messenger_source_abc.hpp"

namespace messenger {

class ConsoleSource: public SourceBase {
public:
    ConsoleSource();
    ConsoleSource(const ConsoleSource& a_other) = default;
    ConsoleSource& operator=(const ConsoleSource& a_other) = default;
    ~ConsoleSource() = default;

    std::string Read() override;
    bool End() override;

private:
    bool m_isEnd;
};


class FileSource: public SourceBase {
public:
    FileSource(const char* a_filename);
    FileSource(const FileSource& a_other) = default;
    FileSource& operator=(const FileSource& a_other) = default;
    ~FileSource();

    std::string Read() override;
    bool End() override;

private:
    std::fstream m_file;
    bool m_isEnd;
};


} //messenger

#endif