#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void child_handler(int signum) {
	int stat;
	printf("(parent) SIGCHILD\n"); 
	wait(&stat); 
	printf("(parent) received status %d from child\n", stat); 
}

int main()
{
	printf("Starting program\n"); 
	int mypid; 
	int myparent; 
	int childpid;
	int childstatus; 	


	//beginning forks 
	childpid = fork();
	mypid = getpid();
	myparent=getppid();
	if(childpid<0) {
		perror("(parent) Error Forking"); 
	}  else if(childpid==0) {
		printf("(child) this is child\n");
		execlp("./child", "child", NULL); 
		printf("(child) exec failed\n");
		return -1;  
	} else {
		printf("(parent) this is parent waiting on child to finish\n");
		if(waitpid(childpid, &childstatus, 0) < 0) {
			perror("(parent) Cannot wait\n"); 
			exit(-1); 
		} 
		printf("(parent) child finished\n"); 
	}
	
	return 0; 
}
