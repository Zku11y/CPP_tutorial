#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int ft_valid(int *buffer, int size, int row, int col){
    int i = 0;
    while(i < row){
        if(buffer[i] == col) return false;
        if(buffer[i] - i == col - row || buffer[i] + i == col + row) return false;
        i++;
    }
    return true;
}

void ft_queens(int *buffer, int size, int n){
    if(n == size){
        for(int i = 0; i < size; i++){
            printf("%d", buffer[i]);
            if(i + 1 < size)
                printf(" ");
        }
        printf("\n");
        return;
    }

    int i = 0;
    while(i < size){
        if(ft_valid(buffer, size, n, i)){
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
    int buffer[size];
    ft_queens(buffer, size, 0);
}