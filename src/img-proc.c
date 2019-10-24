#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "img-proc.h"

RGBPixel * create_rgb_pixel(unsigned char *rgb)
{
    RGBPixel *pixel;
    pixel = (RGBPixel*)malloc(sizeof(RGBPixel));
    pixel->rgb[0] = rgb[0];
    pixel->rgb[1] = rgb[1];
    pixel->rgb[2] = rgb[2];
    return pixel;
}

GrayPixel * create_gray_pixel(unsigned char color) 
{
    GrayPixel *pixel;
    pixel->color = color;
    return pixel;
}

BinaryPixel * create_binary_pixel(unsigned char color)
{
    BinaryPixel *pixel;
    pixel->color = color;
    return color;
}

Image * create_image(int size) 
{
    Image *img;

    img = (Image*)malloc(sizeof(Image));
    img->n = 0;
    img->size = size;
    img->a =(int *)calloc(size, sizeof(int));

    return img;
}

Image * read_rgb(char *file_name) 
{

}

Image * read_gray(char *file_name)
{

}

Image * read_bin(char *file_name) 
{
    
}

int main() 
{
    FILE *fp = fopen("lena.ppm", "r");
    printf("Hello World!\n");
    char line[100];
    char *buffer;
    size_t bufsize = 100;
    size_t read;

    char type[5];

    if (fp == NULL)
        exit(EXIT_FAILURE);

/*     fseek(fp,0,SEEK_SET);
    fread(line, sizeof(int) * 10, 2, fp);
    printf("%s\n", line); */

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    char* fileType = (char *) malloc(5 * sizeof(char));

    getline(&buffer,&bufsize, fp);
    strcpy(fileType, buffer);
    printf("Type of file: %s\n", fileType);

    int* largura = (int *) malloc(1 * sizeof(int));
    int* altura = (int *) malloc(1 * sizeof(int));
    getline(&buffer,&bufsize, fp);

    printf("Dimentions: %s\n", buffer);
    char delimiter[] = " ";
    largura = strtok(buffer, delimiter);
    printf("Largura: %s\n", buffer);
    altura = strtok(buffer, delimiter);
    printf("Alturs: %s\n", buffer);



    /* while ((read = getline(&line, &bufsize, fp)) != -1) {
         printf("Retrieved line of length %zu:\n", read);
         printf("> %s\n", line);
    } */


    fclose(fp);
    return 0;
}