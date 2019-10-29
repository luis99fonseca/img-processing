#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int main(int argc, char *argv[]) 
{   
    
    //Note: its required for p2.c to be run beforehand
    printf("\nLoading first grayscale image...\n");
    ImageGray* i1 = read_gray("../out/p2.ppm");
    printf("\nImage load with success!\n");

    printf("\nConverting grayscale to binary...\n");
    ImageBin* bin_image = convert_grayToBin(i1, 128);
    printf("\nConverted image with success!\n");

    printf("\nSaving new binary image to a file...\n");
    write_bin(bin_image, "../out/p3.ppm");
    printf("\nImage saved with sucess!\n");

    printf("\nLoading the same binary image...\n");
    ImageBin* bin_image2 = read_bin("../out/p3.ppm");
    printf("\nImage load with success!\n");

    printf("\nSaving binary image to a new file...\n");
    write_bin(bin_image2, "../out/p3_copy.ppm");
    printf("\nImage saved with sucess!\n");
}