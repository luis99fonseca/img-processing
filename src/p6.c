#include <stdio.h>
#include "structs.h"
#include "filters.c"

int main(){

    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/bike3.ppm");
    printf("\nImage load with success!\n");

    printf("\nConverting first image to grayscale...\n");
    ImageGray* gray_image = convert_rbgToGray(i1);
    printf("\nConverted image with success!\n");

    printf("\nApplying filter to RGB image...\n");
    apply_filter_toRGB(i1, edgeDetection1);

    printf("\nSaving new RGB image to a file...\n");
    write_rgb(i1, "../out/p06-1.ppm");
    printf("\nImage saved with sucess!\n");

    printf("\nApplying filter to Grayscale image...\n");
    apply_filter_toGray(gray_image, edgeDetection1);

    printf("\nSaving new grayscale image to a file...\n");
    write_gray(gray_image, "../out/p06-2.ppm");
    printf("\nImage saved with sucess!\n");

}