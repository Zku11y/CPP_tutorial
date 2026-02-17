/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:12:39 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 21:23:09 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon& weapon): _weapon(weapon), _name(name){}

void HumanA::attack(){
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}