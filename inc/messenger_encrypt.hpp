#ifndef ENCRYPTION_HPP
#define ENCRYPTION_HPP

#include <string>
#include <vector>
#include <memory>

#include "messenger_encrypt_abc.hpp"

namespace messenger {

class Rot13Encryption: public EncryptionBase {
public:
    Rot13Encryption() = default;
    Rot13Encryption(const Rot13Encryption& a_other) = default;
    Rot13Encryption& operator=(const Rot13Encryption& a_other) = default;
    ~Rot13Encryption() = default;

    const std::string Encrypt(const std::string& a_msg) override;
};


class UppercaseEncryption: public EncryptionBase {
public:
    UppercaseEncryption() = default;
    UppercaseEncryption(const UppercaseEncryption& a_other) = default;
    UppercaseEncryption& operator=(const UppercaseEncryption& a_other) = default;
    ~UppercaseEncryption() = default;

    const std::string Encrypt(const std::string& a_msg) override;
};


class XorEncryption: public EncryptionBase {
public:
    XorEncryption() = default;
    XorEncryption(const XorEncryption& a_other) = default;
    XorEncryption& operator=(const XorEncryption& a_other) = default;
    ~XorEncryption() = default;

    const std::string Encrypt(const std::string& a_msg) override;
};


class MultiEncryption: public EncryptionBase {
public:
    MultiEncryption(std::vector<std::unique_ptr<EncryptionBase>> a_encryptions);
    MultiEncryption(const MultiEncryption& a_other) = default;
    MultiEncryption& operator=(const MultiEncryption& a_other) = default;
    ~MultiEncryption() = default;

    const std::string Encrypt(const std::string& a_msg) override;

private:
    std::vector<std::unique_ptr<EncryptionBase>> m_encryptions;
};


} //messenger


#endif