#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_EVERYTHING != 0)) {
        cerr << "SDL Init failed : " << SDL_GetError() << endl;
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Particle fire explosion", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    if (NULL == window) {
        cerr << "SDL Window creation failed : " << SDL_GetError() << endl;
        SDL_Quit();
        return 2;
    }

    bool quit = false;
    SDL_Event event;

    while (!quit) {
    
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}