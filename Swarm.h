#ifndef SWARM_H
#define SWARM_H
#include "Particle.h"

class Swarm {
    public:
        const static int NPARTICLES = 10000;
    private:
        Particle * particles;    
        int lastTime;    
    public:
        Swarm();
        virtual ~Swarm();
        const Particle * getParticles() { return particles; };
        void update(int elapsed);
};

#endif