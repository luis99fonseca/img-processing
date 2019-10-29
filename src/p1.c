#include <stdio.h>
#include "structs.h"

/**
 * Simple program to load 3 RGB images and save them in a new file.
*/
int main() 
{   
    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");
    
    printf("\nLoading second RGB image...\n");
    ImageRGB* i2 = read_rgb("../img/monarch.ppm");
    printf("\nImage load with success!\n");

    printf("\nLoading third RGB image...\n");
    ImageRGB* i3 = read_rgb("../img/bike3.ppm");
    printf("\nImage load with success!\n");

    printf("\nSaving first RGB image to a new file...\n");
    write_rgb(i1, "../out/p1_i1.ppm");
    printf("\nImage saved with success!");

    printf("\nSaving first RGB image to a new file...\n");
    write_rgb(i2, "../out/p1_i2.ppm");
    printf("\nImage saved with success!");

    printf("\nSaving first RGB image to a new file...\n");
    write_rgb(i3, "../out/p1_i3.ppm");
    printf("\nImage saved with success!");

}