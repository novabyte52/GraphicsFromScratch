#include "camera.hpp"

Uint32 Camera::traceRay(double stepMin, Canvas* canvas, std::vector<Sphere> spheres)
{
    double closestStep = Camera::max_d;
    Sphere* closestSphere = NULL;

    for (int i = 0; i < spheres.size(); i++)
    {
        double* steps = intersectRaySphere(&spheres[i]);
        if ((steps[0] < Camera::max_d && steps[0] > stepMin) && steps[0] < closestStep)
        {
            closestStep = steps[0];
            closestSphere = &spheres[i];
        }

        if ((steps[1] < Camera::max_d && steps[1] > stepMin) && steps[1] < closestStep)
        {
            closestStep = steps[1];
            closestSphere = &spheres[i];
        }
    }

    if (closestSphere == NULL)
    {
        return canvas->encodeColor(255, 255, 255);
    }

    return canvas->encodeColor(closestSphere->color);
}

double* Camera::intersectRaySphere(Sphere* sphere)
{
    double* results = NULL;
    double r = sphere->radius;
    Vec3 CO = Vec3(Camera::position.x - sphere->origin.x, Camera::position.y - sphere->origin.y, Camera::position.z - sphere->origin.z);

    double a = Camera::direction.dot(Camera::direction);
    double b = 2 * CO.dot(Camera::direction);
    double c = CO.dot(CO) - (r * r);

    double discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0)
    {
        results = new double[2] {Camera::max_d, Camera::max_d};
        return results;
    }

    results = new double[2] {(-b + sqrt(discriminant)) / (2 * a), (-b - sqrt(discriminant)) / (2 * a)};
    return results;
}
