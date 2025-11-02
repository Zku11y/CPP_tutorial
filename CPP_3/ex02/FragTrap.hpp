#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: ClapTrap{
public:
  FragTrap();
  FragTrap(std::string name);
  ~FragTrap();
  void highFiveGuys(void);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif
