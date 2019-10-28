#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    ImageRGB* cropped = crop(image, 0,0,512,300);
    write_rgb(cropped, "cropped.ppm"); 
}