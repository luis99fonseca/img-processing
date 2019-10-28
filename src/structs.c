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
    img->a =(RGBPixel *)calloc(length * heigth, sizeof(RGBPixel));

    return img;
}

ImageGray * create_imageGray(int length, int heigth) 
{
    ImageGray *img;

    img = (ImageGray*)malloc(sizeof(ImageGray));
    img->n = 0; //TODO ver se é necessario
    img->length = length;
    img->heigth = heigth;
    img->a =(GrayPixel *)calloc(length * heigth, sizeof(GrayPixel));

    return img;
}

ImageBin * create_imageBin(int length, int heigth) 
{
    ImageBin *img;

    img = (ImageBin*)malloc(sizeof(ImageBin));
    img->n = 0; //TODO ver se é necessario
    img->length = length;
    img->heigth = heigth;
    img->a =(BinaryPixel *)calloc(length * heigth, sizeof(BinaryPixel));

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
    if (strcmp(type,"P5") != 0){	//TODO: TESTAR
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

    ImageGray* image = create_imageGray(*larg, *comp);  //TODO: nao sei se isto funciona

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

        printf("%ld: %u\n",rounds2++, *needsChar);
        GrayPixel *temp_pixel = create_gray_pixel(*needsChar);
        image->a[bytes_count++] = *temp_pixel;
    }
    printf("[INFO]: %s; BytesCounted: %d", "Done", bytes_count);
    printf("[TODO]>>> %u", image->a[bytes_count - 1].color);

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
    if (strcmp(type,"P6") != 0){	//TODO: TESTAR
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

    ImageRGB* image = create_imageRGB(*larg, *comp);  //TODO: nao sei se isto funciona

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
    
    //variable to keep track of current rbgArray (TODO POR LINK PA ESSA VAR, se possivel) index;
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

         //   printf("%ld: %u - %u - %u\n",rounds2++, rgbArray[0], rgbArray[1],rgbArray[2]);
            RGBPixel *temp_pixel = create_rgb_pixel(rgbArray);
            image->a[bytes_count++] = *temp_pixel;

            
        }
    }
    printf("[INFO]: %s; BytesCounted: %d", "Done", bytes_count);
    printf("[TODO]>>> %u", image->a[bytes_count - 1].rgb[0]);
    printf("[TODO 2]>>> %d", image->heigth);
    return image;

}

ImageBin * read_bin(char *file_name) 
{
 	   
}


void write_rgb(ImageRGB* image, char* file_name){
    
    
    FILE *fp = fopen(file_name, "w");   
    fprintf(fp, "%s\n", "P6");  //TODO : muda os sizes para coiso dinamico 
    fprintf(fp, "%d %d\n", image->heigth, image->length);
    fprintf(fp, "%s\n", "255"); // TODO: isto devia tar registado tbm
    fclose(fp);
    fp = fopen(file_name, "ab");
    for (int index = 0; index < image->heigth * image->length; index++ ){
        //TODO : meter o "3" menos hardcocded?
        for (int color = 0; color < 3; color++){
            fwrite(&image->a[index].rgb[color], sizeof(unsigned char), 1, fp);
        }
        
    }
    fclose(fp);
    

}
void write_gray(ImageGray *image){
    
}
void write_bin(ImageBin *image){

}

void change_rgb_intensity(ImageRGB *image, char intensity)
{
    
    for (int i = 0; i < image->heigth * image->length; i++)
    {
        for (int color = 0; color < 3; color++)
        {   
            int result = image->a[i].rgb[color] + intensity;
            if (result < 0)
                result = 0;

            if (result > 255)
                result = 255;
            
            // because there is no overflow on the result, we can cast int to unsigned int directly
            image->a[i].rgb[color] = result;
            

        }
    }
}

ImageRGB * crop(ImageRGB *image, int x1, int y1, int x2, int y2)
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

    return cropedImage;
}

void create_water_mark(ImageRGB *image, int x, int y)
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

void invert_vertically(ImageRGB *image) 
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

void invert_horizontally(ImageRGB *image) 
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

void rotate_left(ImageRGB *image)
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

void rotate_right(ImageRGB *image) 
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


void overlap(ImageRGB *image, ImageRGB *crop, int x, int y)
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