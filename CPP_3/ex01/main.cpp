#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
  ScavTrap scavtrap("person 1");
  std::string target("person 2");
  scavtrap.attack(target);
  scavtrap.takeDamage(5);
  scavtrap.beRepaired(3);
}
