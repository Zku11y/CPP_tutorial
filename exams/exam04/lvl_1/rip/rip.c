#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// int to_remove(char *buff){
//     int open = 0;
//     int close = 0;
//     int i = 0;
//     while(buff[i]){
//         if(buff[i] == '(')
//             open++;
//         if(buff[i] == ')'){
//             if(open > 0)
//                 open--;
//             else
//                 close++;
//         }
//         i++;
//     }
//     return close + open;
// }

// void ft_rip(char *og, int pos, int open, int to_remove, char *buff){
//     if(!og[pos]){
//         if(open == 0 && to_remove == 0){
//             buff[pos] = '\0';
//             puts(buff);
//         }
//         return;
//     }

//     if(to_remove > 0){
//         buff[pos] = ' ';
//         ft_rip(og, pos + 1, open, to_remove - 1, buff);
//     }
//     if(og[pos] == '('){
//         buff[pos] = '(';
//         ft_rip(og, pos + 1, open + 1, to_remove, buff);
//     }
//     else if(og[pos] == ')'){
//         if(open > 0){
//             buff[pos] = ')';
//             ft_rip(og, pos + 1, open - 1, to_remove, buff);
//         }
//     }
//     else{
//         buff[pos] = og[pos];
//         ft_rip(og, pos + 1, open, to_remove, buff);
//     }
// }

// int main(int ac, char **av){
//     if(ac != 2)
//         return 1;

//     int size = 0;
//     while(av[1][size])
//         size++;
//     char tmp[size + 1];
//     tmp[size] = '\0';
//     ft_rip(av[1], 0, 0, to_remove(av[1]),tmp);
// }


void solve(char *str, int pos, int open, int to_remove, char *tmp)
{
    if (!str[pos])
    {
        if (open == 0 && to_remove == 0)
        {
            tmp[pos] = '\0';
            puts(tmp);
        }
        return;
    }
    if (to_remove > 0)
    {
        tmp[pos] = ' ';
        solve(str, pos + 1, open, to_remove - 1, tmp);
    }
    if (str[pos] == '(')
    {
        tmp[pos] = '(';
        solve(str, pos + 1, open + 1, to_remove, tmp);
    }
    else if (str[pos] == ')')
    {
        if (open > 0)
        {
            tmp[pos] = ')';
            solve(str, pos + 1, open - 1, to_remove, tmp);
        }
    }
    else
    {
        tmp[pos] = str[pos];
        solve(str, pos + 1, open, to_remove, tmp);
    }
}

int total_removals(char *str)
{
    int open = 0, close = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '(')
            open++;
        else if (str[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
    }
    return open + close;
}

int main(int ac, char *av[])
{
    if (ac != 2)
        return (1);

    char *str = av[1];
    int n = 0;
    while (str[n])
        n++;

    char temp[n + 1];
    solve(str, 0, 0, total_removals(str), temp);
}