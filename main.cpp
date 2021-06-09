#include "ppm.h"
#include "rgb.h"

int main() {
    ppmimage *out = new ppmimage();
    out->render();
    delete out;
}