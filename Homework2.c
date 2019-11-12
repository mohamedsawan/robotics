#include <stdio.h>
#include <math.h>
#include <X11/Xlib.h>
int horizontal [3][3] = { { -1 , 0 , 1 } , { -1 , 0 , 1 } , { - 1 , 0 , 1 } };
int vertical [3][3] = { { -1 , -1 , -1 } , { 0 , 0 , 0 } , { 1 , 1 , 1 } };


#define DIM 512
#define VERTICAL 0
int convolve(unsigned char image[DIM][DIM], int i, int j)
{
    int a, b, sum = 0;
    int vertical [3][3] = { { -1 , 0 , 1 } , { -1 , 0 , 1 } , { - 1 , 0 , 1 } };
    int horizontal [3][3] = { { -1 , -1 , -1 } , { 0 , 0 , 0 } , { 1 , 1 , 1 } };
    for(a = 0; a < 3; a++)
    {
      for(b = 0; b < 3; b++)
      {
        if(VERTICAL)
          sum += image[i + 1 - a][j + 1 - b] * vertical[a][b];
        else
          sum += image[i + 1 - a][j + 1 - b] * horizontal[a][b];
      }
    }
    return sum;
}

extern XRectangle roi;


void process_image(image, size, proc_img)
unsigned char image[DIM][DIM];
int size[2];
unsigned char proc_img[DIM][DIM];
{
  int i , j;
  for(i = 1; i < DIM-1; i++)
  {
    for(j = 1; j < DIM-1; j++)
    {
      proc_img[i][j] = abs(convolve(image, i, j))/3;
    }
  }
  size[0] = 510;
  size[1] = 510;
}

