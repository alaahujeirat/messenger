#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <string>
#include <memory>

#include "messenger_source_abc.hpp"
#include "messenger_dest_abc.hpp"
#include "messenger_encrypt_abc.hpp"

namespace messenger {

class Messenger {
public:
    Messenger(std::unique_ptr<SourceBase> a_source, std::unique_ptr<DestinationBase> a_destination, std::unique_ptr<EncryptionBase> a_encryption);
    Messenger(const Messenger& a_other) = delete;
    Messenger& operator=(const Messenger& a_other) = delete;
    ~Messenger() = default;

    void Send();

private:
    std::unique_ptr<SourceBase> m_source;
    std::unique_ptr<DestinationBase> m_destination;
    std::unique_ptr<EncryptionBase> m_encryption;
};

} //messenger

#endif