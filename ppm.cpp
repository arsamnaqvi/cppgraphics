#include <iostream>
#include <fstream>
#include "ppm.h"

ppmimage::ppmimage(bool random)
{
    this->height = DEFAULTDIM;
    this->width = DEFAULTDIM;
    this->pixels = (rgb *)malloc(DEFAULTDIM * DEFAULTDIM * sizeof(rgb));
    
    for (int i = 0; i < DEFAULTDIM; i++) {
        for (int j = 0; j < DEFAULTDIM; j++) {
            this->pixels[(i*DEFAULTDIM)+j] = rgb(random);
        }
    }
}

ppmimage::ppmimage(int height, int width)
{
    this->height = height;
    this->width = width;
    this->pixels = (rgb *)malloc(height * width * sizeof(rgb));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->pixels[(i*width)+j] = rgb(false);
        }
    }
}

ppmimage::ppmimage(int height, int width, rgb * pixeldata)
{
    this->height = height;
    this->width = width;
    this->pixels = (rgb *)malloc(height * width * sizeof(rgb));
    for (int i = 0; i < height*width; i++) {
        this->pixels[i] = pixeldata[i];
    }
}

ppmimage::~ppmimage()
{
    free(this->pixels);
}

void ppmimage::render()
{
    std::ofstream out("image.ppm");
    //std::cout << "not in if stmnt" << std::endl;
    if (out.is_open()) {
        //std::cout << "in if stmnt" << std::endl;
        out << "P3" << std::endl;
        out << (int) this->width << ' ';
        out << (int) this->height << std::endl;
        out << 255 << std::endl;
        for (int i = 0; i < this->height*this->width; i++) {
            out << (int) this->pixels[i].r << ' ';
            out << (int) this->pixels[i].g << ' ';
            out << (int) this->pixels[i].b << std::endl;
        }
    }
    out.close();
}