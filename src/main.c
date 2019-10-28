#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    ImageRGB* rotated = rotate_right(image);
    write_rgb(rotated, "rotated_right.ppm"); 
}