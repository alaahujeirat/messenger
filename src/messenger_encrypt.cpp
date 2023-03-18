#include <cctype>
#include <sstream>

#include "messenger_encrypt.hpp"


namespace messenger {

const std::string Rot13Encryption::Encrypt(const std::string& a_msg)
{
    std::string enc_msg;

    for (const auto& e: a_msg) {
        if (isupper(e)) {
            enc_msg.push_back('A' + (e - 'A' + 13) % 26);
        } else if (islower(e)) {
            enc_msg.push_back('a' + (e - 'a' + 13) % 26);
        } else {
            enc_msg.push_back(e);
        }
    }

    return enc_msg;
}


const std::string UppercaseEncryption::Encrypt(const std::string& a_msg)
{
    std::string enc_msg(a_msg);
    size_t size = a_msg.size();

    for (size_t i=0; i < size; ++i) {
        enc_msg[i] = toupper(enc_msg[i]);
    }

    return enc_msg;
}


const std::string XorEncryption::Encrypt(const std::string& a_msg)
{
    std::stringstream ss;

    for (const auto& e: a_msg) {
        ss << std::hex << (e | 0x42);
    }

    return ss.str();
}


MultiEncryption::MultiEncryption(std::vector<std::unique_ptr<EncryptionBase>> a_encryptions)
: m_encryptions(std::move(a_encryptions))
{}

const std::string MultiEncryption::Encrypt(const std::string& a_msg)
{
    std::string enc_msg(a_msg);

    for (auto& e: m_encryptions) {
        enc_msg = e->Encrypt(enc_msg);
    }

    return enc_msg;
}


} //messenger