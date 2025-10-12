#pragma once
#include <iostream>
#include <string>


class Zombie
{
private:
    std::string name;

public:
    void announce(void);
    void assign_name(std::string new_name){name = new_name;}
};

Zombie* zombieHorde(int N, std::string name);