#include "rgb.h"

rgb::rgb()
{
    r = 255;
    g = 55;
    b = 55;
}

rgb::rgb(int red, int green, int blue): r(red), g(green), b(blue)
{

}

void rgb::changeval(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

rgb::~rgb()
{

}
