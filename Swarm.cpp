#include "Swarm.h"
#include "stdlib.h"

Swarm::Swarm() {
    particles = new Particle[NPARTICLES];
}

void Swarm::update() {
    for (int i = 0; i < Swarm::NPARTICLES; i++) {
        particles[i].update();
    }
}

Swarm::~Swarm() {
    delete [] particles;
}