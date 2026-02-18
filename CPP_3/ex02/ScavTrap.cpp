/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:48:53 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 20:31:34 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
  this->Name = "";
  this->HP = 100;
  this->Energy = 50;
  this->DMG = 20;
  std::cout << "ScavTrap " << this->Name << " Default Constructor called\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
  this->Name = name;
  this->HP = 100;
  this->Energy = 50;
  this->DMG = 20;
  std::cout << "ScavTrap " << this->Name << " Param Constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other.Name){
  this->Name = other.Name;
  this->HP = other.HP;
  this->Energy = other.Energy;
  this->DMG = other.DMG;
  std::cout << "ScavTrap " << this->Name << " Copy Constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
if(this != &other){
  this->Name = other.Name;
  this->HP = other.HP;
  this->Energy = other.Energy;
  this->DMG = other.DMG;
}
  std::cout << "ScavTrap " << this->Name << " Copy assignment operator called\n";  
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->Name << " Destructor called\n";
}

void ScavTrap::attack(const std::string& target){
  if(this->Energy > 0){
    this->Energy--;
    std::cout << "ScavTrap " << this->Name << " Hit " << target << " which dealt " << this->DMG << " damage! >:D\n";
  }
  else {
    std::cout << "ScavTrap doesn't have anymore energy X _ X\n";
  }
}

void ScavTrap::guardGate(){
  std::cout << "ScavTrap " << this->Name << " is now in Gate Keeper mode\n";
}
