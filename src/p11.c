#include <stdio.h>
#include "structs.h"

/**
 * Simple program to crop, invert vertically and horizontally, place water mark and overlap a RGB image.
*/
int main() 
{   
    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");

    ImageRGB* i2 = crop_rgb(i1, 150, 150, 400, 400);

    rgb_invert_vertically(i2);

    change_rgb_intensity(i2, -100);

    rgb_water_mark(i2, 0, 0);

    ImageRGB* i3 = rgb_reduce(i2, 2);

    rgb_invert_horizontally(i3);

    overlap_rgb(i1, i3, 0, 0);

    printf("\nSaving first RGB image to a new file...\n");
    write_rgb(i1, "../out/p11.ppm");
    printf("\nImage saved with success!\n");
}