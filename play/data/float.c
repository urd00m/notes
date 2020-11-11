#include <math.h>
#include <stdint.h> // definitions of standard integers
#include <stdio.h>  // printf

int array[4] = {2, 1, 0, -1};
unsigned uarray[4] = {2, 1, 0, (unsigned)-1};


void dump_bytes(void *p, int n)
{
  int i;
  unsigned char *pc;

  printf("Memory at %lu (%p) (%d bytes): ", p, p, n);
  pc = (unsigned char *) p;
  for (i=0;i<n;i++) { 
    printf("%02x",pc[i]);
  }
  printf("\n");
}


int print_bits(unsigned x)
{
  int i;
  for (i=0;i<sizeof(x)*8;i++) { 
    printf("%d",(x>>(31-i))&0x1);
  }
}

int print_bits_float(float x)
{
  print_bits(*((unsigned *)&x));
  return 0;
}

int print_bits_double(double x)
{
  print_bits(*(((unsigned *)&x)+1));
  print_bits(*((unsigned *)&x));
}



int float_representations()
{
  float c;
  unsigned temp;

  printf("Floating point representations (32 bit floats)\n\n");

  c = +0.0;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  c = -0.0;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  c = 1.0/0.0;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  c = -1.0/0.0;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  c = NAN;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  c = -NAN;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  // normalized number
  c=3.14159;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  // denormalized number
  temp=0x80010000;
  c= *((float*)(&temp));
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");
}

int double_representations()
{
  double c;
  long long temp;

  printf("Floating point representations (64 bit floats (doubles))\n\n");

  c = +0.0;
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");

  c = -0.0;
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");

  c = 1.0/0.0;
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");

  c = -1.0/0.0;
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");

  c = NAN;
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");

  c = -NAN;
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");

  // normalized number
  c=3.14159;
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");

  // denormalized number
  temp=0x8000100000000000ULL;
  c= *((double*)(&temp));
  printf("  0x%016llx (%32.24le) ",*((long long *)&c),c); print_bits_double(c); printf("\n\n");
}

int float_arithmetic()
{
  int tempa=0xdeadbeef;
  int tempb=0xdfedbeef;

  float a = *((float*)&tempa);
  float b = *((float*)&tempb);
  float c;

  printf("Floating point arithmetic\n\n");

  printf("- 0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("---------------------------------------------------------------------------------\n");
  c = -a;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("+ 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a+b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");
  
  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("- 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a-b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("* 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a*b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("/ 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a/b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  b = 0.0;
  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("* 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a*b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  b = -0.0;
  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("* 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a*b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  b = INFINITY;
  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("+ 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a+b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  b = -INFINITY;
  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("+ 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a+b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  b = NAN;
  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("+ 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a+b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  b = -NAN;
  printf("  0x%08x (%32.24e) ",*((int*)&a),a); print_bits_float(a); printf("\n");
  printf("+ 0x%08x (%32.24e) ",*((int*)&b),b); print_bits_float(b); printf("\n");
  printf("---------------------------------------------------------------------------------\n");  
  c = a+b;
  printf("  0x%08x (%32.24e) ",*((int*)&c),c); print_bits_float(c); printf("\n\n");

  printf("\n");
}

double dot_product(double *a, double *b, int n)
{
  int i;
  double sum;
 
  sum=0;

  for (i=0;i<n;i++) {
     sum = sum + a[i]*b[i];
  }

  return sum;
   
}

float dot_product_float(float *a, float *b, int n)
{
  int i;
  float sum;

  sum=0;

  for (i=0;i<n;i++) {
     sum = sum + a[i]*b[i];
  }

  return sum;

}
 

int main()
{
  float_representations();
  double_representations();

  float_arithmetic();
}
