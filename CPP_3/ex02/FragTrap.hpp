/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:03:10 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 21:02:02 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: ClapTrap{
public:
  FragTrap();
  FragTrap(std::string name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &other);
  ~FragTrap();
  void highFiveGuys(void);
  void attack(const std::string& target);

};

#endif
