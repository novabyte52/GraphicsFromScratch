#pragma once

#include "vec3.hpp"
#include "color.hpp"

class Sphere
{
public:
    Vec3 origin;
    double radius;
    Color color;

    Sphere(Vec3 origin, double radius, Color color): origin(origin), radius(radius), color(color) {};
};
