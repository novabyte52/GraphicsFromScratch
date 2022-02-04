#pragma once

#include "../math/vec3.hpp"

class Viewport
{
public:
    double width;
    double height;
    Vec3 direction;

    Viewport() = default;
    Viewport(double width, double height): width(width), height(height) {};
};
