#include "brownianMotionWithParticleCollision.h"

void brownianMotionWithParticleCollision(Camera3D camera) {
    particle particles[PARTICLES_QUANTITY];

    // Initialize all particles
    for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
        Vector3 random_accel = {(float)GetRandomValue(-100, 100),
                                (float)GetRandomValue(-100, 100),
                                (float)GetRandomValue(-100, 100)};
        developParticle(
            &particles[i],
            (Vector3){
                (float)GetRandomValue(-BOX_CONSTRAINT_X, BOX_CONSTRAINT_X),
                (float)GetRandomValue(-BOX_CONSTRAINT_Y, BOX_CONSTRAINT_Y),
                (float)GetRandomValue(-BOX_CONSTRAINT_Z,
                                      BOX_CONSTRAINT_Z)},  // pos
            (Vector3){0.0f, 0.0f, 0.0f},                   // velocity
            (Vector3)random_accel,                         // accel
            (Color){(unsigned char)GetRandomValue(0, 255),
                    (unsigned char)GetRandomValue(0, 255),
                    (unsigned char)GetRandomValue(0, 255), 255},  // color (obv)
            (float)GetRandomValue(1, 5)                           // radius
        );
    }

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
            for (int j = 0; j < PARTICLES_QUANTITY; j += 1) {
                // for each particle to the initial particle.
                Vector3 distanceVectorP1toP2 = Vector3Subtract(
                    Vector3AddValue(particles[i].pos, particles[i].size),
                    Vector3SubtractValue(particles[j].pos, particles[j].size));
                if ((distanceVectorP1toP2.x < 0 ? -distanceVectorP1toP2.x
                                                : distanceVectorP1toP2.x) <=
                    0) {  // Getting the absolute value of distance between two
                          // particles. on X-Axis here.
                    changeVelocityVector(&particles[i],
                                         (Vector3){
                                             -particles[i].velocity.x,
                                             particles[i].velocity.y,
                                             particles[i].velocity.z,
                                         });
                    changeParticleAcceleration(
                        &particles[i], (Vector3){-particles[i].acceleration.x,
                                                 particles[i].acceleration.y,
                                                 particles[i].acceleration.z});
                    updateParticleVelocity(&particles[i]);

                    changeVelocityVector(&particles[j],
                                         (Vector3){
                                             -particles[j].velocity.x,
                                             particles[j].velocity.y,
                                             particles[j].velocity.z,
                                         });
                    changeParticleAcceleration(
                        &particles[j], (Vector3){-particles[j].acceleration.x,
                                                 particles[j].acceleration.y,
                                                 particles[j].acceleration.z});
                    updateParticleVelocity(&particles[j]);
                }
                if ((distanceVectorP1toP2.y < 0
                         ? -distanceVectorP1toP2.y
                         : distanceVectorP1toP2.y) <= 0) {
                    changeVelocityVector(&particles[i],
                                         (Vector3){
                                             particles[i].velocity.x,
                                             -particles[i].velocity.y,
                                             particles[i].velocity.z,
                                         });
                    changeParticleAcceleration(
                        &particles[i], (Vector3){particles[i].acceleration.x,
                                                 -particles[i].acceleration.y,
                                                 particles[i].acceleration.z});
                    updateParticleVelocity(&particles[i]);

                    changeVelocityVector(&particles[j],
                                         (Vector3){
                                             particles[j].velocity.x,
                                             -particles[j].velocity.y,
                                             particles[j].velocity.z,
                                         });
                    changeParticleAcceleration(
                        &particles[j], (Vector3){particles[j].acceleration.x,
                                                 -particles[j].acceleration.y,
                                                 particles[j].acceleration.z});
                    updateParticleVelocity(&particles[j]);
                }
                if ((distanceVectorP1toP2.z < 0
                         ? -distanceVectorP1toP2.z
                         : distanceVectorP1toP2.z) <= 0) {
                    changeVelocityVector(&particles[i],
                                         (Vector3){
                                             particles[i].velocity.x,
                                             particles[i].velocity.y,
                                             -particles[i].velocity.z,
                                         });
                    changeParticleAcceleration(
                        &particles[i], (Vector3){particles[i].acceleration.x,
                                                 particles[i].acceleration.y,
                                                 -particles[i].acceleration.z});
                    updateParticleVelocity(&particles[i]);

                    changeVelocityVector(&particles[j],
                                         (Vector3){
                                             particles[j].velocity.x,
                                             particles[j].velocity.y,
                                             -particles[j].velocity.z,
                                         });
                    changeParticleAcceleration(
                        &particles[j], (Vector3){particles[j].acceleration.x,
                                                 particles[j].acceleration.y,
                                                 -particles[j].acceleration.z});
                    updateParticleVelocity(&particles[j]);
                }
            }

            // Collision detection for Bounded Box.
            if (particles[i].pos.x >= 200 || particles[i].pos.x <= -200) {
                changeVelocityVector(
                    &particles[i],
                    (Vector3){-particles[i].velocity.x, particles[i].velocity.y,
                              particles[i].velocity.z});
                changeParticleAcceleration(
                    &particles[i], (Vector3){-particles[i].acceleration.x,
                                             particles[i].acceleration.y,
                                             particles[i].acceleration.z});
                updateParticleVelocity(&particles[i]);
            }
            if (particles[i].pos.y >= 200 || particles[i].pos.y <= -200) {
                changeVelocityVector(
                    &particles[i],
                    (Vector3){particles[i].velocity.x, -particles[i].velocity.y,
                              particles[i].velocity.z});
                changeParticleAcceleration(
                    &particles[i], (Vector3){particles[i].acceleration.x,
                                             -particles[i].acceleration.y,
                                             particles[i].acceleration.z});
                updateParticleVelocity(&particles[i]);
            }
            if (particles[i].pos.z >= 200 || particles[i].pos.z <= -200) {
                changeVelocityVector(
                    &particles[i],
                    (Vector3){particles[i].velocity.x, particles[i].velocity.y,
                              -particles[i].velocity.z});
                changeParticleAcceleration(
                    &particles[i], (Vector3){particles[i].acceleration.x,
                                             particles[i].acceleration.y,
                                             -particles[i].acceleration.z});
                updateParticleVelocity(&particles[i]);
            }
            updateParticlePosition(&particles[i]);
        }
        BeginMode3D(camera);

        DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, 400, 400, 400, RED);

        for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
            renderParticle(&particles[i]);
        }
        EndMode3D();

        DrawFPS(10, 40);

        EndDrawing();
    }
    CloseWindow();
}
