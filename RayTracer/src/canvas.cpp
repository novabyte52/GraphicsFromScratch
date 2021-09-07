#include "canvas.hpp"

Canvas::Canvas(int screen_width, int screen_height)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        // Create window
        Canvas::_window = SDL_CreateWindow(
            "Computer Graphics From Scratch",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            screen_width,
            screen_height,
            SDL_WINDOW_SHOWN
        );

        if( Canvas::_window == NULL )
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            // Get surface (a.k.a canvas)
            Canvas::_surface = SDL_GetWindowSurface(Canvas::_window);
            Canvas::_screen_w = screen_width;
            Canvas::_screen_h = screen_height;
            Canvas::_pitch = Canvas::_surface->pitch;
            Canvas::_h = Canvas::_surface->h;
            Canvas::_bytes_per_pixel = Canvas::_surface->format->BytesPerPixel;
        }
    }

    Canvas::view = Viewport(1, 1);
}

// Place a pixel of the specified color on the screen in the specified location
// assuming the origin is in the center of the screen
void Canvas::putPixel(int x, int y, int color)
{
    Uint8 *row8;
    Uint16 *row16;
    Uint32 *row32;

    int Sy = (Canvas::_screen_h / 2 - y) * Canvas::_pitch;
    int Sx = (Canvas::_screen_w / 2 + x) * Canvas::_bytes_per_pixel;

    // Don’t allow overwriting boundaries of the screen
    // Clamping from -299 to 300 on both x and y or else I overflow the screen
    if (x < -(Canvas::_screen_w / 2) + 1 || x > (Canvas::_screen_w / 2) || y < -(Canvas::_screen_h / 2) + 1 || y > (Canvas::_screen_h / 2)) return;

    switch (Canvas::_bytes_per_pixel)
    {
        case 1:
            row8 = (Uint8 *) (Canvas::_surface->pixels + Sy + Sx);
            *row8 = (Uint8) color;
            break;

        case 2:
            row16 = (Uint16 *) (Canvas::_surface->pixels + Sy + Sx);
            *row16 = (Uint16) color;
            break;

        case 4:
            row32 = (Uint32 *) (Canvas::_surface->pixels + Sy + Sx);
            *row32 = (Uint32) color;
            break;
    }
}

// Maps an RGB triple to an opaque pixel value for your canvas
Uint32 Canvas::encodeColor(int r, int g, int b)
{
    return SDL_MapRGB(Canvas::_surface->format, r, g, b);
}

// Maps a Color object to an opaque pixel value for your canvas
Uint32 Canvas::encodeColor(Color color)
{
    return SDL_MapRGB(Canvas::_surface->format, color.r, color.g, color.b);
}

Vec3 Canvas::canvasToViewport(double x, double y)
{
    return Vec3(x * Canvas::view.width / Canvas::_screen_w, y * Canvas::view.height / Canvas::_screen_h, 1);
}

// Output 4 small dots near the center of the screen
void Canvas::testPutPixel()
{
    Canvas::putPixel(10, 10, Canvas::encodeColor(255, 0, 0));
    Canvas::putPixel(11, 10, Canvas::encodeColor(255, 0, 0));
    Canvas::putPixel(10, 11, Canvas::encodeColor(255, 0, 0));
    Canvas::putPixel(11, 11, Canvas::encodeColor(255, 0, 0));

    Canvas::putPixel(-10, 10, Canvas::encodeColor(0, 255, 0));
    Canvas::putPixel(-11, 10, Canvas::encodeColor(0, 255, 0));
    Canvas::putPixel(-10, 11, Canvas::encodeColor(0, 255, 0));
    Canvas::putPixel(-11, 11, Canvas::encodeColor(0, 255, 0));

    Canvas::putPixel(-10, -10, Canvas::encodeColor(0, 0, 255));
    Canvas::putPixel(-11, -10, Canvas::encodeColor(0, 0, 255));
    Canvas::putPixel(-10, -11, Canvas::encodeColor(0, 0, 255));
    Canvas::putPixel(-11, -11, Canvas::encodeColor(0, 0, 255));

    Canvas::putPixel(10, -10, Canvas::encodeColor(255, 0, 128));
    Canvas::putPixel(11, -10, Canvas::encodeColor(255, 0, 128));
    Canvas::putPixel(10, -11, Canvas::encodeColor(255, 0, 128));
    Canvas::putPixel(11, -11, Canvas::encodeColor(255, 0, 128));
}

Canvas::~Canvas()
{
    SDL_DestroyWindow(Canvas::_window);

    SDL_Quit();
}
