#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/wait.h>

int ft_exec(char **cmds, int r, int w, int unused){
  pid_t pid = fork();
  if(pid < 0) return 1;
  if(pid == 0){
    if(dup2(r, STDIN_FILENO) == -1) exit(EXIT_FAILURE);
    if(dup2(w, STDOUT_FILENO) == -1) exit(EXIT_FAILURE);

    if(r != STDIN_FILENO) close(r);
    if(w != STDOUT_FILENO) close(w);
    if(unused != -1) close(unused);

    if(execvp(cmds[0], cmds) == -1) exit(EXIT_FAILURE);
  }
  return 0;
}

void wait_children(){
  while(wait(NULL) > 0);
}

int picoshell(char **cmds[]){
  int p1[2];
  int p2[2];
  bool p = true;
  
  if(!cmds) return 1;

  if(!cmds[1]){
    pid_t pid = fork();
    if(pid < 0) return 1;
    if(pid == 0){
      if(execvp(cmds[0][0], cmds[0]) == -1)
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    return 0;
  }
  int i = 0;
  if(pipe(p1) == -1) return 1;
  if(ft_exec(cmds[0], STDIN_FILENO, p1[1], p1[0]) == 1) return 1;
  close(p1[1]);
  i++;

  while(cmds[i + 1]){

    if(p){ 
      if(pipe(p2) == -1) return (close(p1[0]), wait_children(), 1);
      if(ft_exec(cmds[i], p1[0], p2[1], p2[0]) == 1) return 1;
      close(p1[0]);
      close(p2[1]);
    }

    else{
      if(pipe(p1) == -1) return (close(p2[0]), wait_children(), 1);
      if(ft_exec(cmds[i], p2[0], p1[1], p1[0]) == 1) return 1;
      close(p2[0]);
      close(p1[1]);
    }

    p = !p;
    i++;
  }

  if(p){
    if(ft_exec(cmds[i], p1[0], STDOUT_FILENO, -1) == 1) return 1;
    close(p1[0]);
  }
  else{
    if(ft_exec(cmds[i], p2[0], STDOUT_FILENO, -1) == 1) return 1;
    close(p2[0]);
  }

  while(wait(NULL) > 0);
  return 0;
}


int main()
{
    char *cmd1[] = {"echo", "squalala!", NULL};
    char *cmd2[] = {"cat", NULL};
    char *cmd3[] = {"sed", "s/a/b/g", NULL};

    // char **t[] = {cmd2, cmd3, NULL};
    char **t[] = {cmd1, cmd2, cmd3, NULL};
    picoshell(t);

    return 0;
}
