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
    p->acceleration = (Vector3)acceleration;
}

void renderParticle(particle* p) {
    if (!p) {
        return;
    }
    DrawSphere(p->pos, p->size, p->color);
}

void checkForCollision(particle* p1, particle* p2) {

    float dx = p2->pos.x - p1->pos.x;
    float dy = p2->pos.y - p1->pos.y;
    float dz = p2->pos.z - p1->pos.z;

    float distanceSquared = dx * dx + dy * dy + dz * dz;

    float radiiSumSquared = (p1->size + p2->size) * (p1->size + p2->size);

    if (distanceSquared <= radiiSumSquared) {

        Vector3 tempVelocity = p1->velocity;
        changeVelocityVector(p1, p2->velocity);
        changeVelocityVector(p2, tempVelocity);

    }
}

void checkForBoundingBox(particle* p) {
    if (p->pos.x + p->size >= 200) {
        p->pos.x = 200 - p->size;
        changeVelocityVector(
            p, (Vector3){-p->velocity.x, p->velocity.y, p->velocity.z});
    } else if (p->pos.x - p->size <= -200) {
        p->pos.x = -200 + p->size;
        changeVelocityVector(
            p, (Vector3){-p->velocity.x, p->velocity.y, p->velocity.z});
    }

    if (p->pos.y + p->size >= 200) {
        p->pos.y = 200 - p->size;
        changeVelocityVector(
            p, (Vector3){p->velocity.x, -p->velocity.y, p->velocity.z});
    } else if (p->pos.y - p->size <= -200) {
        p->pos.y = -200 + p->size;
        changeVelocityVector(
            p, (Vector3){p->velocity.x, -p->velocity.y, p->velocity.z});
    }

    if (p->pos.z + p->size >= 200) {
        p->pos.z = 200 - p->size;
        changeVelocityVector(
            p, (Vector3){p->velocity.x, p->velocity.y, -p->velocity.z});
    } else if (p->pos.z - p->size <= -200) {
        p->pos.z = -200 + p->size;
        changeVelocityVector(
            p, (Vector3){p->velocity.x, p->velocity.y, -p->velocity.z});
    }
}