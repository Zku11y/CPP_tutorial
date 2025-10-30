#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int ft_popen(const char *file, char *const argv[], char type) {
  int fd[2];
  pid_t pid;

  if(file == NULL || argv == NULL || (type != 'r' && type != 'w'))
    exit(EXIT_FAILURE);
  
  if(pipe(fd) == -1)
    exit(EXIT_FAILURE);

  pid = fork();
  if(pid == -1)
    exit(EXIT_FAILURE);

  if(pid == 0)  {
    if(type == 'r'){
      if(dup2(fd[1], STDOUT_FILENO) == -1)
        exit(EXIT_FAILURE);
    }
    if(type == 'w'){
      if(dup2(fd[0], STDIN_FILENO) == -1)
        exit(EXIT_FAILURE);
    }
    close(fd[0]);
    close(fd[1]);
    if(execvp(file, argv) == -1){
      exit(EXIT_FAILURE);
    }
  }
  if(type == 'r')
    return(close(fd[1]), fd[0]);
  return(close(fd[0]), fd[1]);
}

int main() {
	int fd = ft_popen("a", (char *const[]){"ls", NULL}, 'r');

    printf("fd : %d\n", ft_popen("ls", (char *const[]){"ls", NULL}, 'r'));
    printf("fd : %d\n", ft_popen("ls", (char *const[]){"ls", NULL}, 'w'));
}
