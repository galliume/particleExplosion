#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle {
    double x;
    double y;

    public:
        Particle();
        virtual ~Particle();
};

#endif