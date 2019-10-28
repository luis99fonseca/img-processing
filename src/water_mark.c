#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    create_water_mark(image, 100, 150);
    write_rgb(image, "watter_mark.ppm"); 
}