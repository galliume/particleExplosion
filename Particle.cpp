#include "Particle.h"
#include "stdlib.h"
#include <math.h>

Particle::Particle(): x(0), y(0) {
    init();
}

void Particle::init() {
    direction = (2 * M_PI * rand()) / RAND_MAX;
    speed = (0.03 * rand()) / RAND_MAX;

    speed *= speed;
}
void Particle::update(int interval) {

    direction += interval * 0.001;

    double xspeed = speed * cos(direction);
    double yspeed = speed * sin(direction);

    x += xspeed * interval;
    y += yspeed * interval;

    if (x < -1 || x > 1 || y < -1 || y > 1) {
        init();
    }

    if (rand() < RAND_MAX / 100) {
        init();
    } 
}

Particle::~Particle() {

}