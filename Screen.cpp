#include "Screen.h"

Screen::Screen(): window(NULL), renderer(NULL), texture(NULL), buffer(NULL) {

}  

bool Screen::init() {
     if (SDL_Init(SDL_INIT_EVERYTHING != 0)) {
        return false;
    }

    window = SDL_CreateWindow(
        "Particle fire explosion", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
    );

    if (NULL == window) {
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    
    if (NULL == renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (NULL == texture) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return false;
    }

    buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    //fill buffer
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    return true;
}

void Screen::update() {
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
    Uint32 color = 0;
    
    color +=red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    
    buffer[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::close() {
    delete [] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Screen::processEvents() {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}