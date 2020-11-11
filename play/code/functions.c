
#include <stdio.h>

int big_callee(int n)
{
  register int a,b,c,d;
  register int i;
  
  a=b=c=d=n;
  
  for (i=0;i<n;i++) {
    a=b+c*d;
  }
  
  return a;
}

int big_caller(int n)
{
  register int a,b,c,d;
  register int i;
  
  a=b=c=d=n;

  for (i=0;i<n;i++) {
    a=b+c*d;
  }
  
  return a+big_callee(n);
}

int buf_overflow_vulnerability()
{
  char zip[9];
  
  printf("Type in zip code:\n");

  gets(zip);
  
  printf("OK, thanks.\n");
  return 0;
}


int main()
{
  big_caller(953);
  
  buf_overflow_vulnerability();
}
