/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:48:46 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/18 17:37:56 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(){
  ScavTrap scavtrap("person 1");
  std::string target("person 2");
  scavtrap.attack(target);
  scavtrap.takeDamage(5);
  scavtrap.beRepaired(3);
}
