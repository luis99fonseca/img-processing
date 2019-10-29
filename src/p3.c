#include <stdio.h>
#include "structs.h"

int main() 
{   
    printf("\nLoading first grayscale image...\n");
    ImageGray* i1 = read_gray("../out/gray_image.ppm");
    printf("\nImage load with success!\n");

    printf("\nConverting grayscale to binary...\n");
    ImageBin* bin_image = convert_grayToBin(i1, 128);
    printf("\nConverted image with success!\n");

    printf("\nSaving new binary image to a file...\n");
    write_bin(bin_image, "../out/bin_image.ppm");
    printf("\nImage saved with sucess!\n");
}