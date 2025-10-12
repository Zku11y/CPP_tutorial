#include "Zombie.hpp"

Zombie::Zombie(std::string str): name(str){}

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
