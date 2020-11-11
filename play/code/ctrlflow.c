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

int if_goto(int x, int a, int b)
{
  int ret;

  if (!x) {
    goto false;
  } 

 true:
  ret = a;
  goto done;

 false:
  ret = b;
  
 done:
  return ret;
}
    


int if_nogoto(int x, int a, int b)
{
  int ret;

  if (!x) {
    ret=b;
  } else {
    ret=a;
  }
  return ret;
  
  /* This is identical to if_goto() - it can be written as 

    if (!x) {
      goto false;
    }
   
    true:
      ret = a;
      goto done;

    false:
      ret = b;
  
    done:

  */
}


int do_while_loop(int n)
{
  volatile int x=93;

  do {
    x++;
    n--;
  } while (n!=0);
  
  return x;


  /*
    This can be written as
    
    loop:
      x++;
      n--;
      if (n!=0) {
         goto loop;
      }


  */
}

int while_loop(int n)
{
  volatile int x=93;

  while (n!=0) {
    x++;
    n--;
  } 
  
  return x;

  /*
    This can be written as

    if (n!=0) {
      do {
        x++;
        n--;
      } while (n!=0);
    }

    OR 

    if (n==0) { 
      goto done;
    }

    loop:
      x++;
      n--;
      if (n!=0) {
         goto loop;
      }

    done:

  */
}


int for_loop(int n)
{
  volatile int x=93;
  int i;

  for (i=n; i!=0; i--) {
    x++;
  } 
  
  return x;

  /*
    This can be written as

    i=n;

    while (i!=0) { 
      x++;
      i--;
    }

    OR

    i=n;

    if (i!=0) {
      do {
        x++;
        i--;
      } while (i!=0);
    }

    OR 


    i=n;
 
    if (i==0) { 
      goto done;
    }

    loop:
      x++;
      i--;
      if (i!=0) {
         goto loop;
      }

    done:

  */
}


int switch_case(int x)
{
  int ret;

  switch (x) {
  case 0: {
    int f;
    printf("Hi, %d\n", f);
    ret=3;
   }
    break;
  case 1:
    ret=99;
    break;
  case 2:
    ret=533;
    break;
  case 3:
    ret=321;
    break;
  case 4:
    ret=-4;
    break;
  default:
    ret=0;
    break;
  }
  
  return ret;
}


int main()
{
  if_goto(5,19,91);
  if_nogoto(5,19,91);
  do_while_loop(5);
  while_loop(5);
  for_loop(5);
  switch_case(2);
}
