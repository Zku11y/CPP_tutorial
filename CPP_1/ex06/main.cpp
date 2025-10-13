#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av){
    if(ac != 2)
        return(std::cout << "wrong arguments\n", 1);
    Harl harl;
    std::string str = av[1];
    harl.complain(str);
    return 0;
}