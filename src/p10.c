#include <stdio.h>
#include "structs.h"

int main() 
{   
    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");

    // reduce 2 times
    ImageRGB* i2 = rgb_reduce(i1, 2);
    printf("\nSaving 2 times reduced image to a file...\n");
    write_rgb(i2, "../out/p10-2x.ppm");
    printf("\nImage saved with sucess!\n");


    // reduce 4 times
    ImageRGB* i3 = rgb_reduce(i1, 4);
    printf("\nSaving 4 times reduced image to a file...\n");
    write_rgb(i3, "../out/p10-4x.ppm");
    printf("\nImage saved with sucess!\n");

    // reduce 8 times
    ImageRGB* i4 = rgb_reduce(i1, 8);
    printf("\nSaving 8 times reduced image to a file...\n");
    write_rgb(i4, "../out/p10-8x.ppm");
    printf("\nImage saved with sucess!\n");

    // expanding 2 times
    ImageRGB* i5 = rgb_expand(i1, 2);
    printf("\nSaving 2 times expanded image to a file...\n");
    write_rgb(i5, "../out/p10+2x.ppm");
    printf("\nImage saved with sucess!\n");

    // expanding 4 times
    ImageRGB* i6 = rgb_expand(i1, 4);
    printf("\nSaving 4 times expanded image to a file...\n");
    write_rgb(i6, "../out/p10+4x.ppm");
    printf("\nImage saved with sucess!\n");    


}