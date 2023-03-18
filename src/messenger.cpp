#include "messenger.hpp"

namespace messenger {

Messenger::Messenger(std::unique_ptr<SourceBase> a_source, std::unique_ptr<DestinationBase> a_destination, std::unique_ptr<EncryptionBase> a_encryption)
: m_source(std::move(a_source))
, m_destination(std::move(a_destination))
, m_encryption(std::move(a_encryption))
{}


void Messenger::Send()
{
    while (!m_source->End())
    {
        std::string msg = m_source->Read();
        
        std::string enc_msg(msg);
        if (m_encryption) {
            enc_msg = m_encryption->Encrypt(msg);
        }
        
        m_destination->Write(enc_msg);
    }
}


} //messenger