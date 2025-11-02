#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target){
  if(Energy > 0){
    Energy--;
    std::cout << "ClapTrap BITCHSLAPPED " << target << " which dealt " << DMG << " damage! >:D\n";
  }
  else {
    std::cout << "ClapTrap doesn't have anymore energy X _ X\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount){
  if(HP - (int)amount >= 0)
    HP -= amount;
  else
    HP = 0;
  std::cout << "ClapTrap got his shit rocked from receiving " << amount << " of damage, and now his HP is " << HP << " >:(\n";
}

void ClapTrap::beRepaired(unsigned int amount){
  if(Energy > 0){
    HP += amount;
    Energy--;
    std::cout << "ClapTrap healed his ass gaining " << amount << " HP back!, now his HP is at " << HP << " :D\n";
  }
  else
    std::cout << "ClapTrap doesn't have anymore energy X _ X\n";
}
