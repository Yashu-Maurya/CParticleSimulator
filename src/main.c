#include "main.h"
#include "brownianMotion.h"
#include "brownianMotionWithParticleCollision.h"

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
   
    brownianMotion(camera); // Uncomment for brownian motion without collision.
    // brownianMotionWithParticleCollision(camera);
    return 0;
}