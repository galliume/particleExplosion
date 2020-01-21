#ifndef PARTICLE_H
#define PARTICLE_H

struct Particle {
    double x;
    double y;
    double speed;
    double direction;


    public:
        Particle();
        virtual ~Particle();
        void update(int interval);
};

#endif