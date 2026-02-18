/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:48:53 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 17:38:57 by skully           ###   ########.fr       */
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
  this->Name = other.Name;
  this->HP = other.HP;
  this->Energy = other.Energy;
  this->DMG = other.DMG;
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

void ScavTrap::takeDamage(unsigned int amount){
  if(this->HP - (int)amount >= 0)
    this->HP -= amount;
  else
    this->HP = 0;
  std::cout << "ScavTrap " << this->Name << " got hit with " << amount << " damage, and now his HP is " << this->HP << " >:(\n";
}

void ScavTrap::beRepaired(unsigned int amount){
  if(this->Energy > 0){
    this->HP += amount;
    this->Energy--;
    std::cout << "ScavTrap " << this->Name << " healed himself gaining " << amount << " HP back!, now his HP is at " << this->HP << " :D\n";
  }
  else
    std::cout << "ScavTrap " << this->Name << " doesn't have anymore energy X _ X\n";
}

void ScavTrap::guardGate(){
  std::cout << "ScavTrap is now in Gate Keeper mode\n";
}
