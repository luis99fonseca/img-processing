#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{   
    char *name = "lena4.ppm";
    FILE *fp = fopen(name, "r");
    printf("Hello World!\n");


    

    if (fp == NULL)
        exit(EXIT_FAILURE);

    FILE *fp2 = fopen("lena5.ppm", "w");
    
    if (fp2 == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
 
    fprintf(fp2, "%s\n", "P4");
    fprintf(fp2, "%s\n", "512 512");
    //fprintf(fp2, "%s\n", "255");
    fclose(fp2);
    fp2 = fopen("lena4.ppm", "ab");


    char *type = (char *) malloc(3 * sizeof(char));
    fscanf(fp, "%s", type);
    printf("%s\n", type);

    int *larg = (int *)malloc(1 * sizeof(int)), *comp = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d %d", larg, comp);
    printf("%d x %d\n", *larg, *comp);
    // ver diferença entre malloc e alloc (embora n seja propriamente importante i guess)
   // uint* matrix = (uint*) malloc(*larg * *comp * sizeof(uint));
/* 
    int *colorRange = (int *)malloc(1 * sizeof(int));
    fscanf(fp, "%d", colorRange);
    printf("%d\n", *colorRange); */
    printf("int has %lu bytes :O\n", sizeof(int));
    long offset = ftell(fp);
    printf("offsef: %ld\n", ftell(fp));
    fclose(fp);


    fp = fopen(name, "rb");
    fseek(fp, offset + 1, SEEK_SET);



    unsigned char *needsChar = (unsigned char*) malloc(sizeof(unsigned char));
    printf("size uchar: %ld, nedchar:%ld\n", sizeof(unsigned char), sizeof(needsChar));

    int index = -1;
    long rounds2 = 0;     

    int bytesread = 0;
    /* char bit = 7; */
    int total = 0;
    unsigned char finalColor = 0;
    unsigned char temp_bit;
    while ((bytesread = fread(needsChar, sizeof(*needsChar), 1, fp)) > 0){
        
        unsigned char corBig = *needsChar;
        printf("COR NOW TOTAL: %u\n", corBig);
        rounds2++;
        int mediaCor4;
        for (char bit = 7; bit >= 0; bit--){
            printf("ola");
            unsigned char temp_color = corBig & (1<<bit);
            printf("cor: %u; bitC= %u, totalSoFar= %d\n", temp_color, bit, total++);
        } 
       
        
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