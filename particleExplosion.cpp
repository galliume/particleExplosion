#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include <math.h>

using namespace std;

int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;   
    Screen screen;

    if (false == screen.init()) {
        cout << "Error SDL" << endl;
    }

    while (true) {   

        int elapsed = SDL_GetTicks();

        unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }
        screen.update();

        if (false == screen.processEvents()) {
            break;
        }
    }

    screen.close();
    
    return 0;
}