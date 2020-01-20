#ifndef SWARM_H
#define SWARM_H
#include "Particle.h"

class Swarm {
    public:
        const static int NPARTICLES = 5000;
    private:
        Particle * particles;        
    public:
        Swarm();
        virtual ~Swarm();
        const Particle * getParticles() { return particles; };
};

#endif