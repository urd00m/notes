#include <stdlib.h>
#include <stdio.h>

unsigned long get_cycle_count();

void init(double *a, long n)
{
  long i;

  for (i=0;i<n;i++) {
    a[i] = i;
  }
}

double dot_product(double *a, double *b, long n)
{
   double sum = 0;
   long i;

   for (i=0;i<n;i++) { 
      sum += a[i] * b[i];
   }

   return sum;
}

int main(int argc, char *argv[])
{
  long n;
  unsigned long start, end;
  volatile double res;
  
  if (argc!=2) {
    printf("usage: dot_prod N\n");
    return -1;
  }
  
  n=atol(argv[1]);
  
  double *mat1 = malloc(sizeof(double)*n);
  double *mat2 = malloc(sizeof(double)*n);
  
  init(mat1,n);
  init(mat2,n);

  start = get_cycle_count();
  res = dot_product(mat1,mat2,n);
  end = get_cycle_count();

  printf("Dot product of %lu element vectors took %lu cycles\n",n,end-start);
  
  return 0;

}


unsigned long get_cycle_count()
{
  unsigned long tsc;						\
  unsigned a, d;		
  
  // this one instruction reads the current cycle count
  // on this processor core.
  asm volatile("rdtsc"      
	       : "=a" (a), 
		 "=d" (d));  

  *(unsigned *)&(tsc) = a;				
  *(unsigned *)(((unsigned char *)&tsc) + 4) = d;		

  return tsc;
}
