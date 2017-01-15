#include <stdio.h>
#include <menu.h>
#include <menustack.h>
#include <command.h>
#include <stdlib.h>

class ExitCommand : public Command {
    public:
    ExitCommand(std::string name, char key) : Command(name, key) {}
    virtual void execute(Menu& m) {
        exit(0);
    }

};

class TaxCommand : public Command {
    public:
    TaxCommand(std::string name, char key) : Command(name, key) {}
    virtual void execute(Menu& m) {
        printf("Set tax value (1-10): ");
        char* input = new char[3];
        char* mover = input;
        char c;
        int counter = 0;
        do {
           c = fgetc(stdin);
           *mover = c;
           mover++;
           #ifdef TRACE
           printf("input0: %c\n", input[0]);
           printf("input1: %c\n", input[1]);
           printf("input2: %c\n", input[2]);
           #endif

           if (c == '\n' ) {
               #ifdef TRACE
               printf("newline detected, aborting.\n");
               #endif
               break;
           }
           counter++;
           if (counter > 2) {
               #ifdef TRACE
               printf("input is too long, aborting.\n");
               #endif
           }
        } while (c != '\n' && counter < 2);

        // hard cut after 2 digits
        mover[2] = '\0';
        #ifdef TRACE
        printf("cleaning stdin buffer\n");
        #endif
        if (counter > 1)
            while ((c = getchar()) != '\n' && c != EOF);

        #ifdef TRACE
        for (int i = 0; i < 3; i++) {
            printf("c[%d]=%c\n", i, input[i]);
        }
        #endif
        
        int num = strtol(input, NULL, 10);
        if (num < 1 || num > 10) {
            printf("invalid input!\n");
        }
        printf("user entered: %d \n", num);
    }
};

class PeopleCommand : public Command {
    public:
    PeopleCommand(std::string name, char key) : Command(name, key) {}
    virtual void execute(Menu& men) {
        Menu m("People menu", men.getMenuStack());    
        TaxCommand cmdTax("Set taxes", '1');
        BackCommand bc("Back", '2');
        m.addCommand(&cmdTax);
        m.addCommand(&bc);
        m.render();
    }

};

class BuildHouseCommand : public Command {
public:
    BuildHouseCommand(std::string name, char key) : Command(name, key) {}
    virtual void execute(Menu& m) {
        printf("build a house!\n");
    }
};

class BuildBarrackCommand : public Command {
public:
    BuildBarrackCommand(std::string name, char key) : Command(name, key) {}
    virtual void execute(Menu& m) {
        printf("build a barrack!\n");
    }
};

class BuildSubCommand : public Command {

public:
    BuildSubCommand(std::string name, char key) : Command(name, key) {

    }
    virtual void execute(Menu& men) {
        Menu m("Build sub menu", men.getMenuStack());    
        BuildHouseCommand cmdHouse("House", '1');
        BuildBarrackCommand cmdBarrack("Barrack", '2');
        BackCommand bc("Back", '3');
        m.addCommand(&cmdHouse);
        m.addCommand(&cmdBarrack);
        m.addCommand(&bc);
        m.render();
    }
};


class BuildCommand : public Command {

public:
    BuildCommand(std::string name, char key) : Command(name, key) {

    }
    virtual void execute(Menu& men) {
        Menu m("Build menu", men.getMenuStack());    
        BuildHouseCommand cmdHouse("House", '1');
        BuildBarrackCommand cmdBarrack("Barrack", '2');
        BuildSubCommand cmdSub("Sub", '3');
        BackCommand bc("Back", '4');
        m.addCommand(&cmdHouse);
        m.addCommand(&cmdBarrack);
        m.addCommand(&cmdSub);
        m.addCommand(&bc);
        m.render();
    }
};


int main(int argc, char** args) {
    printf("creating menustack\n");
    MenuStack ms;

    printf("creating menu\n");
    Menu m("Main menu", &ms);
    ExitCommand exitCmd("Exit", 'e');
    BuildCommand bc("Build", '1');
    PeopleCommand pc("People", '2');
    m.addCommand(&bc);
    m.addCommand(&pc);
    m.addCommand(&exitCmd);
    m.render();
    
    return 0;
}