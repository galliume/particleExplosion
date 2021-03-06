#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

class Screen {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        Uint32 *buffer;
        Uint32 *boxBuffer;
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;

        Screen();
        bool init();
        void close();
        bool processEvents();
        void update();
        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
        void clear();
        void boxBlur();
};

#endif