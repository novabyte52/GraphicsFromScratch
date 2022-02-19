#pragma once

#include "../math/vec3.hpp"
#include "../resource/color.hpp"

class Sphere
{
public:
    std::string name;
    Vec3 origin;
    double radius;
    Color color;
    int spec; // Specular exponent

    Sphere(std::string name, Vec3 origin, double radius, Color color, int spec)
        :name(name), origin(origin), radius(radius), color(color), spec(spec) {};
};
