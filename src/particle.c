#include "particle.h"

void developParticle(particle* p, Vector3 pos, Vector3 velocity,
                     Vector3 acceleration, Color color, float size) {
    p->pos = pos;
    p->velocity = velocity;
    p->acceleration = acceleration;
    p->color = color;
    p->size = size;
}

void changeParticlePosition(particle* p, Vector3 acceleration) {
    if (!p) {
        return;
    }
    float dt = 1 / ((float)FPS);

    acceleration = Vector3Normalize(acceleration);  // Direction Vector
    p->velocity =
        Vector3Add(p->velocity, Vector3Scale(acceleration, 1000.0f * dt));

    // friction
    float friction = 0.98f;
    p->velocity = Vector3Scale(p->velocity, friction);

    p->pos = Vector3Add(p->pos, Vector3Scale(p->velocity, dt));
}

void changeVelocityVector(particle* p, Vector3 v) { p->velocity = (Vector3)v; }

void updateParticlePosition(particle* p) {
    float dt = 1 / ((float)FPS);

    // friction
    p->acceleration = Vector3Scale(p->acceleration, 0.999f);

    p->pos =
        Vector3Add(Vector3Add(p->pos, Vector3Scale(p->velocity, dt)),
                   Vector3Scale(p->acceleration, 100.0f*0.5*dt*dt));  // x = x0 + ut + 1/at^2;
}

void updateParticleVelocity(particle* p) {
    float dt = 1 / ((float)FPS);
    p->velocity = Vector3Add(p->velocity, Vector3Scale(Vector3Normalize(p->acceleration), 100.0f*dt)); // v = u + at;
}

void changeParticleAcceleration(particle* p, Vector3 acceleration) {
    float dt = 1 / ((float)FPS);
    p->acceleration = (Vector3) acceleration;
}

void renderParticle(particle* p) {
    if (!p) {
        return;
    }
    DrawSphere(p->pos, p->size, p->color);
}
