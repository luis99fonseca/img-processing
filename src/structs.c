#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"

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
    pixel = (GrayPixel*)malloc(sizeof(GrayPixel));
    pixel->color = color;
    return pixel;
}

BinaryPixel * create_binary_pixel(unsigned char color)
{
    BinaryPixel *pixel;
    pixel = (BinaryPixel*)malloc(sizeof(BinaryPixel));
    pixel->color = color;
    return pixel;
}

ImageRGB * create_imageRGB(int length, int heigth) 
{
    ImageRGB *img;

    img = (ImageRGB*)malloc(sizeof(ImageRGB));
    img->n = 0; //TODO ver se é necessario
    img->length = length;
    img->heigth = heigth;
    img->a =(RGBPixel *)malloc(length * heigth * sizeof(RGBPixel));

    return img;
}

ImageGray * create_imageGray(int length, int heigth) 
{
    ImageGray *img;

    img = (ImageGray*)malloc(sizeof(ImageGray));
    img->n = 0; //TODO ver se é necessario
    img->length = length;
    img->heigth = heigth;
    img->a =(GrayPixel *)malloc(length * heigth * sizeof(GrayPixel));

    return img;
}

ImageBin * create_imageBin(int length, int heigth) 
{
    ImageBin *img;

    img = (ImageBin*)malloc(sizeof(ImageBin));
    img->n = 0; //TODO ver se é necessario
    img->length = length;
    img->heigth = heigth;
    img->a =(BinaryPixel *)malloc(length * heigth * sizeof(BinaryPixel));

    return img;
}

ImageGray * read_gray(char *file_name) 
{
	FILE *fp = fopen(file_name, "r");
	if (fp == NULL){
		printf("%s\n", "Erro na abertura do ficheiro!");
        exit(EXIT_FAILURE);
    }

    /**
    Variable to store the file type;
    */
    char *type = (char *) malloc(3 * sizeof(char));
    fscanf(fp, "%s", type);
    printf("%s\n", type);
    if (strcmp(type,"P5") != 0){	
    	printf("[ERRO]: %s\n", "Formato de ficheiro inválido!");
        exit(EXIT_FAILURE);
    }

    /**
	Store image dimentions;
    */
    int *larg = (int *)malloc(1 * sizeof(int)), *comp = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d %d", larg, comp);
    printf("%d x %d\n", *larg, *comp);

    /**
	Store color range
    */
    int *colorRange = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d", colorRange);
    printf("%d\n", *colorRange);

    ImageGray* image = create_imageGray(*larg, *comp);  

    //END of first lecture (as a ordinary text file)
    long offset = ftell(fp);
    printf("offsef: %ld\n", ftell(fp));
    fclose(fp);

    //BEGINNING of second lecture (as a binary file)
    fp = fopen(file_name, "rb");
    fseek(fp, offset + 1, SEEK_SET);
    
    //variable to store temporary color;
    unsigned char *needsChar = (unsigned char*) malloc(sizeof(unsigned char));

    //TODO debug
    long rounds2 = 0; 

    //initializations
    int bytesread = 0;
    int bytes_count = 0;
    while ((bytesread = fread(needsChar, sizeof(*needsChar), 1, fp)) > 0){

        //printf("%ld: %u\n",rounds2++, *needsChar);
        GrayPixel *temp_pixel = create_gray_pixel(*needsChar);
        image->a[bytes_count++] = *temp_pixel;
    }
    printf("[INFO]: %s; BytesCounted: %d", "Done", bytes_count);
    return image;
}

ImageRGB * read_rgb(char *file_name)
{
	FILE *fp = fopen(file_name, "r");
	if (fp == NULL){
		printf("%s\n", "Erro na abertura do ficheiro!");
        exit(EXIT_FAILURE);
    }

    /**
    Variable to store the file type;
    */
    char *type = (char *) malloc(3 * sizeof(char));
    fscanf(fp, "%s", type);
    printf("%s\n", type);
    if (strcmp(type,"P6") != 0){	
    	printf("%s\n", "Formato de ficheiro inválido!");
        exit(EXIT_FAILURE);
    }

    /**
	Store image dimentions;
    */
    int *larg = (int *)malloc(1 * sizeof(int)), *comp = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d %d", larg, comp);
    printf("%d x %d\n", *larg, *comp);

    /**
	Store color range
    */
    int *colorRange = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d", colorRange);
    printf("%d\n", *colorRange);

    ImageRGB* image = create_imageRGB(*larg, *comp); 

    //END of first lecture (as a ordinary text file)
    long offset = ftell(fp);
    printf("offsef: %ld\n", ftell(fp));
    fclose(fp);

    //BEGINNING of second lecture (as a binary file)
    fp = fopen(file_name, "rb");
    fseek(fp, offset + 1, SEEK_SET);

    //array of rbg colors;
    unsigned char rgbArray[3];
    
    //variable to store temporary color;
    unsigned char *needsChar = (unsigned char*) malloc(sizeof(unsigned char));
    
    //variable to keep track of current rbgArray
    int index = -1;

    //TODO debug
    long rounds2 = 0; 

    //initializations
    int bytesread = 0;
    int bytes_count = 0;
    while ((bytesread = fread(needsChar, sizeof(*needsChar), 1, fp)) > 0){
        
        //ciclying the index, never letting it getting past 2, preventing overflows
        rgbArray[index = ++index % 3] = *needsChar;
       	
       	//after a complete pixel read (aka 3 bytes), do some extra work...
        if (index == 2){

         
            RGBPixel *temp_pixel = create_rgb_pixel(rgbArray);
            image->a[bytes_count++] = *temp_pixel;

            
        }
    }
    printf("[INFO]: %s; BytesCounted: %d", "Done", bytes_count);
    return image;

}

ImageBin * read_bin(char *file_name) 
{
    FILE *fp = fopen(file_name, "r");
	if (fp == NULL){
		printf("%s\n", "Erro na abertura do ficheiro!");
        exit(EXIT_FAILURE);
    }

    /**
    Variable to store the file type;
    */
    char *type = (char *) malloc(3 * sizeof(char));
    fscanf(fp, "%s", type);
    printf("%s\n", type);
    if (strcmp(type,"P4") != 0){	
    	printf("%s\n", "Formato de ficheiro inválido!");
        exit(EXIT_FAILURE);
    }

    /**
	Store image dimentions;
    */
    int *larg = (int *)malloc(1 * sizeof(int)), *comp = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d %d", larg, comp);
    printf("%d x %d\n", *larg, *comp);


    ImageBin* image = create_imageBin(*larg, *comp);  //TODO: nao sei se isto funciona

    //END of first lecture (as a ordinary text file)
    long offset = ftell(fp);
    printf("offsef: %ld\n", ftell(fp));
    fclose(fp);

    //BEGINNING of second lecture (as a binary file)
    fp = fopen(file_name, "rb");
    fseek(fp, offset + 1, SEEK_SET);

    unsigned char *needsChar = (unsigned char*) malloc(sizeof(unsigned char));
    int bytesread = 0;
    unsigned char temp_bit;
    int bits_count = 0;
    unsigned char temp_color;
    while ((bytesread = fread(needsChar, sizeof(*needsChar), 1, fp)) > 0){
        
        
     //   printf("COR NOW TOTAL: %u\n", *needsChar);
        int mediaCor4;
        for (char bit = 7; bit >= 0; bit--){
            temp_color = *needsChar & (1<<bit);
         //   printf("cor: %u; bitC= %u, totalSoFar= %d\n", temp_color >> bit, bit, bits_count);
            BinaryPixel *temp_pixel = create_binary_pixel(temp_color >> bit);
            image->a[bits_count++] = *temp_pixel;
        } 
       
        
    }
    printf("[INFO]: %s; BitsCounted: %d", "Done", bits_count);
    return image;

}


void write_rgb(ImageRGB* image, char* file_name){
    FILE *fp = fopen(file_name, "w");   
    fprintf(fp, "%s\n", "P6");  
    fprintf(fp, "%d %d\n", image->length, image->heigth);
    fprintf(fp, "%s\n", "255"); 
    fclose(fp);
    fp = fopen(file_name, "ab");
    for (int index = 0; index < image->heigth * image->length; index++ ){
        for (int color = 0; color < 3; color++){
            fwrite(&image->a[index].rgb[color], sizeof(unsigned char), 1, fp);
        }
        
    }
    fclose(fp);
    

}

void write_gray(ImageGray *image, char* file_name){
    FILE *fp = fopen(file_name, "w");   
    fprintf(fp, "%s\n", "P5"); 
    fprintf(fp, "%d %d\n", image->length, image->heigth);
    fprintf(fp, "%s\n", "255"); 
    fclose(fp);
    fp = fopen(file_name, "ab");
    for (int index = 0; index < image->heigth * image->length; index++ ){
        
        fwrite(&image->a[index].color, sizeof(unsigned char), 1, fp);
    }
    fclose(fp);
}

void write_bin(ImageBin *image, char* file_name){
    
    FILE *fp = fopen(file_name, "w");   
    fprintf(fp, "%s\n", "P4"); 
    fprintf(fp, "%d %d\n", image->length, image->heigth);
    fclose(fp);
    fp = fopen(file_name, "ab");
    char bit_index = 7;
    unsigned char temp_color = 0;

    /** Here we play with the bits as following:
     * each ImageBin has a BinaryPixel, in which the color is at least significative bit (aka, of order 0),
     * thus, in each loop, we shift that bit to the left (most significative bit posible), in order to form a byte
     * legible for this format; Once we form a byte, it is written, and a new one is started to be formed;
    */
    for (int index = 0; index < image->heigth * image->length; index++ ){
        temp_color |= (image->a[index].color << bit_index--);
        if (bit_index == -1){

            bit_index = 7;
            fwrite(&temp_color, sizeof(unsigned char), 1, fp);
            temp_color = 0;
        }
        
    }
  
    fclose(fp);
}


void change_rgb_intensity(ImageRGB *image, char intensity)
{
    
    for (int i = 0; i < image->heigth * image->length; i++)
    {
        for (int color = 0; color < 3; color++)
        {   
            int result = image->a[i].rgb[color] + intensity;
            
            if (result < 0) result = 0;
            if (result > 255) result = 255;
            
            // because there is no overflow on the result, we can cast int to unsigned int directly
            image->a[i].rgb[color] = result;
            

        }
    }

    printf("\nChanged image intensity with sucess!\n");
}

void change_grayscale_intensity(ImageGray *image, char intensity)
{ 
    for (int i = 0; i < image->heigth * image->length; i++)
    {
        int result = image->a[i].color + intensity;

        if (result < 0) result = 0;
        if (result > 255) result = 255;

        image->a[i].color = result;
    }
    printf("\nChanged image intensity with sucess!\n");
}

ImageRGB * crop_rgb(ImageRGB *image, int x1, int y1, int x2, int y2)
{
    int total_length = image->length, total_heigth = image->heigth;

    int new_heigth = y2 - y1;
    int new_length = x2 - x1;

    ImageRGB* cropedImage = create_imageRGB(new_length, new_heigth);  

    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 
        || x1 > total_length || x2 > total_length
        || y1 > total_heigth || y2 > total_heigth)
    {
        printf("\nInvalid crop area.\n");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < new_heigth; y++)
    {
        for (int x = 0; x < new_length; x++)
        {   
            cropedImage->a[y*new_length + x].rgb[0] = image->a[(y1+y)*total_length + (x1+x)].rgb[0];
            cropedImage->a[y*new_length + x].rgb[1] = image->a[(y1+y)*total_length + (x1+x)].rgb[1];
            cropedImage->a[y*new_length + x].rgb[2] = image->a[(y1+y)*total_length + (x1+x)].rgb[2];
        }
    }

    printf("\nCropped image with sucess!\n");
    return cropedImage;
}

ImageGray * crop_grayscale(ImageGray *image, int x1, int y1, int x2, int y2)
{
    int total_length = image->length, total_heigth = image->heigth;

    int new_heigth = y2 - y1;
    int new_length = x2 - x1;

    ImageGray* cropedImage = create_imageGray(new_length, new_heigth);  

    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 
        || x1 > total_length || x2 > total_length
        || y1 > total_heigth || y2 > total_heigth)
    {
        printf("\nInvalid crop area.\n");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < new_heigth; y++)
    {
        for (int x = 0; x < new_length; x++)
        {   
            cropedImage->a[y*new_length + x].color = image->a[(y1+y)*total_length + (x1+x)].color;
        }
    }

    printf("\nCropped image with sucess!\n");
    return cropedImage;
}

void rgb_water_mark(ImageRGB *image, int x, int y)
{   
    int total_length = image->length, total_heigth = image->heigth;

    ImageRGB* water_mark = read_rgb("../img/water_mark.ppm");

    int water_mark_length = water_mark->length;
    int water_mark_heigth = water_mark->heigth;

    
    if (x < 0 || y < 0 || x > total_length - water_mark_length + 1 || y > total_heigth - water_mark_heigth)
    {
        printf("\nInvalid watermark placement.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < water_mark_heigth /*&& i + y < total_heigth*/; i++)
    {
        for (int j = 0; j < water_mark_length - 1 /*&& j + x < total_length*/; j++)
        {
            double r1 = round(image->a[(y+i)*total_length + (x+j)].rgb[0] * 0.60) +  round(water_mark->a[i*water_mark_length + j].rgb[0] * 0.40);
            double r2 = round(image->a[(y+i)*total_length + (x+j)].rgb[1] * 0.60) +  round(water_mark->a[i*water_mark_length + j].rgb[1] * 0.40);
            double r3 = round(image->a[(y+i)*total_length + (x+j)].rgb[2] * 0.60) +  round(water_mark->a[i*water_mark_length + j].rgb[2] * 0.40);
            image->a[(y+i)*total_length + (x+j)].rgb[0] = r1 <= 255 ? r1 : 255; 
            image->a[(y+i)*total_length + (x+j)].rgb[1] = r2 <= 255 ? r2 : 255; 
            image->a[(y+i)*total_length + (x+j)].rgb[2] = r3 <= 255 ? r3 : 255; 
        }
    }
    printf("\nPlaced watermark with success!\n");
}

void grayscale_water_mark(ImageGray *image, int x, int y)
{   
    int total_length = image->length, total_heigth = image->heigth;

    ImageGray* water_mark = convert_rbgToGray(read_rgb("../img/water_mark.ppm"));

    int water_mark_length = water_mark->length;
    int water_mark_heigth = water_mark->heigth;

    
    if (x < 0 || y < 0 || x > total_length - water_mark_length + 1 || y > total_heigth - water_mark_heigth)
    {
        printf("\nInvalid watermark placement.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < water_mark_heigth /*&& i + y < total_heigth*/; i++)
    {
        for (int j = 0; j < water_mark_length - 1 /*&& j + x < total_length*/; j++)
        {
            double r1 = round(image->a[(y+i)*total_length + (x+j)].color * 0.60) +  round(water_mark->a[i*water_mark_length + j].color * 0.40);
            image->a[(y+i)*total_length + (x+j)].color = r1 <= 255 ? r1 : 255; 
        }
    }
    printf("\nPlaced watermark with success!\n");
}

void rgb_invert_vertically(ImageRGB *image) 
{

    int length = image->length, heigth = image->heigth;

    RGBPixel* inverted =(RGBPixel *)malloc(length * heigth * sizeof(RGBPixel));
    
    int n = 0;
    for (int i = 0; i < heigth; i++)
    {
        for (int j = length - 1; j >= 0; j--) 
        {
            inverted[n].rgb[0] = image->a[i*length + j].rgb[0];
            inverted[n].rgb[1] = image->a[i*length + j].rgb[1];
            inverted[n].rgb[2] = image->a[i*length + j].rgb[2];
            n++;
        }
    }

    image->a = inverted;
    printf("\nInverted image vertically with success!\n");
}

void grayscale_invert_vertically(ImageGray *image) 
{

    int length = image->length, heigth = image->heigth;

    GrayPixel* inverted =(GrayPixel *)malloc(length * heigth * sizeof(GrayPixel));
    
    int n = 0;
    for (int i = 0; i < heigth; i++)
    {
        for (int j = length - 1; j >= 0; j--) 
        {
            inverted[n].color = image->a[i*length + j].color;
            n++;
        }
    }

    image->a = inverted;
    printf("\nInverted image vertically with success!\n");
}

void rgb_invert_horizontally(ImageRGB *image) 
{

    int length = image->length, heigth = image->heigth;

    RGBPixel* inverted =(RGBPixel *)malloc(length * heigth * sizeof(RGBPixel));
    
    int n = 0;
    for (int i = heigth - 1; i >= 0; i--)
    {
        for (int j = 0; j < length; j++) 
        {
            inverted[n].rgb[0] = image->a[i*length + j].rgb[0];
            inverted[n].rgb[1] = image->a[i*length + j].rgb[1];
            inverted[n].rgb[2] = image->a[i*length + j].rgb[2];
            n++;
        }
    }

    image->a = inverted;
    printf("\nInverted image horizontally with success!\n");
}

void grayscale_invert_horizontally(ImageGray *image) 
{

    int length = image->length, heigth = image->heigth;

    GrayPixel* inverted =(GrayPixel *)malloc(length * heigth * sizeof(GrayPixel));
    
    int n = 0;
    for (int i = heigth - 1; i >= 0; i--)
    {
        for (int j = 0; j < length; j++) 
        {
            inverted[n].color = image->a[i*length + j].color;
            n++;
        }
    }

    image->a = inverted;
    printf("\nInverted image horizontally with success!\n");
}

void rgb_rotate_left(ImageRGB *image)
{
    int length = image->length, heigth = image->heigth;

    RGBPixel* inverted =(RGBPixel *)malloc(length * heigth * sizeof(RGBPixel));

    int n = 0;
    for (int j = length - 1; j >= 0; j--)
    {
        for (int i = 0; i < heigth; i++)
        {
            inverted[n].rgb[0] = image->a[i*length + j].rgb[0];
            inverted[n].rgb[1] = image->a[i*length + j].rgb[1];
            inverted[n].rgb[2] = image->a[i*length + j].rgb[2];
            n++;
        }
    }

    image->a = inverted;
    printf("\nRotated image 90º with success!\n");

}

void grayscale_rotate_left(ImageGray *image)
{
    int length = image->length, heigth = image->heigth;

    GrayPixel* inverted =(GrayPixel *)malloc(length * heigth * sizeof(GrayPixel));

    int n = 0;
    for (int j = length - 1; j >= 0; j--)
    {
        for (int i = 0; i < heigth; i++)
        {
            inverted[n].color = image->a[i*length + j].color;
            n++;
        }
    }

    image->a = inverted;
    printf("\nRotated image 90º with success!\n");

}

void rgb_rotate_right(ImageRGB *image) 
{
    int length = image->length, heigth = image->heigth;

    RGBPixel* inverted =(RGBPixel *)malloc(length * heigth * sizeof(RGBPixel));

    int n = 0;
    for (int j = 0; j < length; j++)
    {
        for (int i = heigth - 1; i >= 0; i--)
        {
            inverted[n].rgb[0] = image->a[i*length + j].rgb[0];
            inverted[n].rgb[1] = image->a[i*length + j].rgb[1];
            inverted[n].rgb[2] = image->a[i*length + j].rgb[2];
            n++;
        }
    }
    
    image->a = inverted;
    printf("\nRotated image -90º with success!\n");
}

void grayscale_rotate_right(ImageGray *image) 
{
    int length = image->length, heigth = image->heigth;

    GrayPixel* inverted =(GrayPixel *)malloc(length * heigth * sizeof(GrayPixel));

    int n = 0;
    for (int j = 0; j < length; j++)
    {
        for (int i = heigth - 1; i >= 0; i--)
        {
            inverted[n].color = image->a[i*length + j].color;
            n++;
        }
    }
    
    image->a = inverted;
    printf("\nRotated image -90º with success!\n");
}


void overlap_rgb(ImageRGB *image, ImageRGB *crop, int x, int y)
{
    int total_length = image->length, total_heigth = image->heigth;

    int crop_length = crop->length, crop_heigth = crop->heigth;

    if (x < 0 || y < 0 || x > total_length - crop_length + 1 || y > total_heigth - crop_heigth)
    {
        printf("\nInvalid overlap.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < crop_heigth /*&& i + y < total_heigth*/; i++)
    {
        for (int j = 0; j < crop_length - 1 /*&& j + x < total_length*/; j++)
        {
            image->a[(y+i)*total_length + (x+j)].rgb[0] = crop->a[i*crop_length + j].rgb[0]; 
            image->a[(y+i)*total_length + (x+j)].rgb[1] = crop->a[i*crop_length + j].rgb[1]; 
            image->a[(y+i)*total_length + (x+j)].rgb[2] = crop->a[i*crop_length + j].rgb[2]; 
        
        }
    }
    printf("\nImage overlap with success!\n");
}

void overlap_grayscale(ImageGray *image, ImageGray *crop, int x, int y)
{
    int total_length = image->length, total_heigth = image->heigth;

    int crop_length = crop->length, crop_heigth = crop->heigth;

    if (x < 0 || y < 0 || x > total_length - crop_length + 1 || y > total_heigth - crop_heigth)
    {
        printf("\nInvalid overlap.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < crop_heigth /*&& i + y < total_heigth*/; i++)
    {
        for (int j = 0; j < crop_length - 1 /*&& j + x < total_length*/; j++)
        {
            image->a[(y+i)*total_length + (x+j)].color = crop->a[i*crop_length + j].color;
        
        }
    }
    printf("\nImage overlap with success!\n");
}

ImageRGB * rgb_reduce(ImageRGB *image, char ratio)
{
    int length = image->length, heigth = image->heigth;
    int new_length = length / ratio, new_heigth = heigth / ratio;

    ImageRGB* shrink = create_imageRGB(new_length, new_heigth);

    for (int i = 0; i < heigth; i+=ratio)
    {
        for (int j = 0; j < length; j+=ratio)
        {
            shrink->a[shrink->n].rgb[0] = image->a[i*length + j].rgb[0];
            shrink->a[shrink->n].rgb[1] = image->a[i*length + j].rgb[1];
            shrink->a[shrink->n].rgb[2] = image->a[i*length + j].rgb[2];
            shrink->n++;
        }
    }
    
    printf("\nImage reduced with success!\n");
    return shrink;
}

ImageGray * grayscale_reduce(ImageGray *image, char ratio)
{
    int length = image->length, heigth = image->heigth;
    int new_length = length / ratio, new_heigth = heigth / ratio;

    ImageGray* shrink = create_imageGray(new_length, new_heigth);

    for (int i = 0; i < heigth; i+=ratio)
    {
        for (int j = 0; j < length; j+=ratio)
        {
            shrink->a[shrink->n].color = image->a[i*length + j].color;
            shrink->n++;
        }
    }
    
    printf("\nImage reduced with success!\n");
    return shrink;
}

ImageRGB * rgb_expand(ImageRGB *image, char ratio)
{
    int length = image->length, heigth = image->heigth;
    int new_length = length * ratio, new_heigth = heigth * ratio;

    ImageRGB* expand = create_imageRGB(new_length, new_heigth);

    for (int i = 0; i < heigth; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int r = 0; r < ratio; r++)
            {
                expand->a[expand->n].rgb[0] = image->a[i*length + j].rgb[0];
                expand->a[expand->n].rgb[1] = image->a[i*length + j].rgb[1];
                expand->a[expand->n].rgb[2] = image->a[i*length + j].rgb[2];
                expand->n++;
            }
            
        }

        for(int r = 0; r < ratio - 1; r++)
        {
            for (int copy = 0; copy < new_length; copy++)
            {
                expand->a[expand->n].rgb[0] = expand->a[expand->n - new_length].rgb[0];
                expand->a[expand->n].rgb[1] = expand->a[expand->n - new_length].rgb[1];
                expand->a[expand->n].rgb[2] = expand->a[expand->n - new_length].rgb[2];
                expand->n++;
            }
        }
    }
    printf("\nImage expanded with success!\n");
    return expand;
}

ImageGray * grayscale_expand(ImageGray *image, char ratio)
{
    int length = image->length, heigth = image->heigth;
    int new_length = length * ratio, new_heigth = heigth * ratio;

    ImageGray* expand = create_imageGray(new_length, new_heigth);

    for (int i = 0; i < heigth; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int r = 0; r < ratio; r++)
            {
                expand->a[expand->n].color = image->a[i*length + j].color;
                expand->n++;
            }
            
        }

        for(int r = 0; r < ratio - 1; r++)
        {
            for (int copy = 0; copy < new_length; copy++)
            {
                expand->a[expand->n].color = expand->a[expand->n - new_length].color;
                expand->n++;
            }
        }
    }
    printf("\nImage expanded with success!\n");
    return expand;
}


ImageGray* convert_rbgToGray(ImageRGB *image){
    ImageGray* new_image = create_imageGray(image->length, image->heigth);

    for (int index = 0; index < image->heigth * image->length; index++){
        new_image->a[index].color = ((0.3 * image->a[index].rgb[0]) + (0.6 * image->a[index].rgb[1]) + (0.10 * image->a[index].rgb[3]));
       // new_image->a[index].color = ( image->a[index].rgb[0] + image->a[index].rgb[1] + image->a[index].rgb[2]) / 3;

    }
    return new_image;
}


ImageGray* convert_rbgToGrayParametized(ImageRGB* image, char* color){
    ImageGray* new_image = create_imageGray(image->length, image->heigth);

    char index_color;
    if (strcmp(color,"Red") == 0){
        index_color = 0;
    } else if (strcmp(color,"Green") == 0){
        index_color = 1;
    } else if (strcmp(color,"Blue") == 0){
        index_color = 2;
    } else {
        printf("%s\n", "[ERROR] Canal não pertencente ao formato RGB!");
        exit(EXIT_FAILURE);
    }

    for (int index = 0; index < image->heigth * image->length; index++){
        new_image->a[index].color = image->a[index].rgb[index_color];
    }
    return new_image;

}
ImageBin* convert_grayToBin(ImageGray* image, unsigned char threshold){
     ImageBin* new_image = create_imageBin(image->length, image->heigth);
     
    for (int index = 0; index < image->heigth * image->length; index++){
        new_image->a[index].color =  image->a[index].color > threshold ? 0 : 1;
    }
    return new_image;

}
void apply_filter_toRGB(ImageRGB* image, float filter[9]){ 
    RGBPixel *temp_a = (RGBPixel *)malloc(image->length * image->heigth * sizeof(RGBPixel));
    
    int total_cols = image->length;

    //variables used to adjust the filter computations at the edges; is this case they copy the value of the pixel in the oposite way of the edge
    int adjust_col = 0;
    int adjust_line = 0;
    for (int line = 0; line < image->heigth; line++){
        for (int col = 0; col < image->length; col++){
            adjust_col = 0;
            adjust_line = 0;
            if (line == 0){
                adjust_line = 1;
            }  
            if (line == image->heigth - 1)
            {
                adjust_line = -1;
            }
            if (col == 0){
                adjust_col = 1;
            }  
            if (col == image->length - 1)
            {
                adjust_col = -1;
            }
                for (int color = 0; color < 3; color++){     
                    temp_a[line *  total_cols + col].rgb[color] = sumFilterRGB(image, filter, line + adjust_line, col + adjust_col, color);                    
                }
            }
        }
    
    //TODO: ver se libertamos memoria!!!
    //free(image->a);

    image->a = temp_a;

}

//Note: to simplify, array is of fixed size; initial goal was to allow a little more dinamic approch, see below; 
unsigned char sumFilterRGB(ImageRGB *image,float filter[9], int line, int col, char channel){
    int value = 0;
    int temp_value;
    
    /* Note: as a parameter, an array becomes a pointer, and once this happens, you can't determine the number of elements in it;
        Thus, if it wasnt for it, we would now calculate the root of the "size of the kernel". Because it would have a fixed size anyway(9), that root would be 3,
        which you can find hardcoded in one of the lines below*/
    for (int temp_line = -1 ; temp_line <= 1; temp_line++){
        for (int temp_col = - 1; temp_col <= 1; temp_col++){  
            temp_value = image->a[(temp_line + line) * image->length + (temp_col + col)].rgb[channel] * filter[(temp_line + 1) * 3 + (temp_col + 1)];
            value += temp_value;
        }
    }
    if (value > 255){
        value = 255;
    } else if (value < 0)
    {
        value = 0;
    }
    

    return (unsigned char) value;
}

void apply_filter_toGray(ImageGray* image, float filter[9]){
    GrayPixel *temp_a = (GrayPixel *)malloc(image->length * image->heigth * sizeof(GrayPixel));
    
    int total_cols = image->length;

    //variables used to adjust the filter computations at the edges; is this case they copy the value of the pixel in the oposite way of the edge
    int adjust_col = 0;
    int adjust_line = 0;
    for (int line = 0; line < image->heigth; line++){
        for (int col = 0; col < image->length; col++){
            adjust_col = 0;
            adjust_line = 0;
            if (line == 0){
                adjust_line = 1;
            }  
            if (line == image->heigth - 1)
            {
                adjust_line = -1;
            }
            if (col == 0){
                adjust_col = 1;
            }  
            if (col == image->length - 1)
            {
                adjust_col = -1;
            }
                for (int color = 0; color < 3; color++){     
                    temp_a[line *  total_cols + col].color = sumFilterGray(image, filter, line + adjust_line, col + adjust_col);                    
                }
            }
        }
    
    //TODO: ver se libertamos memoria!!!
    //free(image->a);

    image->a = temp_a;
}

unsigned char sumFilterGray(ImageGray *image,float filter[9], int line, int col){
    int value = 0;
    int temp_value;
    
    /* Note: as a parameter, an array becomes a pointer, and once this happens, you can't determine the number of elements in it;
        Thus, if it wasnt for it, we would now calculate the root of the "size of the kernel". Because it would have a fixed size anyway(9), that root would be 3,
        which you can find hardcoded in one of the lines below*/
    for (int temp_line = -1 ; temp_line <= 1; temp_line++){
        for (int temp_col = - 1; temp_col <= 1; temp_col++){  
            temp_value = image->a[(temp_line + line) * image->length + (temp_col + col)].color * filter[(temp_line + 1) * 3 + (temp_col + 1)];
            value += temp_value;
        }
    }

    if (value > 255){
        value = 255;
    } else if (value < 0)
    {
        value = 0;
    }

    return (unsigned char) value;
}

