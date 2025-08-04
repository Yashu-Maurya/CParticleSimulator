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

typedef enum Axis {
    X_AXIS=1,
    Y_AXIS=2,
    Z_AXIS=3,
    ALL_AXIS=4
} Axis;

void developParticle(particle* p, Vector3 pos, Vector3 velocity, Vector3 acceleration, Color color, float size);

void changeParticlePosition(particle* p, Vector3 acceleration);

void renderParticle(particle* p);

void changeDirectionByAngle(particle* p, float radian, Axis axis); // TODO;

#endif