#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    ImageRGB* expanded = expand(image, 2);
    write_rgb(expanded, "../out/expanded.ppm");
}