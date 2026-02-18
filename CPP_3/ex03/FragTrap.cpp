/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:03:06 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 20:31:55 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
  this->Name = "";
  this->HP = 100;
  this->Energy = 100;
  this->DMG = 30;
  std::cout << "FragTrap " << this->Name << " Default Constructor called\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
  this->Name = name;
  this->HP = 100;
  this->Energy = 100;
  this->DMG = 30;
  std::cout << "FragTrap " << this->Name << " Param Constructor called\n";
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other.Name){
  this->Name = other.Name;
  this->HP = other.HP;
  this->Energy = other.Energy;
  this->DMG = other.DMG;
  std::cout << "FragTrap " << this->Name << " Copy Constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other){
if(this != &other){
  this->Name = other.Name;
  this->HP = other.HP;
  this->Energy = other.Energy;
  this->DMG = other.DMG;
}
  std::cout << "FragTrap " << this->Name << " Copy assignment operator called\n";  
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->Name << " Destructor called\n";
}

void FragTrap::attack(const std::string& target){
  if(this->Energy > 0){
    this->Energy--;
    std::cout << "FragTrap " << this->Name << " Hit " << target << " which dealt " << this->DMG << " damage! >:D\n";
  }
  else {
    std::cout << "FragTrap " << this->Name << " doesn't have anymore energy X _ X\n";
  }
}

void FragTrap::highFiveGuys(void){
  std::cout << "FragTrap " << this->Name << " is asking for a couple CRISP high-fives :>\n";
}
