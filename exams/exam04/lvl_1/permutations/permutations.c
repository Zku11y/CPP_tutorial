#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_solve(char *buffer){
  int i = 0;
  while(buffer[i]){
    int j = i + 1;
    while(buffer[j]){
      if(buffer[j] < buffer[i]){
        char tmp = buffer[j];
        buffer[j] = buffer[i];
        buffer[i] = tmp;
      }
      j++;
    }
    i++;
  }
}

void ft_queens(char *og, char *buffer, int *lock, int size, int n){
  if(n == size){
    printf("%s\n", buffer);
    return;
  }

  int i = 0;
  while(i < size){
    if(lock[i]){
      i++;
      continue;
    }

    lock[i] = 1;
    buffer[n] = og[i];
    ft_queens(og, buffer, lock, size, n + 1);
    lock[i] = 0;
    i++;
  }
}

int main(int ac, char **av){
  if(ac != 2)
    return 1;

  int size = 0;
  while(av[1][size])
    size++;
  char buffer[size + 1];
  buffer[size] = '\0';
  int lock[size];

  for(int i = 0; i < size; i++)
    lock[i] = 0;
  ft_solve(av[1]);
  ft_queens(av[1], buffer, lock, size, 0);
}