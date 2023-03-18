#ifndef SOURCE_ABC_HPP
#define SOURCE_ABC_HPP

#include <string>

namespace messenger {

class SourceBase {
public:
    virtual ~SourceBase() = default;
    virtual std::string Read() = 0;
    virtual bool End() = 0;

protected:
    SourceBase() = default;
    SourceBase(const SourceBase& a_other) = default;
    SourceBase& operator=(const SourceBase& a_other) = default;
};

} //messenger

#endif