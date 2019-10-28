#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    ImageRGB* shrink = shrink_rgb(image, 2);
    write_rgb(shrink, "shrink.ppm");
}