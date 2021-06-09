#pragma once
#include <cstdint>

class rgb {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
    
    public:
        rgb(bool random);
        rgb(int red, int green, int blue);
        void changeval(int r, int g, int b);
        ~rgb();
};