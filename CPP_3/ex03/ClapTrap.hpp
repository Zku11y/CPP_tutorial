/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:47:39 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 20:25:46 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
  ClapTrap();
  ClapTrap(const ClapTrap &other);
  ClapTrap(std::string name);
  ClapTrap &operator=(const ClapTrap &other);
  virtual ~ClapTrap();

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

};

#endif
