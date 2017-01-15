
#pragma once
#include "cmdline_api.h"
//#include "menu.h"
#include <vector>

class Menu;

class CMDLINE_API MenuStack {

public:
    MenuStack() {
        printf("in ctr. of MenuStack %p\n", (void*) this);
    }
    virtual void push(Menu* menu);
    virtual Menu* pop();
    virtual Menu* getTop();
    
private:
    std::vector<Menu*> _menus;
    int _stackPointer = -1;
};