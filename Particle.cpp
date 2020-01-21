#include "Particle.h"
#include "stdlib.h"
#include <math.h>

Particle::Particle(): x(0), y(0) {
    direction = (2 * M_PI * rand()) / RAND_MAX;
    speed = (0.0001 * rand()) / RAND_MAX;

}

void Particle::update(int interval) {
    double xspeed = speed * cos(direction);
    double yspeed = speed * sin(direction);

    x += xspeed * interval;
    y += yspeed * interval;
}

Particle::~Particle() {

}