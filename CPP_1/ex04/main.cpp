/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:54:57 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 21:30:31 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

int main(int ac, char **av){
    if(ac != 4)
        return(std::cout << "not enough arguments!" << std::endl, 1);
    std::ifstream infile;
    std::ofstream outfile;
    infile.open(av[1]);
    if(infile.fail())
        return(std::cerr << "error while opening infile\n", 1);
    outfile.open((std::string(av[1]) + ".replace").c_str());
    if(outfile.fail())
        return(std::cerr << "error while opening outfile\n", 1);    
    std::string input;
    std::string to_find = av[2];
    std::string to_change = av[3];
    size_t pos;
    while(std::getline(infile, input))
    {
        pos = input.find(to_find);
        while(pos != std::string::npos)
        {
            outfile << input.substr(0, pos) << to_change;
            input.erase(0, pos + to_find.length());
            pos = input.find(to_find);
        }
        outfile << input;
        if(!infile.eof())
            outfile << '\n';
    }
    return 0;
}