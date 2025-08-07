#include "gravity.h"

// declaring functions.
void gravitySim(Camera3D camera) {
    particle particles[PARTICLES_QUANTITY];

    Vector3 gravity_acceleration = (Vector3){0.0f, -9.8f, 0.0f};

    // Initialize all particles
    for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
        developParticle(
            &particles[i],
            (Vector3){
                (float)GetRandomValue(-BOX_CONSTRAINT_X, BOX_CONSTRAINT_X),
                (float)GetRandomValue(0, BOX_CONSTRAINT_Y),
                (float)GetRandomValue(-BOX_CONSTRAINT_Z,
                                      BOX_CONSTRAINT_Z)},  // pos
            (Vector3){0.0f, 0.0f, 0.0f},                   // velocity
            (Vector3)gravity_acceleration,                 // accel
            (Color){(unsigned char)GetRandomValue(0, 255),
                    (unsigned char)GetRandomValue(0, 255),
                    (unsigned char)GetRandomValue(0, 255), 255},  // color (obv)
            (float)GetRandomValue(4, 5)                           // radius
        );
    }

    while (!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
            for (int j = i; j < PARTICLES_QUANTITY; j += 1) {
                checkForCollision(&particles[i],&particles[j]);
            }
            checkForBoundingBox(&particles[i]);
            
            updateParticleVelocity(&particles[i]);
            updateParticlePosition(&particles[i]);
        }
        BeginMode3D(camera);

        DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, BOX_CONSTRAINT_X * 2,
                      BOX_CONSTRAINT_Y * 2, BOX_CONSTRAINT_Z * 2, RED);

        for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
            renderParticle(&particles[i]);
        }
        EndMode3D();

        DrawFPS(10, 40);

        EndDrawing();
    }
    CloseWindow();
}
