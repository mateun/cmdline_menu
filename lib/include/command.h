#pragma once
#include "cmdline_api.h"
#include <string>

class Menu;
class MenuStack;

class CMDLINE_API Command {

public:
    Command(const std::string& name, char key) : _key(key), _name(name) {
        printf("in ctr. of Command\n");
        printf("key: %c\n", _key);
    }
    virtual void execute(Menu& menu) = 0;
    char getKey() { return _key; }
    std::string getName() { return _name; }

protected:
    std::string _name;
    char _key;

    
};

class CMDLINE_API BackCommand : public Command {

public:
    BackCommand(const std::string& name, char key) : Command(name, key) {
        printf("ctr. BackCommand\n");
        printf("_key: %c\n", this->getKey());
    }
    virtual void execute(Menu& menu);

};
