#include <stdio.h>
#include "structs.h"

int main() 
{
    ImageRGB* image = read_rgb("../img/lena.ppm");
    ImageGray* gray = convert_rbgToGray(image);
    grayscale_water_mark(gray, 100, 100);
    write_gray(gray, "../out/gray_watermark.ppm");
}