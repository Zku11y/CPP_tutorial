/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:03:17 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 21:04:53 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){
  FragTrap fragtrap("person 1");
  std::string target("person 2");
  fragtrap.attack(target);
  fragtrap.takeDamage(5);
  fragtrap.beRepaired(3);
  fragtrap.highFiveGuys();
}
