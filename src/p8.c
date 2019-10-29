#include <stdio.h>
#include "structs.h"

int main() 
{   
    printf("\nLoading first RGB image...\n");
    ImageRGB* i1 = read_rgb("../img/lena.ppm");
    printf("\nImage load with success!\n");

    rgb_invert_horizontally(i1);

    printf("\nSaving horizontal inverted image to a file...\n");
    write_rgb(i1, "../out/p8-1.ppm");
    printf("\nImage saved with sucess!\n");

    // voltar a inverter para a posicao original
    rgb_invert_horizontally(i1);
    
    rgb_invert_vertically(i1);

    printf("\nSaving vertical inverted image to a file...\n");
    write_rgb(i1, "../out/p8-2.ppm");
    printf("\nImage saved with sucess!\n");

}