#include "particle.h"

void developParticle(particle* p, Vector3 pos, Vector3 velocity, Vector3 acceleration, Color color, float size) {
                        p->pos = pos;
                        p->velocity = velocity;
                        p->acceleration = acceleration;
                        p->color = color;
                        p->size = size;
                     }

void changeParticlePosition(particle* p, Vector3 acceleration) {
    if(!p) {
        return;
    }
    float dt = 1/FPS;
    
}

void renderParticle(particle* p) {
    if(!p){
        return;
    }
    DrawSphere(p->pos,p->size,p->color);
}