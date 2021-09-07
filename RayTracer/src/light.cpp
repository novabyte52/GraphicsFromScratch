#include "light.hpp"

Vec3 Light::getDirection(Vec3 point)
{
    return Vec3(0, 0, 0);
}

Vec3 PointLight::getDirection(Vec3 point)
{
    return PointLight::position - point;
}

Vec3 DirectionalLight::getDirection(Vec3 point)
{
    return DirectionalLight::direction;
}