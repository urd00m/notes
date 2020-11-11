#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int *z=0;

void myhandler(int signum)
{
	printf("Ouch, the kernel just sent us signal %d\n", signum);
	printf("We'll quit\n");
	
	z=0x40000;	
	
	//abort();
	//exit(-1);
}




int main()
{
	volatile int x;


   signal(SIGSEGV, myhandler);

	x = *z;

	return x;
}
