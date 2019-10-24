//
// Created by:
// 89066 - Luís Carlos Duarte Fonseca
// 88886 - Tiago Carvalho Mendes
// 
// October, 2019 - University of Aveiro
//


/**
 * Structure to define a pixel using an array of three unsigned chars.
 * Each element of the array represents a value in the RGB color scheme.
 * 
 * Red value: rgb[0]
 * Green value: rgb[1]
 * Blue value: rgb[2]
*/
typedef struct 
{
    unsigned char rgb[3];
} RGBPixel;


/**
 * Structure to define a pixel in the gray scale, using an unsigned char.
*/
typedef struct 
{
    unsigned char color;
} GrayPixel;


/**
 * Structure to define a binary pixel, using an unsigned char.
 * However, we only want 1 bit from the 8 bits of the field 'color', so we need to do additional computations.
*/
typedef struct
{
    unsigned char color;
} BinaryPixel;


/**
 * Structure to represent an image with pointer, index and size.
*/
typedef struct
{
    RGBPixel *a;
    int n;
    int length;
    int heigth;
} ImageRGB;

typedef struct
{
    BinaryPixel *a;
    int n;
    int length;
    int heigth;
} ImageBin;

typedef struct
{
    GrayPixel *a;
    int n;
    int length;
    int heigth;
} ImageGray;


/**
 * RGBPixel constructor.
 * 
 * @param rgb A pointer to an array with the 3 values in the RGB color scheme.
 * @return A pointer to the created RGBPixel structure.
*/
RGBPixel * create_rgb_pixel(unsigned char *rgb);


/**
 * GrayPixel constructor.
 * 
 * @param color An unsigned char with the color value in grayscale.
 * @return A pointer to the created GrayPixel structure.
*/
GrayPixel * create_gray_pixel(unsigned char color);


/**
 * BinaryPixel constructor.
 * 
 * @param color An unsigned char with the color value in the first bit.
 * @return A pointer to the created BinaryPixel structure.
*/
BinaryPixel * create_binary_pixel(unsigned char color);


/**
 * Image constructor.
 * 
 * @param size Size of the image (length * heigth)
 * @return A pointer to the created Image structure
*/
ImageRGB * create_imageRGB(int length, int heigth);

ImageRGB * read_rgb(char *file_name);
ImageGray * read_gray(char *file_name);
ImageBin * read_bin(char *file_name);