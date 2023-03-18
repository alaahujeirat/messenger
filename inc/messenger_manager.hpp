#ifndef MESSENGER_MANAGER_HPP
#define MESSENGER_MANAGER_HPP

#include "messenger.hpp"

namespace messenger {

class MessengerManager {
public:
    MessengerManager(int a_argCount, char* a_argArray);
    MessengerManager(const MessengerManager& a_other);
    MessengerManager& operator=(const MessengerManager& a_other);
    ~MessengerManager() = default;

    void Send();

private:
    Messenger CreateMsn(int a_argCount, char* a_argArray);

private:
    Messenger m_messenger;
};


class MessengerManagerException: std::runtime_error {
public:
    MessengerManagerException(const char* what) : std::runtime_error(what) {}
};

} //messenger

#endif