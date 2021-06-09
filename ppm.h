#pragma once
#include "rgb.h"

#define DEFAULTDIM  1500

class ppmimage {
    private:
        int height;
        int width;
        rgb *pixels;
    
    public:
        ppmimage(bool random);
        ppmimage(int height, int width);
        ppmimage(int height, int width, rgb * pixeldata);
        ~ppmimage();
        void render();
};