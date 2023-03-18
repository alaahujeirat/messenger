#ifndef ENCRYPTION_ABC_HPP
#define ENCRYPTION_ABC_HPP

#include <string>

namespace messenger {

class EncryptionBase {
public:
    virtual ~EncryptionBase() = default;
    virtual const std::string Encrypt(const std::string& a_msg) = 0;

protected:
    EncryptionBase() = default;
    EncryptionBase(const EncryptionBase& a_other) = default;
    EncryptionBase& operator=(const EncryptionBase& a_other) = default;
};

} //messenger

#endif