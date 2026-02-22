#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>

int sandbox(void (*f)(void), unsigned int timeout, bool verbose){
  pid_t pid = fork();
  if(pid < 0)
    return -1;
  if(pid == 0){
    alarm(timeout);
    f();
    exit(0);
  }

  int status;
  if(waitpid(pid, &status, 0) == -1)
    return -1;
  
  if(WIFEXITED(status)){
    int code = WEXITSTATUS(status);
    if(code == 0){
      if(verbose)
        printf("Nice function!\n");
      return 1;
    }
    else{
      if(verbose)
        printf("exited with code %d\n", code);
      return 0;
    }
  }

  if(WIFSIGNALED(status)){
    int code = WTERMSIG(status);
    if(code == SIGALRM){
      if(verbose)
        printf("Bad function: timed out after %d seconds\n", timeout);
    }
    else{
      if(verbose)
        printf("Bad function: %s\n", strsignal(code));
    }
    return 0;
  }

  return -1;
}


