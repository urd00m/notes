#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


void child_handler(int signum)
{
  int stat;

  printf("(parent) SIGCHLD\n");
  wait(&stat);
  printf("(parent) received status %d from child\n", stat);

}

int main()
{
  int mypid;
  int myparent;
  int childpid;
  int childstatus;
  char cmd[80];
  char bg;

  signal(SIGCHLD,child_handler);
  

  while (1) { 
    printf("(parent) tinyshell> ");
    gets(cmd);

    if (!strcmp(cmd,"")) { 
      continue;
    }
    if (!strcmp(cmd,"quit")) { 
      break;
    }

    if (cmd[strlen(cmd)-1]=='&') {
      bg=1;
      cmd[strlen(cmd)-1]=0;
    } else {
      bg=0;
    }

    printf("(parent) Handling %s command '%s'\n",
	   bg ? "background" : "foreground", cmd);

    childpid=fork();

    mypid=getpid();
    myparent=getppid();
  
    if (childpid<0) { 
      perror("(parent) Error forking");
      continue;
    } else if (childpid==0) {
      // I am the child
      printf("(child) I am pid %d, and my parent is %d, and I am about to replace myself with '%s'\n", mypid, myparent,cmd);

      execlp(cmd,cmd,0);

      printf("(child) exec failed - could not replace myself with '%s'\n",cmd);
      return -1;
    } else {
      // I am the parent
      printf("(parent) I am pid %d, my parent is %d, and my child is %d\n", mypid, myparent, childpid);
      if (bg) { 
	printf("(parent) not waiting for child to finish\n");
	continue;
      } else {
	printf("(parent) Waiting for child to finish\n");
	if (waitpid(childpid, &childstatus, 0)<0) { 
	  perror("(parent) Cannot wait\n");
	  exit(-1);
	}
	printf("(parent) child is now done, and returned %d\n",childstatus);
      }
    }
  }
  return 0;
}

    

  
