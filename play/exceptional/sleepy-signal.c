#include <stdio.h>
#include <signal.h>

void myhandler(int signum)
{
	printf("I don't want to be interrupted!\n");
	
}




int main()
{
        signal(SIGINT, myhandler);
	
	while (1) { sleep(10); }
}
