#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap(){
  this->Name = "";
  HP = 100;
  Energy = 50;
  DMG = 30;
  std::cout << "DiamondTrap default constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
  this->Name = name;
  HP = 100;
  Energy = 50;
  DMG = 30;
  std::cout << "DiamondTrap param constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other.Name + "_clap_name"), ScavTrap(other.Name), FragTrap(other.Name){
  this->Name = other.Name;
  HP = 100;
  Energy = 50;
  DMG = 30;
  std::cout << "DiamondTrap copy constructor called\n";

}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other){
  if(this != &other){
    this->Name = other.Name;
    HP = other.HP;
    Energy = other.Energy;
    DMG = other.DMG;
  }
  
  std::cout << "DiamondTrap assignement operator called\n";
  return (*this);
}

DiamondTrap::~DiamondTrap(){
  std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::attack(const std::string& target){
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
  std::cout << "DiamondTrap's name is : " << this->Name << ", ClapTrap's name is : " << Name << std::endl;
}




