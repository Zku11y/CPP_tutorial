/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:12:47 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 21:27:05 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

    HumanB::HumanB(const std::string name):_weapon(NULL), _name(name){
        _name = name;
    }

    void HumanB::setWeapon(Weapon& weapon){
        // _weapon.setType(weapon.getType());
        _weapon = &weapon;
    }

    void HumanB::attack(){
        if(!_weapon)
            std::cout << _name << " has no weapon\n";
        else
            std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    }
