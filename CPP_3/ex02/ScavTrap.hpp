#pragma once

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: ClapTrap{
public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();
  
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void guardGate(){std::cout << "ScavTrap is now in Gate Keeper mode\n";}

};

#endif
