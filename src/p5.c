#include <stdio.h>
#include "structs.h"

/**
 * Simple program to place a watermark in RGB and grayscale images.
*/
int main() 
{   
    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");

    rgb_water_mark(i1, 181, 206);

    printf("\nSaving RGB image with watermark to a new file...\n");
    write_rgb(i1, "../out/p5_water_mark1.ppm");
    printf("\nImage saved with success!");

    //Note: its required for p2.c to be run beforehand
    printf("\nLoading first Grayscale image...\n");
    ImageGray* i2 = read_gray("../out/p2.ppm");
    printf("\nImage load with success!\n");

    grayscale_water_mark(i2, 362, 412);

    printf("\nSaving Grayscale image with watermark to a new file...\n");
    write_gray(i2, "../out/p5_water_mark2.ppm");
    printf("\nImage saved with success!");

}