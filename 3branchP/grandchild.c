#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main() {
	printf("(grandchild) grandchild running\n"); 
	
	printf("(grandchild) 1*2 = 2\n"); 

	return 0; 
}
