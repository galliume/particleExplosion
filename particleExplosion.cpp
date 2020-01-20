#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"

using namespace std;

int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;   
    Screen screen;

    if (false == screen.init()) {
        cout << "Error SDL" << endl;
    }
    
    while (true) {   

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }
        screen.setPixel(50, 50, 100, 255, 0);
        screen.update();

        if (false == screen.processEvents()) {
            break;
        }
    }

    screen.close();
    
    return 0;
}