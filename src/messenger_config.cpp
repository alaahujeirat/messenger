#include <utility>
#include <cctype>
#include <fstream>

#include "messenger_config.hpp"

namespace messenger {

static std::map<std::string, SourceOptions> BuildSources()
{
    std::map<std::string, SourceOptions> map;

    map.insert(std::pair<std::string, SourceOptions>("console", SourceConsole));
    map.insert(std::pair<std::string, SourceOptions>("file", SourceFile));

    return map;
}

static std::map<std::string, DestinationOptions> BuildDestinations()
{
    std::map<std::string, DestinationOptions> map;

    map.insert(std::pair<std::string, DestinationOptions>("console", DestinationConsole));
    map.insert(std::pair<std::string, DestinationOptions>("file", DestinationFile));
    map.insert(std::pair<std::string, DestinationOptions>("socket", DestinationSocket));

    return map;
}

static std::map<std::string, EncryptionOptions> BuildEncryptions()
{
    std::map<std::string, EncryptionOptions> map;

    map.insert(std::pair<std::string, EncryptionOptions>("noencryption", NoEncryption));
    map.insert(std::pair<std::string, EncryptionOptions>("rot13", Rot13));
    map.insert(std::pair<std::string, EncryptionOptions>("uppercase", Uppercase));
    map.insert(std::pair<std::string, EncryptionOptions>("xor", Xor));
    map.insert(std::pair<std::string, EncryptionOptions>("multi", Multi));

    return map;
}

MessengerConfiguration::MessengerConfiguration()
: m_sources(BuildSources())
, m_destinations(BuildDestinations())
, m_encryptions(BuildEncryptions())
{}


static bool isFile(const std::string& a_arg)
{
    std::fstream f(a_arg);
    if (!f) {
        return false;
    }

    return true;
}

SourceOptions MessengerConfiguration::SourceType(const std::string& a_arg)
{
    size_t size = a_arg.size();

    if (isFile(a_arg)) {
        return m_sources["file"];
    } else {
        std::string str(a_arg);
        for (size_t i=0; i < size; ++i) {
            str[i] = tolower(str[i]);
        }

        if (str.find("con") != str.npos) {
            return m_sources["console"];
        }
    }

    throw ConfigurationException("Invalid source");
}


DestinationOptions MessengerConfiguration::DestinationType(const std::string& a_arg)
{
    size_t size = a_arg.size();

    if (a_arg.find(":") != a_arg.npos) {
        return m_destinations["socket"];
    } else if (isFile(a_arg)) {
        return m_destinations["file"];
    } else {
        std::string str(a_arg);
        for (size_t i=0; i < size; ++i) {
            str[i] = tolower(str[i]);
        }

        if (str.find("con") != str.npos) {
            return m_destinations["console"];
        }
    }

    throw ConfigurationException("Invalid destination");
}


EncryptionOptions MessengerConfiguration::EncryptionType(const std::string& a_arg)
{
    size_t size = a_arg.size();
    std::string str(a_arg);

    for (size_t i=0; i < size; ++i) {
        str[i] = tolower(str[i]);
    }
    
    if (m_encryptions.find(str) == m_encryptions.end()) {
            throw ConfigurationException("Invalid encryption method");
        }
    return m_encryptions[str];
}


} //messenger