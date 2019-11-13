#include <stdio.h>
#include <math.h>
#define DIM 512
#define VERTICAL 1


int convolve(unsigned char image[DIM][DIM], int i, int j)
{
    int a, b, sum = 0;

    int t[5][5];
    for(a = 0; a < 3; a++)
    {
      for(b = 0; b < 3; b++)
      {
        sum += ((image[i + 1 - a][j + 1 - b] - avg) * (vertical[a][b] - tAvg))/(StDev*tStDev);
      }
    }
    return sum;
}


int main(void) {
  int i, j, xlength, ylength, sum = 0, avg, variance = 0, StDev;
  for(i = 0; i < xlength; i++)
  {
    for(j = 0; j < ylength; j++)
    {
      sum += image[j][i];
    }
  }
  
  avg = sum/(xlength*ylength);

  for(i = 0; i < xlength; i++)
  {
    for(j = 0; j < ylength; j++)
    {
      variance += pow(image[j][i] - avg,2);
    }
  }

  StDev = pow(variance, 0.5);

  
}
