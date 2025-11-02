#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
  DiamondTrap diamondtrap("person 1");
  std::string target("person 2");
  diamondtrap.attack(target);
  diamondtrap.highFiveGuys();
  diamondtrap.guardGate();
  diamondtrap.whoAmI();
}
