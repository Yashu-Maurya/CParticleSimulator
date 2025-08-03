#ifndef particle_h
#define particle_h
#include "main.h"
#include "raymath.h"

typedef struct particle {
    Vector3 pos;
    Vector3 velocity;
    Vector3 acceleration;
    Color color;
    float size;

} particle;

void developParticle(particle* p, Vector3 pos, Vector3 velocity, Vector3 acceleration, Color color, float size);

void changeParticlePosition(particle* p, Vector3 acceleration);

void renderParticle(particle* p);

#endif