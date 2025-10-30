#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose){
  pid_t child;
  int status;
  int res;

  child = fork();
  if(child < 0) return -1;
  if(child == 0){
    alarm(timeout);
    f();
    exit(0);
  }
  
  alarm(timeout);
  res = waitpid(child, &status, 0);
  if(res == -1){
    return -1;
  }
  if(res == child){
    if(WIFEXITED(status)){
      if(WEXITSTATUS(status) == 0)
        return(printf("Nice function!\n"), 1);
      else if(WEXITSTATUS(status) == SIGALRM)
        return 
      printf("Bad function: exited with code %d\n", WEXITSTATUS(status));
      return 0;
    }
    else if(WIFSIGNALED(status)){
      printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
      return 0;
    }
  }
  return -1;
}


