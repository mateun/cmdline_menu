#include <menustack.h>
#include <menu.h>
#include <stdio.h>


void MenuStack::push(Menu* men) {
    //printf("pushing menu [%p] in stack: %p\n", (void*) men, (void*) this);
    _menus.push_back(men);
    _stackPointer++;
    #ifdef TRACE
    for each (Menu* m in _menus) {
        printf("menu: [%p]\n",  (void*) m);
    }
    printf("_stackPointer: %d\n", _stackPointer);
    #endif
}

Menu* MenuStack::pop() {
    //printf("popping menu. _stackpointer: %d, menu.size(): %d. StackObjId: %p\n", _stackPointer, _menus.size(), (void*) this);
    

    if (_stackPointer > 0) {
        Menu* m = _menus[_stackPointer--];
        _menus.pop_back();

        #ifdef TRACE
        for each (Menu* m in _menus) {
                printf("menu: [%p]\n",  (void*) m);
        }
        #endif

        return m;
    }
    
}

Menu* MenuStack::getTop() {
    //printf("in getTop(): %d\n", _stackPointer);
    if (_stackPointer >= 0)
        return _menus[_stackPointer];
    else {
        return nullptr;
    }
}



