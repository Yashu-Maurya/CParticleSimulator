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
    // brownianMotion(camera); // Uncomment for brownian motion without
    // collision. 
    // brownianMotionWithParticleCollision(camera); // Uncomment for
    // brownian motion with collision
    gravitySim(camera);
    return 0;
}
