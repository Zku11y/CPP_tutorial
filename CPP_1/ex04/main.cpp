#include "Header.hpp"

int main(int ac, char **av){
    if(ac != 4)
        return(std::cout << "need 4 arguments!" << std::endl, 1);
    std::ifstream file;
    file.open(av[1]);
    if(file.fail())
        return(std::cerr << "error while opening file\n", 1);
    std::string input;
    while(std::getline(file, input))
    {
        while
    }
}