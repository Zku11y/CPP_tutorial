#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

bool ft_check(int *buffer, int n, int i){
  int j = 1;
  while(n - j >= 0){
    if(i == buffer[n - j]) return false;
    if(buffer[n - j] == (i - j) || buffer[n - j] == (i + j))
      return false;
    j++;
  }
  return true;
}

void ft_queens(int *buffer, int size, int n){
  if(n == size){
    for(int i = 0; i < n; i++){
      printf("%d", buffer[i]);
      if(i + 1 < size)
        printf(" ");
    }
    printf("\n");
    return;
  }

  int i = 0;
  while(i < size){
    if(ft_check(buffer, n, i)){
      buffer[n] = i;
      ft_queens(buffer, size, n + 1);
    }
    i++;
  }
}

int main(int ac, char **av){
  if(ac != 2)
    return 1;
  
  int size = atoi(av[1]);
  int buffer[size + 1];

  ft_queens(buffer, size, 0);
}
