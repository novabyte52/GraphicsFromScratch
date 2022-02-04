#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <vector>

#include "visual/canvas.hpp"
#include "visual/camera.hpp"
#include "math/vec3.hpp"
#include "resource/color.hpp"
#include "object/sphere.hpp"

int main(int argc, char* args[])
{
    Canvas* canvas = new Canvas(600, 600);
    // Fill the canvas white
    int error = SDL_FillRect(canvas->_surface, NULL, canvas->encodeColor(255, 255, 255));
    // Update the canvas
    SDL_UpdateWindowSurface(canvas->_window);

    // Populating a vector with test spheres to render
    std::vector<Sphere> spheres;
    spheres.push_back(Sphere(Vec3(0, -1, 3), 1, Color(255, 0, 0), 500));
    spheres.push_back(Sphere(Vec3(2, 0, 4), 1, Color(0, 0, 255), 500));
    spheres.push_back(Sphere(Vec3(-2, 0, 4), 1, Color(0, 255, 0), 10));
    // Big yellow sphere
    spheres.push_back(Sphere(Vec3(0, -5001, 0), 5000, Color(255, 255, 0), 1000));

    // Populating a vector with test lights to render
    Light ambient = Light(0.2);
    PointLight point = PointLight(Vec3(2, 1, 0), 0.6);
    DirectionalLight dir = DirectionalLight(Vec3(1, 4, 4), 0.2);
    std::vector<Light*> lights;
    lights.push_back(&ambient);
    lights.push_back(&point);
    lights.push_back(&dir);

    Camera cam = Camera();

    SDL_LockSurface(canvas->_surface);
    // Looping from -299 to 300 on both x and y or else I overflow the screen
    // (Well, putPixel has a clamp, and that has been adjusted as well)
    for (int x = -(canvas->_screen_w/2) + 1; x <= (canvas->_screen_w/2); x++)
    {
        for (int y = -(canvas->_screen_h/2) + 1; y <= (canvas->_screen_h/2); y++)
        {
            // Determine the square on the viewport grid corresponding to this pixel on the canvas
            cam.direction = canvas->canvasToViewport(x, y);

            // Determine the color seen through that square on the viewport
            // Hard coding viewCoord as direction since cam position is 0
            Uint32 color = cam.traceRay(1, canvas, spheres, lights);

            // Paint the pixel of the canvas with that color
            canvas->putPixel(x, y, color);
        }
    }
    SDL_UnlockSurface(canvas->_surface);

    // Update the canvas
    SDL_UpdateWindowSurface(canvas->_window);
    // Wait ten seconds
    SDL_Delay(10 * 1000);
}
