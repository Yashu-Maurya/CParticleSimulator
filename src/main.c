#include "main.h"

#include "brownianMotion.h"
#include "brownianMotionWithParticleCollision.h"
#include "gravity.h"

int main(void) {

    // Initialization
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WIDTH, HEIGHT, "BATA BING BATA BOOM");
    SetTargetFPS(FPS);

    // Camera Config
    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 200.0f, 200.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.projection = CAMERA_PERSPECTIVE;
    camera.fovy = 90.0f;

    DisableCursor();

    printf("0: Brownian Motion\n 1: Brownian Motion with Collision\n 2: Gravity Simulation\n 3: Maxwell's Demon Simulation\nEnter your Choice: ");
    enum Choices choice;
    scanf("%d", &choice);

    switch (choice) {
        case BROWNIAN_MOTION:
            brownianMotion(camera);
            break;
        case BROWNIAN_MOTION_WITH_PARTICLE_COLLISION:
            brownianMotionWithParticleCollision(camera);
            break;
        case GRAVITY_SIMULATION:
            gravitySim(camera);
            break;
        case MAXWELLS_DEMON_SIMULATION:
            maxwellsDemonSim(camera);
            break;
        default:
            printf("Invalid choice\n");
            break;
    };
    gravitySim(camera);
    return 0;
}
