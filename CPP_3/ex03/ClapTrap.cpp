/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:47:42 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 20:30:23 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
  :Name(""), HP(10), Energy(10), DMG(0){
  std::cout << "ClapTrap " << this->Name << " Default Constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
  : Name(name), HP(10), Energy(10), DMG(0){
  std::cout << "ClapTrap " << this->Name << " Param Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
  : Name(other.Name), HP(other.HP), Energy(other.Energy), DMG(other.DMG){
  std::cout << "ClapTrap " << this->Name << " Copy Constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
if(this != &other){
  this->Name = other.Name;
  this->HP = other.HP;
  this->Energy = other.Energy;
  this->DMG = other.DMG;
}
  std::cout << "ClapTrap " << this->Name << " Copy assignment operator called\n";
  return *this;
}

ClapTrap::~ClapTrap(){
  std::cout << "ClapTrap " << this->Name << " Destructor called\n";
}

void ClapTrap::attack(const std::string& target){
  if(this->Energy > 0){
    this->Energy--;
    std::cout << "ClapTrap " << this->Name << " Hit " << target << " which dealt " << this->DMG << " damage! >:D\n";
  }
  else {
    std::cout << "ClapTrap " << this->Name << " doesn't have anymore energy X _ X\n";
  }
}

void ClapTrap::takeDamage(unsigned int amount){
  if(this->HP - (int)amount >= 0)
    this->HP -= amount;
  else
    this->HP = 0;
  std::cout << "ClapTrap " << this->Name << " got hit with " << amount << " damage, and now his HP is " << this->HP << " >:(\n";
}

void ClapTrap::beRepaired(unsigned int amount){
  if(this->Energy > 0){
    this->HP += amount;
    this->Energy--;
    std::cout << "ClapTrap " << this->Name << " healed himself gaining " << amount << " HP back!, now his HP is at " << this->HP << " :D\n";
  }
  else
    std::cout << "ClapTrap " << this->Name << " doesn't have anymore energy X _ X\n";
}
