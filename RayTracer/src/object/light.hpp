#pragma once

#include "../math/vec3.hpp"

class Light
{
public:
    double intensity;

    Light(double intensity): intensity(intensity) {};

    virtual Vec3 getDirection(Vec3 point);
};

class PointLight: public Light
{
public:
    Vec3 position;

    PointLight(Vec3 position, double intensity): position(position), Light(intensity) {};

    Vec3 getDirection(Vec3 point);
};

class DirectionalLight: public Light
{
public:
    Vec3 direction;

    DirectionalLight(Vec3 direction, double intensity): direction(direction), Light(intensity) {};

    Vec3 getDirection(Vec3 point);
};