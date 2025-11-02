#pragma once

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>


class ClapTrap{

protected:
  std::string Name;
  int HP;
  int Energy;
  int DMG;

public:
  ClapTrap(): Name(""), HP(10), Energy(10), DMG(0){
    std::cout << "ClapTrap Default constructor called\n";
  }

  ClapTrap(std::string name)
    : Name(name), HP(10), Energy(10), DMG(0){
    std::cout << "ClapTrap Param Constructor called\n";
  }
  ~ClapTrap(){
    std::cout << "ClapTrap Destructor called\n";
  }
  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
