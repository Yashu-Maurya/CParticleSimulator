#ifndef maxwellsParticle_h
#define maxwellsParticle_h
#include "particle.h"

typedef struct maxwellsParticle {
    struct particle particle;
    double mass;
    double temperature;
} maxwellsParticle;

void developMaxwellsParticle(maxwellsParticle *p, Vector3 pos, Vector3 velocity,
                        Vector3 acceleration, Color color, double mass,
                        double temperature);
void renderMaxwellsParticle(maxwellsParticle *p);
void checkForMaxwellsParticleCollision(maxwellsParticle *p1, maxwellsParticle *p2);
void updateMaxwellsParticleVelocity(maxwellsParticle *p);
void updateMaxwellsParticlePosition(maxwellsParticle *p);
void checkForMaxwellsBoundingBox(maxwellsParticle *p);
#endif
