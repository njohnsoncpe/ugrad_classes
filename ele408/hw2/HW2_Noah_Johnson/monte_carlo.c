/* Program to compute Pi using Monte Carlo methods */

#include <stdlib.h>
#include <stdio.h>
//#include <math.h>
#define SEED 35791246

/* Returns a uniformly distributed RV in range [lo,hi]*/
double uni_rv(int lo, int hi){
  return((double)lo+rand()/(RAND_MAX/((double)hi-(double)lo)+1));
}

int main(int argc, char* argv[])
{
  FILE* fp;
  int N[6] = {1e3,1e4,1e5,1e6,1e7,1e8};
  double x,y;
  int i,j,M=0; /* # of points in the 1st quadrant of unit circle */
  double z;
  double pi;
  fp = fopen("MonteCarlo.txt","w+");
  /* initialize random numbers */
  srand(SEED);
  for(j=0;j<6;j++){
    M=0;
    for(i=0;i<N[j];i++){
      x = uni_rv(-1,1);
      y = uni_rv(-1,1);
      z = x*x+y*y;
      if (z<=1) M++;
    }pi=(double)M/N[j]*4;
    fprintf(fp,"%d,%g\n",N[j],pi);
  }
  fclose(fp);
}
