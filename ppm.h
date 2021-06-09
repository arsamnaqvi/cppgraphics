#pragma once
#include "rgb.h"


class ppmimage {
    private:
        int height;
        int width;
        rgb *pixels;
    
    public:
        ppmimage();
        ppmimage(int height, int width);
        ppmimage(int height, int width, rgb * pixeldata);
        ~ppmimage();
        void render();
};