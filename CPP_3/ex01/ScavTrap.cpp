/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:48:53 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/17 16:20:28 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(){
  this->Name = "";
  this->HP = 100;
  this->Energy = 50;
  this->DMG = 20;
  std::cout << "ScavTrap Default constructor called\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
  this->Name = name;
  this->HP = 100;
  this->Energy = 50;
  this->DMG = 20;
  std::cout << "ScavTrap Param constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other.Name){
  this->Name = other.Name;
  this->HP = other.HP;
  this->Energy = other.Energy;
  this->DMG = other.DMG;
  std::cout << "ScavTrap Param constructor called\n";

}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap desctructor called\n";
}

void ScavTrap::attack(const std::string& target){
  if(this->Energy > 0){
    this->Energy--;
    std::cout << "ScavTrap BITCHSLAPPED " << target << " which dealt " << this->DMG << " damage! >:D\n";
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
  std::cout << "ScavTrap got his shit rocked from receiving " << amount << " of damage, and now his HP is " << this->HP << " >:(\n";
}

void ScavTrap::beRepaired(unsigned int amount){
  if(this->Energy > 0){
    this->HP += amount;
    this->Energy--;
    std::cout << "ScavTrap healed his ass gaining " << amount << " HP back!, now his HP is at " << this->HP << " :D\n";
  }
  else
    std::cout << "ScavTrap doesn't have anymore energy X _ X\n";
}

