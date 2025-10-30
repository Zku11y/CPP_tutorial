#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void check_dups(char *str1) {
  int i = 0;
  while(str1[i]){
    int j = i + 1;
    while(str1[j]){
      if(str1[j] == str1[i])
        return;
      j++;
    }
    i++;
  }
  puts(str1);
}

void permutations(char *og, char *buffer, int size, int n){
  if(n == size) {
    check_dups(buffer);
    return;
  }
  int i = 0;
  while(i < size) {
    buffer[n] = og[i];
    permutations(og, buffer, size, n + 1);
    i++;
  }
}

int main(int ac, char** av){
  if(ac != 2)
    return 0;
  int size = 0;
  while(av[1][size])
    size++;
  char *buffer = calloc(size + 1, sizeof(char));
  permutations(av[1], buffer, size, 0);
}
