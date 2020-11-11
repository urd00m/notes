#include <stdio.h>

int main()
{
   int a[8] = {0,1,2,3,4,5,6,7};

   printf("a[3] = %d\n", a[3]);
   printf("3[a] = %d\n", 3[a]);

   printf("a[9] = %d\n", a[9]);
   printf("a[-2] = %d\n", a[-2]);

	printf("0x40100[0] = %d\n", ((int *)0x40100)[0]);

}

