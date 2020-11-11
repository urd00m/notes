#include <stdio.h>

int array[10];

int main()
{
  int i;
  int sum=0;
  
  for (i = 0; i < 10; i++) { 
    array[i]=i;
  }
  
  for(i = 0; i < 10; i++) {
    sum = sum + array[i];
  }
  printf("sum = %d\n",sum);
  return 0;
}


