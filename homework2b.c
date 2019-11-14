#include <stdio.h>
#include <math.h>
#define DIM 512
#define VERTICAL 1


int convolve(unsigned char image[DIM][DIM], int temp [roi.height][roi.length], int x, int y, int avg, int tAvg, StDev, tStDev)
{
    int X, Y, sum = 0;

    int t[5][5];
    
    for(X = 0; X < roi.width; X++)
    {
      for(Y = 0; Y < roi.height; Y++)
      {
        sum += (image[y + Y][x + X] - avg) * (temp[Y][X] - tAvg);
      }
    }
    return sum/(StDev*tStDev);
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


int main(void) {
  int x, y, xlength, ylength, sum = 0, tSum = 0, avg, tAvg, variance = 0, StDev, best = 0;
  int temp [roi.height][roi.width];
  for(x = 0; x < roi.width; x++)
  {
      for(y = 0; y < roi.height; y++)
      {
          temp[y][x] = image[roi.x + x][roi.y + y];
          tSum += temp[y][x];
      }
  }
  tAvg = tSum/(roi.width*roi.length);
   
   for(x = 0; x < roi.width; x++)
  {
      for(y = 0; y < roi.length; y++)
      {
          best += temp[y][x] * temp[y][x];
      }
  }
          
  for(x = 0; x < DIM; x++)
  {
    for(y = 0; y < DIM; y++)
    {
      sum += image[y][x];
    }
  }
  
  avg = sum/(DIM*DIM);

  for(x = 0; x < DIM; x++)
  {
    for(y = 0; y < DIM; y++)
    {
      variance += pow(image[y][x] - avg,2);
    }
  }

  StDev = pow(variance, 0.5);
  
  for(x = 0; x < DIM-roi.width; x++)
  {
    for(y = 0; y < DIM-roi.height; y++)
    {
      proc_img[y][x] = abs(convolve(image, x, y))/3;
    }
  }

  
}
