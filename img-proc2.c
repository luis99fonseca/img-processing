#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    FILE *fp = fopen("lena.ppm", "r");
    printf("Hello World!\n");


    char *type = (char *) malloc(3 * sizeof(char));

    if (fp == NULL)
        exit(EXIT_FAILURE);


    FILE *fp2 = fopen("lena3.ppm", "w");
    /*fp = fopen("lena3.ppm", "w");*/
    if (fp2 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp2, "%s\n", "P4");
    fprintf(fp2, "%s\n", "512 512");
    fprintf(fp2, "%s\n", "255");
    fp2 = fopen("lena3.ppm", "ab");

    fscanf(fp, "%s", type);
    printf("%s\n", type);

    int *larg = (int *)malloc(1 * sizeof(int)), *comp = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d %d", larg, comp);
    printf("%d x %d\n", *larg, *comp);
    // ver diferença entre malloc e alloc (embora n seja propriamente importante i guess)
    uint *matrix = (uint*) malloc(*larg * *comp * sizeof(uint));

    int *colorRange = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d", colorRange);
    printf("%d\n", *colorRange);
    printf("int has %lu bytes :O\n", sizeof(int));
    long offset = ftell(fp);
    printf("offsef: %ld\n", ftell(fp));
    fclose(fp);


    fp = fopen("lena.ppm", "rb");
    fseek(fp, offset + 1, SEEK_SET);
/*    unsigned char *colorR = (unsigned char*) malloc(sizeof(unsigned char));
    unsigned char *colorG = (unsigned char*) malloc(sizeof(unsigned char));
    unsigned char *colorB = (unsigned char*) malloc(sizeof(unsigned char));*/
    unsigned char rgbArray[3];
    unsigned char *needsChar = (unsigned char*) malloc(sizeof(unsigned char));
    printf("size uchar: %ld, nedchar:%ld\n", sizeof(unsigned char), sizeof(needsChar));

    int index = -1;
    long rounds2 = 0;     

    //nao é bom pa ler binario             
    /*while ( fgets(needsChar, sizeof(needsChar), fp) != NULL){
        
        
        rgbArray[index = ++index % 3] = *needsChar;
        printf("i= %d; read: %ld\n", index, strlen(needsChar));
        if (index == 2){

            printf("offsefINSIDE: %ld\n", ftell(fp));
            printf("%ld: %u - %u - %u\n",rounds2++, rgbArray[0], rgbArray[1],rgbArray[2]);
        }
        
        if (rounds2 == 10){
            break;
        }
    }
    */
    int bytesread = 0;
    char bit = 8;
    int total = 0;
    unsigned char finalColor = 0;
    while ((bytesread = fread(needsChar, sizeof(*needsChar), 1, fp)) > 0){
        
        
        rgbArray[index = ++index % 3] = *needsChar;
        /*printf("i= %d; read: %d\n", index, bytesread);*/
        int mediaCor4;
        
       
        printf("outsideBit: %d\n", bit);
        if (index == 2){
            /*printf("offsefINSIDE: %ld\n", ftell(fp));*/
            printf("%ld: %u - %u - %u\n",rounds2++, rgbArray[0], rgbArray[1],rgbArray[2]);
            unsigned char mediaCor2 = (rgbArray[0] + rgbArray[1] + rgbArray[2]) / 3;
            unsigned char mediaCor3 = ((0.3 * rgbArray[0]) + (0.59 * rgbArray[1]) + (0.11 * rgbArray[2]));
            unsigned char mediaCor4 = mediaCor2;
            unsigned char corBW = (mediaCor4 > 128) ? 0 : 1;
            if (corBW == 1){
                unsigned char temp_bit = 1 << bit; 
                finalColor |= temp_bit; 
            }                   
            printf("bit: %d; corBW: %u; corAtual: %u\n", bit, corBW,finalColor);
            if (bit == 0){
                bit = 8;
                total++;
                printf("Writing... at: %d\n", total);
                fwrite(&finalColor, sizeof(*needsChar), 1, fp2);
                finalColor = 0;
            }
            bit--;
            
            printf("media2 : %u; media3 : %u\n", mediaCor2, mediaCor3);
            //printf(">>> %d\n", mediaCor);
            
                
            
            
        }
        /*if (rounds2 == 10){
            break;
        }*/
    }

     printf("pixeis: %ld\n", rounds2);
    long offset2 = ftell(fp);
    printf("offsef2: %ld\n", ftell(fp));
    fseek(fp, 0, SEEK_END);
    long endset = ftell(fp);
    printf("endset: %ld\n", ftell(fp));
    fclose(fp);
    fclose(fp2);

    


    return 0;
}