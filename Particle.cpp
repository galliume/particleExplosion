#include "Particle.h"
#include "stdlib.h"

Particle::Particle() {
    x = ((2.0 * rand()) / RAND_MAX) - 1;
    y = ((2.0 * rand()) / RAND_MAX) - 1;

}

Particle::~Particle() {

}