#include "Swarm.h"
#include "stdlib.h"

Swarm::Swarm() {
    particles = new Particle[NPARTICLES];
}

Swarm::~Swarm() {
    delete [] particles;
}