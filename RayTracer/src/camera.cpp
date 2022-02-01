#include "camera.hpp"

Uint32 Camera::traceRay(double stepMin, Canvas* canvas, std::vector<Sphere> spheres, std::vector<Light*> lights)
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

    Vec3 P = Camera::position + Camera::direction * closestStep;
    Vec3 N = P - closestSphere->origin;
    N = N / N.length();
    Vec3 negativeDir = -1 * Camera::direction;
    closestSphere->color.r = closestSphere->color.r * computeLighting(P, N, Vec3(0, 0, -1), closestSphere->spec, lights);
    closestSphere->color.g = closestSphere->color.g * computeLighting(P, N, Vec3(0, 0, -1), closestSphere->spec, lights);
    closestSphere->color.b = closestSphere->color.b * computeLighting(P, N, Vec3(0, 0, -1), closestSphere->spec, lights);
    closestSphere->color.clamp();
    return canvas->encodeColor(closestSphere->color);
}

double* Camera::intersectRaySphere(Sphere* sphere)
{
    double* results = NULL;
    double r = sphere->radius;
    Vec3 CO = Vec3(Camera::position.x - sphere->origin.x, Camera::position.y - sphere->origin.y, Camera::position.z - sphere->origin.z);

    // May need to look at the first section and actually pass a direction
    // instead of modifying the cameras direction
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

double Camera::computeLighting(Vec3 point, Vec3 normal, Vec3 view, int spec, std::vector<Light*> lights)
{
    double intensity = 0;
    for (int i = 0; i < lights.size(); i++)
    {
        // If direction is (0, 0, 0) then it's ambient
        // Polymorphism ensures the correct direction function is called in any other case
        Vec3 L = lights[i]->getDirection(point);
        if (L.equals(Vec3(0, 0, 0)))
        {
            intensity += lights[i]->intensity;
        }
        else
        {
            // Diffuse
            double n_dot_l = normal.dot(L);
            if (n_dot_l > 0)
            {
                intensity += lights[i]->intensity * n_dot_l/(normal.length() * L.length());
            }

            // Specular
            if (spec != -1)
            {
                Vec3 R = 2 * normal * normal.dot(L) - L;
                double r_dot_v = R.dot(view);
                if (r_dot_v > 0)
                {
                    intensity += lights[i]->intensity * pow(r_dot_v / (R.length() * view.length()), spec);
                }
            }
        }
    }

    return intensity;
}
