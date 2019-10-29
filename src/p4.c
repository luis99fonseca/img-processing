#include <stdio.h>
#include "structs.h"

int main() 
{   
    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");

    change_rgb_intensity(i1, 120);

    printf("\nSaving first intensity increased RGB image to a new file...\n");
    write_rgb(i1, "../out/p4_intensity1.ppm");
    printf("\nImage saved with success!");

    change_rgb_intensity(i1, -100);

    printf("\nSaving second intensity increased RGB image to a new file...\n");
    write_rgb(i1, "../out/p4_intensity2.ppm");
    printf("\nImage saved with success!");

    change_rgb_intensity(i1, 200);

    printf("\nSaving third intensity increased RGB image to a new file...\n");
    write_rgb(i1, "../out/p4_intensity3.ppm");
    printf("\nImage saved with success!");

    printf("\nLoading first grayscale image...\n");
    ImageGray* i2 = read_gray("../out/p2.ppm");
    printf("\nImage load with success!\n");

    change_grayscale_intensity(i2, -150);

    printf("\nSaving first intensity increased grayscale image to a new file...\n");
    write_gray(i2, "../out/p4_intensity4.ppm");
    printf("\nImage saved with success!");

}