#include <stdio.h>
#include "maxwellsDemon.h"

void maxwellsDemonSim(Camera3D camera) {
    // Initializing Particles
    struct maxwellsParticle particles[PARTICLES_QUANTITY];
    for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
        Vector3 pos = {(float)GetRandomValue(
            -BOX_CONSTRAINT_X,
            BOX_CONSTRAINT_X),
       (float) GetRandomValue(
            -BOX_CONSTRAINT_Y,
            BOX_CONSTRAINT_Y),
        (float)GetRandomValue(
            -BOX_CONSTRAINT_Z,
            BOX_CONSTRAINT_Z)} ;
         Vector3 random_accel = {(float)GetRandomValue(-100, 100)/100.0f,
                                (float)GetRandomValue(-100, 100)/100.0f,
                                (float)GetRandomValue(-100, 100)/100.0f};
        int temp = GetRandomValue(MIN_TEMPERATURE, MAX_TEMPERATURE);
        Color particle_color = {
            (unsigned char)(255 * ((float)temp / 100.0f)),
            (unsigned char)0,
            (unsigned char)(255 * ((float)(MAX_TEMPERATURE - temp) / 100.0f)),
            255
        };
        int mass = GetRandomValue(1, 10); // in gms
        developMaxwellsParticle(&particles[i], pos, (Vector3){0.0f, 0.0f, 0.0f}, random_accel, particle_color, mass, temp);
    }


    while(!WindowShouldClose()) {
        UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
            for (int j = 0; j < PARTICLES_QUANTITY; j += 1) {
                checkForMaxwellsParticleCollision(&particles[i], &particles[j]);
            }
            checkForMaxwellsBoundingBox(&particles[i]);
            updateMaxwellsParticleVelocity(&particles[i]);
            updateMaxwellsParticlePosition(&particles[i]);
        }

        BeginMode3D(camera);

        DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, 400, 400, 400, RED);

        for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
           renderMaxwellsParticle(&particles[i]);
        }
        EndMode3D();

        DrawFPS(10, 40);

        EndDrawing();
    }
}
