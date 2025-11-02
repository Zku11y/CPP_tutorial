#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
  FragTrap fragtrap("person 1");
  std::string target("person 2");
  fragtrap.attack(target);
  fragtrap.takeDamage(5);
  fragtrap.beRepaired(3);
  fragtrap.highFiveGuys();
}
