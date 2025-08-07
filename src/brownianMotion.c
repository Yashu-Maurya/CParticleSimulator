#include "brownianMotion.h"

void brownianMotion(Camera3D camera) {
    particle particles[PARTICLES_QUANTITY];

    // Initialize all particles
    for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
        Vector3 random_accel = {(float)GetRandomValue(-100, 100)/100.0f,
                                (float)GetRandomValue(-100, 100)/100.0f,
                                (float)GetRandomValue(-100, 100)/100.0f};
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
            checkForBoundingBox(&particles[i]);

            updateParticleVelocity(&particles[i]);
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

