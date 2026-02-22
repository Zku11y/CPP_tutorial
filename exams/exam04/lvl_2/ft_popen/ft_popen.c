#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_popen(const char *file, char *const argv[], char type){
    if(!file || !argv || (type != 'r' && type != 'w'))
        return 1;
    
    int fd[2];
    pid_t pid;

    if(pipe(fd) == -1)
      return 1;

    pid = fork();
    if(pid < 0)
      return 1;
    if(pid == 0){

    if(type == 'r'){
      if(dup2(fd[1], STDOUT_FILENO) == -1)
        exit(EXIT_FAILURE);
    }
    
    if(type == 'w'){
      if(dup2(fd[0], STDIN_FILENO) == -1)
        exit(EXIT_FAILURE);
      close(fd[0]);
      close(fd[1]);
    }

    if(execvp(file, argv) == -1)
      exit(EXIT_FAILURE);
  }
  if(type == 'r')
    return(close(fd[1]), fd[0]);
  return(close(fd[0]), fd[1]);
}
