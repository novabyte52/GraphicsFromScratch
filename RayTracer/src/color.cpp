#include "color.hpp"

void Color::clamp()
{
    if (Color::r < 0) Color::r = 0;
    if (Color::r > 255) Color::r = 255;

    if (Color::g < 0) Color::g = 0;
    if (Color::g > 255) Color::g = 255;
    
    if (Color::b < 0) Color::b = 0;
    if (Color::b > 255) Color::b = 255;
}