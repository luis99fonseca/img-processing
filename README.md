# img-processing
Repository to develop an image processing program in C.

## Formas de representar píxeis

```c
// RGB
typedef struct {
    uchar r,g,b;
} RGBPixel;

uint data; // + mask

uchar data[3];

// Binary
uchar {0 1} 
```

## Formas de representar imagens

RGBPixel(**data; data[][]);
        (*data; poslin = l*nc + c);

## Aceder a um elemento de uma matriz num array unidimensional

Matrix N*M

índices: i pertence a [0, N-1], j pertence a [0, M-1]

Posição do elemento (i,j):

matriz[i][j] = array[i*M + j]

[https://stackoverflow.com/questions/14015556/how-to-map-the-indexes-of-a-matrix-to-a-1-dimensional-array-c](https://stackoverflow.com/questions/14015556/how-to-map-the-indexes-of-a-matrix-to-a-1-dimensional-array-c)