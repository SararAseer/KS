#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void sighandler(int sig){
  if (sig == SIGUSR1){
    printf("Pid: %d\n", getppid());
    sleep(1);
  }
  else if (sig == SIGINT){
    int f = open("file.txt", O_WRONLY | O_CREAT , 0666);
  if (f < 0) {
      printf("File open failure");
      exit(1);
    }

    write(f, "Program death by SIGINT", 24);
    close(f);
    exit(0);
  }
}

int main(){
  signal(SIGUSR1, sighandler);
  signal(SIGINT, sighandler);
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
