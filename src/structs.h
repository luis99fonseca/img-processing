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
 * Structure to represent an image in the RGB scale with pointer, index and size.
*/
typedef struct
{
    RGBPixel *a;
    int n;
    int length;
    int heigth;
} ImageRGB;

/**
 * Structure to represent a binary image with pointer, index and size.
*/
typedef struct
{
    BinaryPixel *a;
    int n;
    int length;
    int heigth;
} ImageBin;

/**
 * Structure to represent an image in the grayscale with pointer, index and size.
*/
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
 * RGB image constructor.
 * 
 * @param length Number of columns.
 * @param heigth Number of rows.
 * @return A pointer to the created RGB Image structure.
*/
ImageRGB * create_imageRGB(int length, int heigth);

/**
 * Grayscale image constructor.
 * 
 * @param length Number of columns.
 * @param heigth Number of rows.
 * @return A pointer to the created Grayscale image structure.
*/
ImageGray * create_imageGray(int length, int heigth);

/**
 * Binary image constructor.
 * 
 * @param length Number of columns.
 * @param heigth Number of rows.
 * @return A pointer to the created Binary image structure.
*/
ImageBin * create_imageBin(int length, int heigth);

/**
 * Method to read an image in the PPM format and in the RGB color scheme.
 * 
 * @param file_name Image PPM filename.
 * @return A pointer to the created RGB Image.
*/
ImageRGB * read_rgb(char *file_name);

/**
 * Method to read an image in the PPM format and in the grayscale color scheme.
 * 
 * @param file_name Image PPM filename.
 * @return A pointer to the created grayscale image.
*/
ImageGray * read_gray(char *file_name);

/**
 * Method to read an image in the PPM format and in binary.
 * 
 * @param file_name Image PPM filename.
 * @return A pointer to the created binary image.
*/
ImageBin * read_bin(char *file_name);


/**
 * Method to save a RGB image in a PPM file.
 * 
 * @param image A pointer to the RGB image.
 * @param file_name Image PPM filename.
*/
void write_rgb(ImageRGB *image, char* file_name);

/**
 * Method to save a Grayscale image in a PPM file.
 * 
 * @param image A pointer to the Grayscale image.
 * @param file_name Image PPM filename.
*/
void write_gray(ImageGray *image,  char* file_name);

/**
 * Method to save a Binary image in a PPM file.
 * 
 * @param image A pointer to the Binary image.
 * @param file_name Image PPM filename.
*/
void write_bin(ImageBin *image, char* file_name);

/**
 * Method to change the intensity of a RGB image.
 * 
 * @param image A pointer to the RGB image.
 * @param char Intensity value.
*/
void change_rgb_intensity(ImageRGB *image, char intensity);

/**
 * Method to change the intensity of a Grayscale image.
 * 
 * @param image A pointer to the Grayscale image.
 * @param char Intensity value. 
*/
void change_grayscale_intensity(ImageGray *image, char intensity);

/**
 * Method to crop a RGB image, given a starting and ending point.
 * 
 * @param image A pointer to the RGB image.
 * @param x1 First pixel x coordinate.
 * @param y1 First pixel y coordinate.
 * @param x2 Second pixel x coordinate.
 * @param y2 Second pixel y coordinate.
*/
ImageRGB * crop_rgb(ImageRGB *image, int x1, int y1, int x2, int y2);

/**
 * Method to crop a Grayscale image, given a starting and ending point.
 * 
 * @param image A pointer to the RGB image.
 * @param x1 First pixel x coordinate.
 * @param y1 First pixel y coordinate.
 * @param x2 Second pixel x coordinate.
 * @param y2 Second pixel y coordinate.
*/
ImageGray * crop_grayscale(ImageGray *image, int x1, int y1, int x2, int y2);

/**
 * Method to overlap a specific area of a RGB image with another one smaller, given a starting point.
 * 
 * @param image A pointer to the RGB image to be overlapped.
 * @param piece A ponter to the smaller RGB image.
 * @param x Start position x coordinate.
 * @param y Start position y coordinate.
*/
void overlap_rgb(ImageRGB *image, ImageRGB *piece, int x, int y);

/**
 * Method to overlap a specific area of a Grayscale image with another one smaller, given a starting point.
 * 
 * @param image A pointer to the Grayscale image to be overlapped.
 * @param piece A ponter to the smaller Grayscale image.
 * @param x Start position x coordinate.
 * @param y Start position y coordinate.
*/
void overlap_grayscale(ImageGray *image, ImageGray *piece, int x, int y);

/**
 * Method to create a water mark in a RGB image, given a starting point.
 * 
 * @param image A pointer to the RGB image to place a water mark.
 * @param x1 Start position x coordinate.
 * @param y1 Start position y coordinate.
*/
void rgb_water_mark(ImageRGB *image, int x, int y);

/**
 * Method to create a water mark in a Grayscale image, given a starting point.
 * 
 * @param image A pointer to the Grayscale image to place a water mark.
 * @param x1 Start position x coordinate.
 * @param y1 Start position y coordinate.
*/
void grayscale_water_mark(ImageGray *image, int x, int y);

/**
 * Method to invert a RGB image horizontally.
 * 
 * @param image A pointer to the RGB image that will be inverted. 
*/
void rgb_invert_horizontally(ImageRGB *image);

/**
 * Method to invert a Grayscale image horizontally.
 * 
 * @param image A pointer to the Grayscale image that will be inverted. 
*/
void grayscale_invert_horizontally(ImageGray *image);

/**
 * Method to invert a RGB image vertically.
 * 
 * @param image A pointer to the RGB image that will be inverted.
*/
void rgb_invert_vertically(ImageRGB *image);

/**
 * Method to invert a Grayscale image vertically.
 * 
 * @param image A pointer to the Grayscale image that will be inverted.
*/
void grayscale_invert_vertically(ImageGray *image);

/**
 * Method to rotate a RGB image -90 degrees.
 * 
 * @param image A pointer to the RGB image that will be rotated -90º.
*/
void rgb_rotate_right(ImageRGB *image);

/**
 * Method to rotate a Grayscale image -90 degrees.
 * 
 * @param image A pointer to the Grayscale image that will be rotated -90º.
*/
void grayscale_rotate_right(ImageGray *image);

/**
 * Method to rotate a RGB image 90 degrees.
 * 
 * @param image A pointer to the RGB image that will be rotated 90º.
*/
void rgb_rotate_left(ImageRGB *image);

/**
 * Method to rotate a Grayscale image 90 degrees.
 * 
 * @param image A pointer to the Grayscale image that will be rotated 90º.
*/
void grayscale_rotate_left(ImageGray *image);


/**
 * Method to reduce a RGB image in a specific ratio.
 * 
 * @param image A pointer to the RGB image.
 * @param ratio reducing ratio value. (i.e. ratio = 2 -> reduce by half)
*/
ImageRGB * rgb_reduce(ImageRGB *image, char ratio);

/**
 * Method to reduce a Grayscale image in a specific ratio.
 * 
 * @param image A pointer to the Grayscale image.
 * @param ratio reducing ratio value. (i.e. ratio = 2 -> reduce by half)
*/
ImageGray * grayscale_reduce(ImageGray *image, char ratio);

/**
 * Method to expand a RGB image in a specific ratio.
 * 
 * @param image A pointer to the RGB image.
 * @param ratio expanding ratio value. (i.e. ratio = 2 -> expand 2 times)
*/
ImageRGB * rgb_expand(ImageRGB *image, char ratio);

/**
 * Method to expand a Grayscale image in a specific ratio.
 * 
 * @param image A pointer to the Grayscale image.
 * @param ratio expanding ratio value. (i.e. ratio = 2 -> expand 2 times)
*/
ImageGray * grayscale_expand(ImageGray *image, char ratio);

/**
 * Method to convert a RGB image in Grayscale image
 * 
 * @param image A pointer to the RGB image.
*/
ImageGray* convert_rbgToGray(ImageRGB* image);

/**
 * Method to convert a RGB image in Grayscale image, based on given color channel
 * 
 * @param image A pointer to the RGB image.
 * @param color one of the following: \c Red , \c Green , \c Blue 
*/
ImageGray* convert_rbgToGrayParametized(ImageRGB* image, char* color);

/**
 * Method to convert a Grayscale image in Binary image
 * 
 * @param image A pointer to the Grayscale image.
 * @param threshold a value between 0 and 255, from which the pixel shall be colored
*/
ImageBin* convert_grayToBin(ImageGray* image, unsigned char threshold);

/**
 * Method to apply a filter to a RGB image in given a filter of 3*3 dimention
 * 
 * @param image A pointer to the RGB image.
 * @param filter an array with a preferably valid kernel
*/
void apply_filter_toRGB(ImageRGB* image, float filter[9]);

/**
 * Auxiliary function, which calculates de value of a given pixel, by defined RGB channel
 * 
 * @param image A pointer to the RGB image.
 * @param filter an array with a preferably valid kernel
 * @param line vertical location of pixel to apply calculations to
 * @param col horizontal location of pixel to apply calculations to
 * @param channel a value between 0 and 2, representing the colors of the RGB format
*/
unsigned char sumFilterRGB(ImageRGB *image,float filter[9], int line, int col, char channel);

/**
 * Method to apply a filter to a Grayscale image in given a filter of 3*3 dimention
 * 
 * @param image A pointer to the Grayscale image.
 * @param filter an array with a preferably valid kernel
*/
void apply_filter_toGray(ImageGray* image, float filter[9]);

/**
 * Auxiliary function, which calculates de value of a given pixel, in a Grayscaled image
 * 
 * @param image A pointer to the RGB image.
 * @param filter an array with a preferably valid kernel
 * @param line vertical location of pixel to apply calculations to
 * @param col horizontal location of pixel to apply calculations to
*/
unsigned char sumFilterGray(ImageGray *image,float filter[9], int line, int col);

/**
 * Method to convert a Gray image in RGB image
 * 
 * @param image A pointer to the Grayscale image.
*/
ImageRGB* convert_GrayToRGB(ImageGray* image);

/**
 * Method to color into Gray, an RGB image
 * 
 * @param image A pointer to the RGB image.
*/
void color_RGBtoGray(ImageRGB* image);


