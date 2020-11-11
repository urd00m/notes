#include <stdio.h>

int fact(int k)
{
  if (k==0) { 
    return 1;
  } else {
    return k*fact(k-1);
  }
}

int main()
{
  int num=12;

  printf("fact %d = %d\n", num, fact(num));
}
