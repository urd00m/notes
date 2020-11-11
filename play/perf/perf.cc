#include <stdio.h>


#define N (1024L*1024L*16L)

volatile double x[N];

int setup() 
{
  long i;
  for (i=0;i<N;i++) { 
    x[i]=i;
  }
}
  
int main()
{
  long i;
 
  setup();
 
  double s=0;
  
  for (i=0;i<N;i++) { 
    s+=x[i];
  }
  
  printf("summed %lu doubles in C++, result %lf\n", N, s);

  return 0;
  
}
