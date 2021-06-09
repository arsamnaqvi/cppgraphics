#include <stdlib.h>
#include <time.h>
#include "ppm.h"
#include "rgb.h"

int main() {
    srand(time(0));
    ppmimage *out = new ppmimage(true);
    out->render();
    delete out;
}