#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    ImageRGB* croped = crop(image, 1, 1, 2, 2);
    write_rgb(croped, "cropped.ppm"); 
}