#include <stdio.h>
#include "structs.h"
#include "filters.c"

/**
 * Simple program to crop a RGB image, apply a filter and overlap the cropped area in the original image.
*/
int main(){

    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");


    ImageRGB* i2 = crop_rgb(i1, 225, 230, 400, 400);
    apply_filter_toRGB(i2,edgeDetection2);
    overlap_rgb(i1, i2, 225, 230);

    write_rgb(i1, "../out/p07-1.ppm");


}