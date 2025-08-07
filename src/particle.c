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

    p->pos = Vector3Add(
        Vector3Add(p->pos, Vector3Scale(p->velocity, dt)),
        Vector3Scale(p->acceleration,
                     100.0f * 0.5 * dt * dt));  // x = x0 + ut + 1/at^2;
}

void updateParticleVelocity(particle* p) {
    float dt = 1 / ((float)FPS);

    p->velocity =
        Vector3Add(p->velocity,
                   Vector3Scale(p->acceleration, 100.0f * dt));  // v = u + at;
}

void changeParticleAcceleration(particle* p, Vector3 acceleration) {
    float dt = 1 / ((float)FPS);
    p->acceleration = (Vector3)acceleration;
}

void renderParticle(particle* p) {
    if (!p) {
        return;
    }
    DrawSphere(p->pos, p->size, p->color);
}

void checkForCollision(particle* particles, int i, int j) {
    Vector3 distanceVectorP1toP2;
    Vector3 dxVector = Vector3Subtract(particles[i].pos, particles[j].pos);
    distanceVectorP1toP2 = Vector3Multiply(dxVector, dxVector);

    float radiusSum = (particles[i].size + particles[j].size) *
                      (particles[i].size + particles[j].size);

    if (distanceVectorP1toP2.x  <= radiusSum) {  // Getting the absolute value of distance between two
              // particles. on X-Axis here.
        changeVelocityVector(&particles[i], (Vector3){
                                                -particles[i].velocity.x,
                                                particles[i].velocity.y,
                                                particles[i].velocity.z,
                                            });

        changeVelocityVector(&particles[j], (Vector3){
                                                -particles[j].velocity.x,
                                                particles[j].velocity.y,
                                                particles[j].velocity.z,
                                            });
    }
    if (distanceVectorP1toP2.y  <= radiusSum) {
        changeVelocityVector(&particles[i], (Vector3){
                                                particles[i].velocity.x,
                                                -particles[i].velocity.y,
                                                particles[i].velocity.z,
                                            });

        changeVelocityVector(&particles[j], (Vector3){
                                                particles[j].velocity.x,
                                                -particles[j].velocity.y,
                                                particles[j].velocity.z,
                                            });
    }
    if (distanceVectorP1toP2.z  <= radiusSum) {
        changeVelocityVector(&particles[i], (Vector3){
                                                particles[i].velocity.x,
                                                particles[i].velocity.y,
                                                -particles[i].velocity.z,
                                            });

        changeVelocityVector(&particles[j], (Vector3){
                                                particles[j].velocity.x,
                                                particles[j].velocity.y,
                                                -particles[j].velocity.z,
                                            });
    }
}
