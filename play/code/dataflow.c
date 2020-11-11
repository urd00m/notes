#include <stdio.h>

//
// You don't need to understand this function
//
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

void timing_overhead()
{
  unsigned long long start, end;

  start=get_cycle_count();
  end=get_cycle_count();
  
  printf("timing overhead is at least %llu cycles\n",end-start);
}

int op_single(int x)
{
  return ~x;
}

int op_regs(int x, int y)
{
  return x+y;
}

long op_regs_long(long x, long y)
{
  return x+y;
}

  
int a, b, c;

int op_mem()
{
  c = a + b;

  return c;
}

int op_for_loop(int x[], int n)
{
  int i;
  int sum;
  unsigned long long start, end;

  sum=1;

  start=get_cycle_count();
  
  for (i=0;i<n;i++) { 
    sum = sum + x[i];
  }
  
  end=get_cycle_count();

  printf("for loop and timing overhead took %llu cycles\n", end-start);

  return sum;
}
  
int compare()
{
  volatile int a=0x7fffffff;
  volatile int b=-1;
  
  printf("%d - %d = %d but %d > %d = %d\n",
	 a,b,a-b, a,b, a > b);

}


int z[1024];

int main()
{
  op_single(5);
  op_regs(5,6);
  op_mem();
  op_for_loop(z,1024);
  compare();
  timing_overhead();
}
