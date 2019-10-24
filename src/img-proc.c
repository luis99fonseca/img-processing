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

ImageGray * read_gray(char *file_name) 
{

}

ImageRGB * read_rgb(char *file_name)
{
	FILE *fp = fopen(file_name, "r");
	if (fp == NULL){
		printf("%s\n", "Erro na leitura do ficheiro!");
        exit(EXIT_FAILURE);
    }

    /**
    Variable to store the file type;
    */
    char *type = (char *) malloc(3 * sizeof(char));
    fscanf(fp, "%s", type);
    printf("%s\n", type);
    if (type != "P4"){	//TODO: TESTAR
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

    ImageRGB* image = create_image(larg, comp);  //TODO: nao sei se isto funciona

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
    
    //variable to keep track of current rbgArray (POR LINK PA ESSA VAR, se possivel) index;
    int index = -1;

    //TODO debug
    long rounds2 = 0; 

    //initializations
    int bytesread = 0;
    while ((bytesread = fread(needsChar, sizeof(*needsChar), 1, fp)) > 0){
        
        //ciclying the index, never letting it getting past 2, preventing overflows
        rgbArray[index = ++index % 3] = *needsChar;
       	
       	//after a complete pixel read (aka 3 bytes), do some extra work...
        if (index == 2){

            printf("%ld: %u - %u - %u\n",rounds2++, rgbArray[0], rgbArray[1],rgbArray[2]);


            
        }
        /*if (rounds2 == 10){
            break;
        }*/
    }
}

ImageBin * read_bin(char *file_name) 
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