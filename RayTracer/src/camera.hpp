#pragma once

#include <math.h>
#include <vector>

#include "vec3.hpp"
#include "sphere.hpp"
#include "canvas.hpp"

class Camera
{
public:
    Vec3 position = Vec3(0, 0, 0);
    Vec3 direction = Vec3(0, 0, 1);
    double max_d = DBL_MAX;

    Camera() = default;
    Camera(Vec3 position, Vec3 direction, double maxRenderDistance)
        : position(position), direction(direction), max_d(maxRenderDistance) {};

    Uint32 traceRay(double stepMin, Canvas* canvas, std::vector<Sphere> spheres);
    double* intersectRaySphere(Sphere* sphere);
};
