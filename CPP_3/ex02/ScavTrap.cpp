#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
  Name = "";
  HP = 100;
  Energy = 50;
  DMG = 20;
  std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
  Name = name;
  HP = 100;
  Energy = 50;
  DMG = 20;
  std::cout << "ScavTrap Param constructor called\n";
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap desctructor called\n";
}

void ScavTrap::attack(const std::string& target){
  if(Energy > 0){
    Energy--;
    std::cout << "ScavTrap BITCHSLAPPED " << target << " which dealt " << DMG << " damage! >:D\n";
  }
  else {
    std::cout << "ScavTrap doesn't have anymore energy X _ X\n";
  }
}

void ScavTrap::takeDamage(unsigned int amount){
  if(HP - (int)amount >= 0)
    HP -= amount;
  else
    HP = 0;
  std::cout << "ScavTrap got his shit rocked from receiving " << amount << " of damage, and now his HP is " << HP << " >:(\n";
}

void ScavTrap::beRepaired(unsigned int amount){
  if(Energy > 0){
    HP += amount;
    Energy--;
    std::cout << "ScavTrap healed his ass gaining " << amount << " HP back!, now his HP is at " << HP << " :D\n";
  }
  else
    std::cout << "ScavTrap doesn't have anymore energy X _ X\n";
}

