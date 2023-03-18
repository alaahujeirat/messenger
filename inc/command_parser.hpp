#ifndef COMMAND_PARSER_HPP
#define COMMAND_PARSER_HPP

#include <string>
#include <vector>

namespace messenger {

class CommandParser {
public:
    CommandParser(int a_argCount, char* a_argArray);
    CommandParser(const CommandParser& a_other) = default;
    CommandParser& operator=(const CommandParser& a_other) = default;
    ~CommandParser() = default;

    bool isCommandValid();
    const std::string SourceType();
    const std::string DestinationType();
    const std::vector<std::string> EncryptionType();

private:
    int m_argCount;
    std::vector<std::string> m_argList;
};


} //messenger

#endif