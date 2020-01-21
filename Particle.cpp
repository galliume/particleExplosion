#include "Particle.h"
#include "stdlib.h"
#include <math.h>

Particle::Particle(): x(0), y(0) {
    direction = (2 * M_PI * rand()) / RAND_MAX;
    speed = (0.001 * rand()) / RAND_MAX;

}

void Particle::update() {
    double xspeed = speed * cos(direction);
    double yspeed = speed * sin(direction);

    x += xspeed;
    y += yspeed;
}

Particle::~Particle() {

}