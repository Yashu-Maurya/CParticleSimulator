#ifndef main_h
    #define main_h
    enum Choices {
    BROWNIAN_MOTION,
    BROWNIAN_MOTION_WITH_PARTICLE_COLLISION,
    GRAVITY_SIMULATION,
    MAXWELLS_DEMON_SIMULATION
};


#include <stdio.h>
#include <raylib.h>
#include <math.h>
#include <raymath.h>

#define WIDTH 1280
#define HEIGHT 720
#define PARTICLES_QUANTITY 100
#define BOX_CONSTRAINT_X 200
#define BOX_CONSTRAINT_Y 200
#define BOX_CONSTRAINT_Z 200
#define FPS 120
#endif

