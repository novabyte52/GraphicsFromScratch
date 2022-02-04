#pragma once

#include <SDL2/SDL.h>

#include "../resource/color.hpp"
#include "../math/vec3.hpp"
#include "viewport.hpp"

class Canvas
{
public:
    SDL_Window* _window = NULL;
    SDL_Surface* _surface = NULL;

    Viewport view;

    int _screen_w;
    int _screen_h;
    int _bytes_per_pixel = 0;
    int _pitch;
    int _h;

    Canvas() = default;
    Canvas(int screen_width, int screen_height);

    void putPixel(int x, int y, int color);

    Uint32 encodeColor(int r, int g, int b);
    Uint32 encodeColor(Color color);

    Vec3 canvasToViewport(double x, double y);

    void testPutPixel();

    ~Canvas();
};
