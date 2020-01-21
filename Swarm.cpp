#include "Swarm.h"
#include "stdlib.h"

Swarm::Swarm() : lastTime(0) {
    particles = new Particle[NPARTICLES];
}

void Swarm::update(int elapsed) {

    int interval = elapsed - lastTime;

    for (int i = 0; i < Swarm::NPARTICLES; i++) {
        particles[i].update(interval);
    }

    lastTime = elapsed;
}

Swarm::~Swarm() {
    delete [] particles;
}