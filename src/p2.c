#include <stdio.h>
#include "structs.h"

int main() 
{   
    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");

    printf("\nConverting first image to grayscale...\n");
    ImageGray* gray_image = convert_rbgToGray(i1);
    printf("\nConverted image with success!\n");

    printf("\nSaving new grayscale image to a file...\n");
    write_gray(gray_image, "../out/gray_image.ppm");
    printf("\nImage saved with sucess!\n");
}