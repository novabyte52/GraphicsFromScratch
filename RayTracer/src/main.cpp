#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <vector>

#include "canvas.hpp"
#include "camera.hpp"
#include "vec3.hpp"
#include "color.hpp"
#include "sphere.hpp"

int main(int argc, char* args[])
{
    Canvas* canvas = new Canvas(600, 600);
    // Fill the canvas white
    int error = SDL_FillRect(canvas->_surface, NULL, canvas->encodeColor(255, 255, 255));
    // Update the canvas
    SDL_UpdateWindowSurface(canvas->_window);

    // Populating a vector with test spheres to render
    std::vector<Sphere> spheres;
    spheres.push_back(Sphere(Vec3(0, -1, 3), 1, Color(255, 0, 0)));
    spheres.push_back(Sphere(Vec3(2, 0, 4), 1, Color(0, 0, 255)));
    spheres.push_back(Sphere(Vec3(-2, 0, 4), 1, Color(0, 255, 0)));

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
            Uint32 color = cam.traceRay(1, canvas, spheres);

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