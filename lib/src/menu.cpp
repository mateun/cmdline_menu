#include <menu.h>
#include <stdio.h>


void Menu::render() {
    printf("%s [%p]\n", _name.c_str(), (void*)this);
    printf("-----------------------------------------\n");
    for each(Command* cmd in _cmdList) {
        printf("%c ... %s\n", cmd->getKey(), cmd->getName().c_str());
    }

    printf("-----------------------------------------\n");
    printf("$> ");
    
    char c;
    scanf("%c", &c);
    // clear the stdin
    while ( getchar() != '\n' )
    ;
    printf("current c: %c\n", c);
    for each (Command* cmd in _cmdList) {
        if (c == cmd->getKey()) {
            cmd->execute(*this);
            
        }
    }
    
    render();

}

void Menu::addCommand(Command* cmd) {
    _cmdList.push_back(cmd);
}