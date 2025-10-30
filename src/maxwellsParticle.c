#include "maxwellsParticle.h"

void developMaxwellsParticle(maxwellsParticle *p, Vector3 pos, Vector3 velocity,
                             Vector3 acceleration, Color color, double mass,
                             double temperature) {

    p->particle.pos = pos;
    p->particle.velocity = velocity;
    p->particle.acceleration = acceleration;
    p->particle.color = color;

    float size = ((int)cbrt(mass*0.75));
    size = size <= 1 ? 1: size;
    size *= 5;
    p->particle.size = (int)size;

    p->mass = mass;
    p->temperature = temperature;
}

void renderMaxwellsParticle(maxwellsParticle *p) {
    if (!p) {
        return;
    }
    DrawSphere(p->particle.pos, p->particle.size, p->particle.color);
}

void checkForMaxwellsParticleCollision(maxwellsParticle *p1, maxwellsParticle *p2) {
    checkForCollision(&p1->particle, &p2->particle);
}

void updateMaxwellsParticlePosition(maxwellsParticle *p) {
    updateParticlePosition(&p->particle);
}

void updateMaxwellsParticleVelocity(maxwellsParticle *p) {
    updateParticleVelocity(&p->particle);
}

void updateMaxwellsParticleAcceleration(maxwellsParticle *p, Vector3 acceleration) {
    changeParticleAcceleration(&p->particle, acceleration);
}

void updateMaxwellsParticlePosition(maxwellsParticle *p) {
    updateParticlePosition(&p->particle);
}

void checkForMaxwellsBoundingBox(maxwellsParticle *p) {
    checkForBoundingBox(&p->particle);
}