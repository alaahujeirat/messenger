#include <string>

#include "messenger_manager.hpp"
#include "messenger_factory.hpp"
#include "command_parser.hpp"

namespace messenger {

MessengerManager::MessengerManager(int a_argCount, char* a_argArray)
: m_messenger(CreateMsn(a_argCount, a_argArray))
{}


Messenger MessengerManager::CreateMsn(int a_argCount, char* a_argArray)
{
    CommandParser parser(a_argCount, a_argArray);
    auto src = parser.SourceType();
    auto dest = parser.DestinationType();
    auto enc = parser.EncryptionType();

    SourceFactory sourceFac;
    DestinationFactory destFac;
    EncryptionFactory encFac;

    return Messenger(std::move(sourceFac.Create(src)), std::move(destFac.Create(dest)), std::move(encFac.Create(enc)));
}


void MessengerManager::Send()
{
    m_messenger.Send();
}

} //messenger