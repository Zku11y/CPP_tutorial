#include "Header.hpp"

int main(int ac, char **av){
    if(ac != 4)
        return(std::cout << "need 4 arguments!" << std::endl, 1);
    std::ifstream file;
    std::ofstream outfile;
    file.open(av[1]);
    if(file.fail())
        return(std::cerr << "error while opening infile\n", 1);
    outfile.open((std::string(av[1]) + ".replace").c_str());
    if(outfile.fail())
        return(std::cerr << "error while opening outfile\n", 1);    
    std::string input;
    std::string to_find = av[2];
    std::string to_change = av[3];
    size_t pos;
    while(std::getline(file, input))
    {
        pos = input.find(to_find);
        while(pos != std::string::npos)
        {
            outfile << input.substr(0, pos) << to_change;
            input.erase(0, pos + to_find.length());
            pos = input.find(to_find);
        }
        outfile << input;
        if(!file.eof())
            outfile << '\n';
    }
    return 0;
}