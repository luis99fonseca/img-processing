#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <structs.h>

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
    return pixel;
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