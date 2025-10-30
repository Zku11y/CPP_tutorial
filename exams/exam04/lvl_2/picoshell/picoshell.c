#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>

int ft_ex(char **cmd, int *io){
  pid_t pid = fork();
  if(pid < 0)
    return 1;
  if(pid == 0){

    if(io[0] != 0){
      if(dup2(io[0], STDIN_FILENO) == -1)
        exit(EXIT_FAILURE);
      close(io[0]);
    }

    if(io[1] != 1){
      if(dup2(io[1], STDOUT_FILENO) == -1)
        exit(EXIT_FAILURE);
      close(io[1]);
    }

    if(execvp(cmd[0], cmd) == -1)
      exit(EXIT_FAILURE);
  }
  return 0;
}

int picoshell(char **cmds[]){
  int fd0[2];
  int fd1[2];
  int io[2];
  bool pip = true;

  int i = 0;

    if(!cmds[1]){
      pid_t pid = fork();
      if(pid < 0)
        return 1;
      if(pid == 0){
        execvp(cmds[0][0], cmds[0]);
        exit(-1);
      }
      wait(NULL);
      return 0;
    }


  while(cmds[i]){
    
    if(i == 0){
      io[0] = 0;
      if(pipe(fd0) == -1) return 1;
      io[1] = fd0[1];
      if(ft_ex(cmds[i], io) == 1) return 1;
      if(io[1] != 1) close(io[1]);
      i++;
      continue;
    }
  
  if(!cmds[i + 1]){
      io[1] = 1;
      if(pip)
        io[0] = fd0[0];
      else
        io[0] = fd1[0];
      if(ft_ex(cmds[i], io) == 1)
        return 1;
      if(io[0] != 0)
        close(io[0]);
      i++;
      continue;
    }

    if(pip == true){
      io[0] = fd0[0];
      if(pipe(fd1) == -1) return 1;
      io[1] = fd1[1];
    }
    else{
      io[0] = fd1[0];
      if(pipe(fd0) == -1) return 1;
      io[1] = fd0[1];
    }

    if(ft_ex(cmds[i], io) == 1)
      return 1;

    if(io[0] != 0)
      close(io[0]);
    if(io[1] != 1)
      close(io[1]);

    pip = !pip;
    i++;
  }
  int j = 0;
  while(cmds[j]){
    wait(NULL);
    j++;
  }
  return 0;
}



int ft_picoshell(char **cmds[])
{
    if (!cmds)
        return -1;
    
    int s=0;
    while(cmds[s])
        s++;
    
    int t[s-1][2];
    for(int i=0; i<s-1; i++)
        if(pipe(t[i])==-1)
            return -1;
    
    int i=0;
    pid_t pid;
    while(i<s)
    {
        pid=fork();
        if(pid==-1)
            exit(1);
        else if(pid==0)
        {
            if(i==0)
                dup2(t[i][1], 1);
            else if(i==s-1)
                dup2(t[i-1][0],0);
            else{
                dup2(t[i-1][0], 0);
                dup2(t[i][1], 1);
            }
            
            for(int i=0; i<s-1; i++){
                close(t[i][0]);    
                close(t[i][1]);    
            }
            execvp(cmds[i][0], cmds[i]);
            exit(-1);
        }
        i++; 
    }

    for(int i=0; i<s-1; i++){
        close(t[i][0]);    
        close(t[i][1]);    
    }

    for(int i=0; i<s; i++)
        wait(NULL);
    
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
