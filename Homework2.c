#include <stdio.h>
#include <math.h>
#include <X11/Xlib.h>
int vertical [3][3] = { { -1 , 0 , 1 } , { -1 , 0 , 1 } , { - 1 , 0 , 1 } };
int horizontal [3][3] = { { -1 , -1 , -1 } , { 0 , 0 , 0 } , { 1 , 1 , 1 } };


#define DIM 512
#define VERTICAL 1
int convolve(unsigned char image[DIM][DIM], int arr[3][3], int i, int j)
{
    int a, b, sum;
    for(a = 0; a < 3; a++)
    {
      for(b = 0; b < 3; b++)
      {
        sum += image[i + 1 - a][j + 1 - b] * arr[i][j];
      }
    }
}

void process_image(image, size, proc_img)
unsigned char image[DIM][DIM];
int size[2];
unsigned char proc_img[DIM][DIM];
{
  int i, j;
  for(i = 0; i < DIM-1; i++)
  {
    for(j = 0; j < DIM-1; j++)
    {
      if(VERTICAL)
        proc_img[i][j] = abs(convolve(image, vertical, i, j))/3;
      else
        proc_img[i][j] = abs(convolve(image, horizontal, i , j))/3;
    }
  }

}



int main(void) {
  printf("Hello World\n");
  return 0;
}
