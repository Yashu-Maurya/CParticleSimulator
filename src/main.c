#include "main.h"

#include "particle.h"

int main(void) {
    // Initialization
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WIDTH, HEIGHT, "BATA BING BATA BOOM");
    SetTargetFPS(FPS);

    // Camera Config
    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 200.0f, 200.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    ;
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    DisableCursor();
    Vector3 gravity = {0.0f, 9.8f, 0.0f};

    particle particles[PARTICLES_QUANTITY];

    for (int i = 0; i < PARTICLES_QUANTITY; i += 1) {
        developParticle(
            &particles[i],
            (Vector3){
                (float)GetRandomValue(-BOX_CONSTRAINT_X, BOX_CONSTRAINT_X),
                (float)GetRandomValue(-BOX_CONSTRAINT_Y, BOX_CONSTRAINT_Y),
                (float)GetRandomValue(-BOX_CONSTRAINT_Z,
                                      BOX_CONSTRAINT_Z)},  // pos
            (Vector3){0.0f, 0.0f, 0.0f},                   // velocity
            (Vector3){0.0f, 0.0f, 0.0f},                   // accel
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
            Vector3 random_accel = {(float)GetRandomValue(-100, 100) / 100.0f,
                                (float)GetRandomValue(-100, 100) / 100.0f,
                                (float)GetRandomValue(-100, 100) / 100.0f};
            changeParticlePosition(&particles[i], random_accel);
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

    return 0;
}