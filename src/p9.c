#include <stdio.h>
#include "structs.h"

/**
 * Simple program to rotate a grayscale image (to left and rigth) . 
*/
int main() 
{   
    //Note: its required for p2.c to be run beforehand
    printf("\nLoading first Grayscale image...\n");
    ImageGray* i1 = read_gray("../out/p2.ppm");
    printf("\nImage load with success!\n");

    grayscale_rotate_right(i1);

    printf("\nSaving -45º rotated image to a file...\n");
    write_gray(i1, "../out/p9-45.ppm");
    printf("\nImage saved with sucess!\n");

    grayscale_rotate_right(i1);

    printf("\nSaving -90º rotated image to a file...\n");
    write_gray(i1, "../out/p9-90.ppm");
    printf("\nImage saved with sucess!\n");

    grayscale_rotate_right(i1);
    grayscale_rotate_right(i1);

    printf("\nSaving -360º rotated image to a file...\n");
    write_gray(i1, "../out/p9-360.ppm");
    printf("\nImage saved with sucess!\n");

    grayscale_rotate_left(i1);
    grayscale_rotate_left(i1);
    grayscale_rotate_left(i1);

    printf("\nSaving 135º rotated image to a file...\n");
    write_gray(i1, "../out/p9+135.ppm");
    printf("\nImage saved with sucess!\n");


}