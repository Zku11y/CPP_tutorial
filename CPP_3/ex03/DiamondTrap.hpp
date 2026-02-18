/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:24:09 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 19:40:05 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
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
