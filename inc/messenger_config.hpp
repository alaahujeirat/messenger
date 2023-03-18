#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <map>
#include <string>

namespace messenger {

enum SourceOptions{SourceConsole, SourceFile};
enum DestinationOptions{DestinationConsole, DestinationFile, DestinationSocket};
enum EncryptionOptions{NoEncryption, Rot13, Uppercase, Xor, Multi};


class MessengerConfiguration {
public:
    MessengerConfiguration();
    MessengerConfiguration(const MessengerConfiguration& a_other) = default;
    MessengerConfiguration& operator=(const MessengerConfiguration& a_other) = default;
    ~MessengerConfiguration() = default;

    SourceOptions SourceType(const std::string& a_arg);
    DestinationOptions DestinationType(const std::string& a_arg);
    EncryptionOptions EncryptionType(const std::string& a_arg);

private:
    std::map<std::string, SourceOptions> m_sources;
    std::map<std::string, DestinationOptions> m_destinations;
    std::map<std::string, EncryptionOptions> m_encryptions;
};


class ConfigurationException: public std::invalid_argument {
public:
    ConfigurationException(const char* what) : std::invalid_argument(what) {}
};


} //messenger

#endif