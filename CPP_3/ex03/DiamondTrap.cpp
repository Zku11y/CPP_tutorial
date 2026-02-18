/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:24:06 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 20:32:17 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(std::string("_clap_name")), ScavTrap(), FragTrap(), Name(""){
  this->HP = FragTrap::HP;
  this->Energy = ScavTrap::Energy;
  this->DMG = FragTrap::DMG;
  std::cout << "DiamondTrap " << this->Name << " Default Constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), Name(name){
  this->HP = FragTrap::HP;
  this->Energy = ScavTrap::Energy;
  this->DMG = FragTrap::DMG;
  std::cout << "DiamondTrap " << this->Name << " Param Constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other.Name + "_clap_name"), ScavTrap(other.Name), FragTrap(other.Name), Name(other.Name){
  this->HP = FragTrap::HP;
  this->Energy = ScavTrap::Energy;
  this->DMG = FragTrap::DMG;
  std::cout << "DiamondTrap " << this->Name << " Copy Constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other){
  if(this != &other){
    this->Name = other.Name;
    HP = other.HP;
    Energy = other.Energy;
    DMG = other.DMG;
  }
  
  std::cout << "DiamondTrap " << this->Name << " Copy assignment operator called\n";  
  return (*this);
}

DiamondTrap::~DiamondTrap(){
  std::cout << "DiamondTrap " << this->Name << " Destructor called\n";
}

void DiamondTrap::attack(const std::string& target){
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
  std::cout << "DiamondTrap's name is : " << this->Name << ", ClapTrap's name is : " << ClapTrap::Name << std::endl;
}




