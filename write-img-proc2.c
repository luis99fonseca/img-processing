#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    FILE *fp = fopen("lena2.ppm", "w");
    /*fp = fopen("lena2.ppm", "w");*/
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "%s\n", "P6");
    fprintf(fp, "%s\n", "512 512");
    fprintf(fp, "%s\n", "255");
    fclose(fp);

    fp = fopen("lena2.ppm", "ab");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
//+e com fwrite
    
    return 0;
}