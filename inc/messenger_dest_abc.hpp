#ifndef DESTINATION_ABC_HPP
#define DESTINATION_ABC_HPP

#include <string>

namespace messenger {

class DestinationBase {
public:
    virtual ~DestinationBase() = default;
    virtual void Write(const std::string& a_msg) = 0;

protected:
    DestinationBase() = default;
    DestinationBase(const DestinationBase& a_other) = default;
    DestinationBase& operator=(const DestinationBase& a_other) = default;
};

} //messenger

#endif