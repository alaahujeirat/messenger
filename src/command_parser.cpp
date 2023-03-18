#include <stdexcept>
#include <cstring>

#include "command_parser.hpp"

namespace messenger {

constexpr int MIN_ARGS = 2;

static std::vector<std::string> Parse(int a_argCount, char* a_argArray)
{
    std::vector<std::string> vec;
    vec.reserve(a_argCount);

    char* arg;
    arg = strtok(a_argArray, " ");
    while (arg != NULL) {
        vec.push_back(arg);
        arg = strtok(NULL, " ");
    }
    
    if (vec.size() == MIN_ARGS) {
        vec.push_back("noEncryption");
    }

    return vec;
}

CommandParser::CommandParser(int a_argCount, char* a_argArray)
: m_argCount(a_argCount)
, m_argList(Parse(a_argCount, a_argArray))
{
    if (!isCommandValid()) {
        throw std::runtime_error("Command argument/s missing");
    }
}

bool CommandParser::isCommandValid()
{
    return m_argCount >= MIN_ARGS;
}

const std::string CommandParser::SourceType()
{
    return m_argList[0];
}

const std::string CommandParser::DestinationType()
{
    return m_argList[1];
}

const std::vector<std::string> CommandParser::EncryptionType()
{
    size_t size = m_argList.size();
    std::vector<std::string> encList;
    encList.push_back(m_argList[2]);

    if (size > MIN_ARGS) {
        for (size_t i=3; i < size; ++i) {
            encList.push_back(m_argList[i]);
        }
    }

    return encList;
}


} //messenger