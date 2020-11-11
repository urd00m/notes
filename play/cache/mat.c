#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Multiply two N*N matrices together

double *alloc_mat(long n)
{
  double *x = malloc(n*n*sizeof(double));
  memset(x,0,n*n*sizeof(double));
  return x;
}

void fill_mat(double *x, long n)
{
  long i;

  for (i=0;i<n*n;i++) { 
    x[i] = drand48();
  }
}

// compute z = x * y for n*n matrices
void mult_mat(double *x, double *y, double *z, long n)
{
  long i,j,k;
  double sum;

  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      sum = 0;
      for (k=0;k<n;k++) {
	sum += x[i*n+k] * y[k*n+j];
      }
      z[i*n+j] = sum;
    }
  }
}

double sum_mat(double *x, long n)
{
  long i,j,k;
  double sum;

  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      sum += x[i*n+j];
    }
  }
  return sum;
}



int main(int argc, char *argv[])
{
  long n;
  char op;
  
  if (argc!=3) { 
    printf("mat s|m size\n");
    return -1;
  }
  op = argv[1][0];
  if (op!='s' && op!='m') { 
    printf("mat s|m size\n");
    return -1;
  }
  n = atoi(argv[2]);

  printf("Doing op %c on matrices of size %ld by %ld\n", op, n,n);

  if (op=='s') { 
    double *x = alloc_mat(n);
    fill_mat(x,n);
    sum_mat(x,n);
    free(x);
    return 0;
  } else if (op=='m') {
    double *x = alloc_mat(n);
    double *y = alloc_mat(n);
    double *z = alloc_mat(n);
    fill_mat(x,n);
    fill_mat(y,n);
    mult_mat(x,y,z,n);
    free(x);
    free(y);
    free(z);
    return 0;
  }
}
	 
