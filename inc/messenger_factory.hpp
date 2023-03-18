#ifndef MESSENGER_FACTORY_HPP
#define MESSENGER_FACTORY_HPP

#include <vector>
#include <string>
#include <memory>

#include "messenger_source_abc.hpp"
#include "messenger_dest_abc.hpp"
#include "messenger_encrypt_abc.hpp"
#include "messenger_config.hpp"

namespace messenger {

class SourceFactory {
public:
    SourceFactory() = default;
    SourceFactory(const SourceFactory& a_other) = default;
    SourceFactory& operator=(const SourceFactory& a_other) = default;
    ~SourceFactory() = default;

    std::unique_ptr<SourceBase> Create(const std::string& a_source);

private:
    MessengerConfiguration m_config;
};


class DestinationFactory {
public:
    DestinationFactory() = default;
    DestinationFactory(const DestinationFactory& a_other) = default;
    DestinationFactory& operator=(const DestinationFactory& a_other) = default;
    ~DestinationFactory() = default;

    std::unique_ptr<DestinationBase> Create(const std::string& a_destination);

private:
    MessengerConfiguration m_config;
};


class EncryptionFactory {
public:
    using uPtr = std::unique_ptr<EncryptionBase>;
    EncryptionFactory();
    EncryptionFactory(const EncryptionFactory& a_other) = default;
    EncryptionFactory& operator=(const EncryptionFactory& a_other) = default;
    ~EncryptionFactory() = default;

    uPtr Create(std::vector<std::string>& a_encryption);

private:
    std::vector<uPtr> Convert(const std::vector<std::string>& a_encryption);

private:
    std::map<EncryptionOptions, uPtr> m_encryptions;
    MessengerConfiguration m_config;
};


} //messenger

#endif