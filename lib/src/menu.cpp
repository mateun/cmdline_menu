#include <menu.h>
#include <stdio.h>


void Menu::render() {
    //printf("%s [%p]\n", _name.c_str(), (void*)this);
    printf("\n");
    Menu::drawHeaderBorder();
    printf("  %s \n", _name.c_str());
    Menu::drawSingleLine();
    for each(Command* cmd in _cmdList) {
        printf("  %c ... %s\n", cmd->getKey(), cmd->getName().c_str());
    }

    Menu::drawFooterBorder();
    
    printf("$> ");
    
    char c;
    scanf("%c", &c);
    // clear the stdin
    while ( getchar() != '\n' )
    ;
    //printf("current c: %c\n", c);
    for each (Command* cmd in _cmdList) {
        if (c == cmd->getKey()) {
            system("cls");
            cmd->execute(*this);
            
        }
    }

    

    render();

}

void Menu::addCommand(Command* cmd) {
    _cmdList.push_back(cmd);
}