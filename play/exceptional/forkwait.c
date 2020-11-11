#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int mypid;
  int myparent;
  int childpid;
  int childstatus;

  childpid=fork();
  
  mypid=getpid();
  myparent=getppid();
  
  if (childpid<0) { 
    perror("Error forking");
    return -1;
  } else if (childpid==0) {
    // I am the child
    printf("Hi, I am the child, pid %d, and my parent is %d\n", mypid, myparent);
#if 1
    sleep(10);
    printf("Hi, I am the child and I am now done\n");
    exit(0);
#else
//    sleep(1);
#if 0
    fork();
#endif
    if (execl("./forkwait", 0)<0) { 
      perror("exec failed");
      exit(-1);
    }
#endif
  } else { // childpid>0
    printf("I am the parent, pid %d, my parent is %d, and my child is %d\n", mypid, myparent, childpid);
    printf("Waiting for child to finish\n");
    int childret = waitpid(childpid, &childstatus, 0); 
    if (childret<0) { 
      perror("Cannot wait\n");
      exit(-1);
    }
    printf("I am the parent, and the child is now done, and returned %d %d\n",childstatus, childret);
  }
  
  return 0;
}

    

  
