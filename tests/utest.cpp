#include "command_parser.hpp"
#include "messenger_manager.hpp"

#include <iostream>

using namespace messenger;

void FileToConNoEnc()
{
    char command[] = "message.txt console";
    MessengerManager manager(3, command);
    manager.Send();

}

void FileToCon()
{
    char command[] = "message.txt Console rot13 uppercase";
    MessengerManager manager(3, command);
    manager.Send();

}

void ConToCon()
{
    char command[] = "console console uppercase";
    MessengerManager manager(3, command);
    manager.Send();
}

void ConToFile()
{
    char command[] = "console savedMsg.txt uppercase";
    MessengerManager manager(3, command);
    manager.Send();
}

void ConToTcp()
{
    char command[] = "console 127.0.0.1:7070 uppercase";
    MessengerManager manager(3, command);
    manager.Send();
}

void FileToTcp()
{
    char command[] = "message.txt 127.0.0.1:7070 uppercase";
    MessengerManager manager(3, command);
    manager.Send();
}

int main(int argc, char* argv[])
{
    //FileToConNoEnc();
    //FileToCon();
    //ConToCon();
    ConToFile();
    //ConToTcp();
    //FileToTcp();

}