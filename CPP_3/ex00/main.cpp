#include "ClapTrap.hpp"

int main(){
  ClapTrap claptrap("person 1");
  std::string target("person 2");
  claptrap.attack(target);
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
}
