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
        if (false == screen.processEvents()) {
            break;
        }
    }

    screen.close();
    
    return 0;
}