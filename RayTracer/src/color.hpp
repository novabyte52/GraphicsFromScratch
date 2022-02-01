#pragma once

class Color
{
public:
    int r;
    int g;
    int b;
    
    Color() = default;
    Color(int r, int g, int b): r(r), g(g), b(b) {};

    void clamp();
};
