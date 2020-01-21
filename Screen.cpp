#include "Screen.h"

Screen::Screen(): window(NULL), renderer(NULL), texture(NULL), buffer(NULL), boxBuffer(NULL) {

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
    boxBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    //fill buffer
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(boxBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    return true;
}

void Screen::update() {
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }

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

void Screen::clear() {
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(boxBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::close() {
    delete [] buffer;
    delete [] boxBuffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Screen::boxBlur() {
    Uint32 *temp = buffer;
    buffer = boxBuffer;
    boxBuffer = temp;

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for(int x = 0; x < SCREEN_WIDTH; x++) {
            /*
            * 0 0 0
            * 0 1 0
            * 0 0 0
            */
           //avg of pixel surrending the target pixel
           int redTotal = 0;
           int greenTotal = 0;
           int blueTotal = 0;

            for (int row = -1; row <= 1; row++) {
                for (int col = -1; col <=1; col++) {
                    int currentX = x + col;
                    int currentY = y + row;
                    
                    if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
                        Uint32 color = boxBuffer[currentY * SCREEN_WIDTH + currentX];

                        Uint8 red = color >> 24;
                        Uint8 green = color >> 16;
                        Uint8 blue = color >> 8;

                        redTotal += red;
                        blueTotal += blue;
                        greenTotal += green;
                    }
                }
            }

            Uint8 red = redTotal / 9;
            Uint8 green = greenTotal / 9;
            Uint8 blue = blueTotal / 9;

            setPixel(x, y, red, green, blue);
        }
    }
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