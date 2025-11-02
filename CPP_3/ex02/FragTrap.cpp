#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
  Name = "";
  HP = 100;
  Energy = 100;
  DMG = 30;
  std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
  Name = name;
  HP = 100;
  Energy = 100;
  DMG = 30;
  std::cout << "FragTrap param constructor called\n";
}

FragTrap::~FragTrap(){std::cout << "FragTrap destructor called\n";}

void FragTrap::highFiveGuys(void){
  std::cout << "FragTrap request a High-Five from you!😄\n";
}

void FragTrap::attack(const std::string& target){
  if(Energy > 0){
    Energy--;
    std::cout << "FragTrap BITCHSLAPPED " << target << " which dealt " << DMG << " damage! >:D\n";
  }
  else {
    std::cout << "FragTrap doesn't have anymore energy X _ X\n";
  }
}

void FragTrap::takeDamage(unsigned int amount){
  if(HP - (int)amount >= 0)
    HP -= amount;
  else
    HP = 0;
  std::cout << "FragTrap got his shit rocked from receiving " << amount << " of damage, and now his HP is " << HP << " >:(\n";
}

void FragTrap::beRepaired(unsigned int amount){
  if(Energy > 0){
    HP += amount;
    Energy--;
    std::cout << "FragTrap healed his ass gaining " << amount << " HP back!, now his HP is at " << HP << " :D\n";
  }
  else
    std::cout << "FragTrap doesn't have anymore energy X _ X\n";
}
