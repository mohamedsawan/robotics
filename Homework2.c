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
/******************************************************************/
/* This structure contains the coordinates of a box drawn with    */
/* the left mouse button on the image window.                     */
/* roi.x , roi.y  - left upper corner's coordinates               */
/* roi.width , roi.height - width and height of the box           */
/******************************************************************/
extern XRectangle roi;


/******************************************************************/
/* Main processing routine. This is called upon pressing the      */
/* Process button of the interface.                               */
/* image  - the original greyscale image                          */
/* size   - the actual size of the image                          */
/* proc_image - the image representation resulting from the       */
/*              processing. This will be displayed upon return    */
/*              from this function.                               */
/******************************************************************/
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

