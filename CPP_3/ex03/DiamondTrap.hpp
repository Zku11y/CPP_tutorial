#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, ScavTrap{
private:
  std::string Name;

public:
  DiamondTrap();
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap& other);
  DiamondTrap &operator=(const DiamondTrap& other);
  ~DiamondTrap();

  void attack(const std::string& target);
  void whoAmI();
};

#endif
