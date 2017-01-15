#pragma once
#include "cmdline_api.h"
#include "command.h"
#include "menustack.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <windows.h>


class CMDLINE_API  Menu {

public:
    Menu() {
        //printf("in Menu default ctr.\n");
    }
    Menu(const std::string& name, MenuStack* menuStack) : _name(name), _menuStack(menuStack) {
        _menuStack->push(this);
        //printf("in ctr. of menu [%p]; menustack: %p\n", (void*) this, (void*) _menuStack);
    }
    Menu& operator=(Menu& other) {
        //printf("in operator= of menu; other: %p\n", (void*) &other);
        this->_cmdList = other._cmdList;
        this->_name = other._name;
        this->_menuStack = other._menuStack;
        return *this;
    }
    virtual void render(); 
    virtual void addCommand(Command* cmd);
    void setMenuStack(MenuStack* menuStack) { 
        _menuStack = menuStack; 
        //printf("set menustack: %p\n", (void*) &_menuStack);
     }
     MenuStack* getMenuStack() {
         return _menuStack;
     }

     static void drawHeaderBorder() { 
        SetConsoleCP(1252);
        std::cout << (char)201;
        Menu::drawDoubleLine();
        std::cout << (char) 187 << std::endl;
     }

     static void drawFooterBorder() {
        std::cout << (char)200;
        Menu::drawDoubleLine();
        std::cout << (char)188 << std::endl;
     }

     
     static void drawSingleLine() {
        printf("  ");
        for (int i = 0; i < 48; i++) {
            std::cout << (char) 196;
        }
        std::cout << std::endl;
     }

     static void drawDoubleLine() {
        for (int i = 0; i < 50; i++) {
            std::cout << (char) 205;
        }
        
     }
    
private:
    std::vector<Command*> _cmdList;
    std::string _name;
    MenuStack* _menuStack;

};