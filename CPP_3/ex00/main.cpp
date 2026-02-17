/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:47:35 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/17 12:47:48 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
  ClapTrap claptrap("person 1");
  std::string target("person 2");
  claptrap.attack(target);
  claptrap.takeDamage(5);
  claptrap.beRepaired(3);
}
