//
// Authors:
// 89066 - Luís Carlos Duarte Fonseca
// 88886 - Tiago Carvalho Mendes
// 
// October, 2019 
//

/**
 * Structure to represent a pixel using an array of three unsigned chars.
*/
typedef struct 
{
    unsigned char data[3];
} ArrayPixel;

/**
 * Structure to represent a pixel using three unsigned chars.
*/
typedef struct 
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGBPixel;

/**
 * Structure to represent an image with pointer, index and size.
*/
typedef struct
{
    int *a;
    int n;
    int size;
} Image;

/**
 * ArrayPixel constructor.
 * 
 * @param r red value
 * @param g green value
 * @param b blue value
 * @return A pointer to the created RGBPixel structure
*/
ArrayPixel * create_array_pixel(unsigned char r, unsigned char g, unsigned char b);

/**
 * RGBPixel constructor.
 * 
 * @param r red value
 * @param g green value
 * @param b blue value
 * @return A pointer to the created RGBPixel structure
*/
RGBPixel * create_rgb_pixel(unsigned char r, unsigned char g, unsigned char b);


/**
 * Image constructor.
 * 
 * @param size Size of the image (length * heigth)
 * @return A pointer to the created Image structure
*/
Image * create_image(int size);