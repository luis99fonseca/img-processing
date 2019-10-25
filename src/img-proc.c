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
        /* GrayPixel *temp_pixel = create_gray_pixel(*needsChar);
        image->a[bytes_count++] = *temp_pixel; */
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

            printf("%ld: %u - %u - %u\n",rounds2++, rgbArray[0], rgbArray[1],rgbArray[2]);
            RGBPixel *temp_pixel = create_rgb_pixel(rgbArray);
            image->a[bytes_count++] = *temp_pixel;

            
        }
    }
    printf("[INFO]: %s; BytesCounted: %d", "Done", bytes_count);
    printf("[TODO]>>> %u", image->a[bytes_count - 1].rgb[0]);
}

ImageBin * read_bin(char *file_name) 
{
 	   
}

int main() 
{
    /* read_rgb("lena.ppm"); */
    read_gray("lena2.ppm");
}