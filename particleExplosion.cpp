#include <iostream>
#include <SDL2/SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"

using namespace std;

int main() {

    srand(time(NULL));

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;   
    Screen screen;

    if (false == screen.init()) {
        cout << "Error SDL" << endl;
    }

    Swarm swarm;

    while (true) {   

        int elapsed = SDL_GetTicks();
        unsigned char green = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
        unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
        unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

        const Particle * const particles = swarm.getParticles();

        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = particles[i];

            int x = (particle.x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = (particle.y + 1) * Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);
        }

        screen.update();

        if (false == screen.processEvents()) {
            break;
        }
    }

    screen.close();
    
    return 0;
}