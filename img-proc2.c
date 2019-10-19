#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    FILE *fp = fopen("lena.ppm", "r");
    printf("Hello World!\n");


    char *type = (char *) malloc(3 * sizeof(char));

    if (fp == NULL)
        exit(EXIT_FAILURE);

    fscanf(fp, "%s", type);
    printf("%s\n", type);

    int *larg = (int *)malloc(1 * sizeof(int)), *comp = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d %d", larg, comp);
    printf("%d x %d\n", *larg, *comp);
    // ver diferença entre malloc e alloc (embora n seja propriamente importante i guess)
    uint *matrix = (uint*) malloc(*larg * *comp * sizeof(uint));

    int *colorRange = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d", colorRange);
    printf("%d\n", *colorRange);
    printf("int has %lu bytes :O\n", sizeof(int));
    long offset = ftell(fp);
    printf("offsef: %ld\n", ftell(fp));
    fclose(fp);


    fp = fopen("lena.ppm", "rb");
    fseek(fp, offset + 1, SEEK_SET);
    unsigned char *colorR = (unsigned char*) malloc(sizeof(unsigned char));
    unsigned char *colorG = (unsigned char*) malloc(sizeof(unsigned char));
    unsigned char *colorB = (unsigned char*) malloc(sizeof(unsigned char));
    unsigned char rgbArray[3];
    unsigned char *needsChar = (unsigned char*) malloc(sizeof(unsigned char));

    int index = -1;                  
    while ( fgets(needsChar, sizeof(needsChar), fp) != NULL){

        rgbArray[index = ++index % 3] = *needsChar;
       /* printf("index: %d\n", index);*/
        if (index == 2){
            printf("%u - %u - %u\n", rgbArray[0], rgbArray[1],rgbArray[2]);
        }
    }


    int count = 0;
    /*fscanf(fp, "%s", pixel);*/
    /*fread(pixel, sizeof(unsigned char), 1, fp);
    printf("%u\n", *pixel); //%u -> unsigned decimal integer
    printf("%ld\n", sizeof(unsigned char));*/
    // Reading a file one byte at a time would incur massive I/O overhead
    /*while (!feof(fp)){
        fgets(pixel, sizeof(int), fp);
        printf("é: %d\n", pixel);
        count++;
    }
*/    printf("%d\n", count);


    fclose(fp);
    return 0;
}