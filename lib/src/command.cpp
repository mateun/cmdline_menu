#include <command.h>
#include <menustack.h>
#include <menu.h>

void BackCommand::execute(Menu& menu) {
    
    menu.getMenuStack()->pop();
    Menu* men = menu.getMenuStack()->getTop();
    if (men != nullptr)
        men->render();
    
}