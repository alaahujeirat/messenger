#include "messenger_factory.hpp"
#include "messenger_sources.hpp"
#include "messenger_destinations.hpp"
#include "messenger_encrypt.hpp"


namespace messenger {

//Source factory
std::unique_ptr<SourceBase> SourceFactory::Create(const std::string& a_source)
{   
    SourceOptions type;
    try {
        type  = m_config.SourceType(a_source);
    } catch (const ConfigurationException& e) {
        throw;
    }
    
    switch (type)
    {
        case SourceConsole:
            return std::make_unique<ConsoleSource>();

        case SourceFile:
            return std::make_unique<FileSource>(a_source.c_str());

        default:
            return nullptr;
    }
}


// Destination factory
static std::pair<std::string, int> SplitAddress(const std::string& a_destination)
{
    size_t pos = a_destination.find(":");
    std::string ip = a_destination.substr(0, pos);
    int port = std::atoi((a_destination.substr(pos+1)).c_str());

    return {ip, port};
}

std::unique_ptr<DestinationBase> DestinationFactory::Create(const std::string& a_destination)
{   
    DestinationOptions type;
    try {
        type = m_config.DestinationType(a_destination);
    } catch (const ConfigurationException& e) {
        throw;
    }

    std::pair<std::string, int> address;
    switch (type)
    {
        case DestinationConsole:
            return std::make_unique<ConsoleDestination>();

        case DestinationFile:
            return std::make_unique<FileDestination>(a_destination.c_str());

        case DestinationSocket:
            address = SplitAddress(a_destination);
            return std::make_unique<SocketDestination>(address.first.c_str(), address.second);

        default:
            return nullptr;
    }
}


// Encryption factory
static std::map<EncryptionOptions, std::unique_ptr<EncryptionBase>> BuildEncs()
{
    using uPtr = std::unique_ptr<EncryptionBase>;
    std::map<EncryptionOptions, uPtr> map;

    map.insert(std::pair<EncryptionOptions, uPtr>(NoEncryption, nullptr));
    map.insert(std::pair<EncryptionOptions, uPtr>(Rot13, std::make_unique<Rot13Encryption>()));
    map.insert(std::pair<EncryptionOptions, uPtr>(Uppercase, std::make_unique<UppercaseEncryption>()));
    map.insert(std::pair<EncryptionOptions, uPtr>(Xor, std::make_unique<XorEncryption>()));

    return map;
}

EncryptionFactory::EncryptionFactory()
: m_encryptions(BuildEncs())
, m_config()
{}


std::unique_ptr<EncryptionBase> EncryptionFactory::Create(std::vector<std::string>& a_encryption)
{
    //multi encryption
    if (a_encryption.size() > 1) { 
        return std::make_unique<MultiEncryption>(Convert(a_encryption));
    } 

    EncryptionOptions type;
    try {
        type  = m_config.EncryptionType(a_encryption[0]);
    } catch(const ConfigurationException& e) {
        throw;
    }

    return std::move(m_encryptions[type]);
}


std::vector<std::unique_ptr<EncryptionBase>> EncryptionFactory::Convert(const std::vector<std::string>& a_encryption)
{
    std::vector<std::unique_ptr<EncryptionBase>> encs;

    for (auto e: a_encryption) {
        auto type = m_config.EncryptionType(e);
        encs.push_back(std::move(m_encryptions[type]));
    }

    return encs;
}


} //messenger