#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    ImageRGB* cropped = crop(image, 100, 100, 300, 300);
    invert_horizontally(cropped);
    change_rgb_intensity(cropped, -100);
    overlap(image, cropped, 100, 100);
    write_rgb(image, "overlap.ppm"); 
}