#include <stdio.h>

int sum(int x, int y)
{
  int t = x + y;
  return t;
}

int main()
{
  printf("x+y=%d\n", sum(4,5));
}
