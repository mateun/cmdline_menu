#pragma once
#include <menu.h>
#include <menustack.h>
#include <command.h>
#include <conio.h>


extern unsigned int g_level;
extern unsigned int g_score;

class ShowPlayerStatsCommand : public Command {

public:
    ShowPlayerStatsCommand(std::string name, char key) : Command(name, key) {

    }
    virtual void execute(Menu& men) {


        HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

        // Remember how things were when we started
	    CONSOLE_SCREEN_BUFFER_INFO csbi;
	    GetConsoleScreenBufferInfo( hstdout, &csbi );
        SetConsoleTextAttribute( hstdout, 0x0A);

        Menu::drawHeaderBorder();

        printf("  Player stats\n");
        printf("  ------------\n");
        printf("  Level: %u\n", g_level);
        printf("  Score: %u\n", g_score);

        Menu::drawFooterBorder();

        

        // temp - draw playfield

        DWORD events;
        INPUT_RECORD buffer;
        int keyCode = 0;
        int pX = 25, pY = 10;
        while (keyCode != 27) {
            PeekConsoleInput(hstdin, &buffer, 1, &events);
            if(events > 0)
            {
                if (buffer.EventType == 1) {
                    keyCode = buffer.Event.KeyEvent.wVirtualKeyCode;
                    
                    ReadConsoleInput(hstdin, &buffer, 1, &events);  
                    bool pressed = buffer.Event.KeyEvent.bKeyDown;
                    if (pressed == true) {
                        system("cls");
                        printf("vkc: %d pressed: %d\n", keyCode, pressed);
                        switch (keyCode) {
                            case(37): pX--; break;
                            case(38): pY--; break;
                            case(39): pX++; break;
                            case(40): pY++; break; 
                        }
                        printf("--- drawing map new ---\n");
                        for (int y = 0; y < 30; y++) {
                            for (int x = 0; x < 70; x++) {
                                if (x == pX && y == pY) {
                                    SetConsoleTextAttribute( hstdout, 0x04);
                                    std::cout << (char)219;
                                    SetConsoleTextAttribute( hstdout, 0x0A);
                                } 
                                else {
                                    std::cout << (char)44;
                                }
                                
                            }
                            std::cout << std::endl;
                        }
                    }
                        
                }
                
            }
        }

        SetConsoleTextAttribute( hstdout, csbi.wAttributes );

        /*char c = 0;
        do {

            c = getch();
            printf("char got: %c\n", c);

        } while (c != 27);*/

        // end temp playfield drawing

    }

};