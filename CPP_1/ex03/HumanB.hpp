/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:12:49 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 21:23:38 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB{
private:
    Weapon* _weapon;
    std::string _name;

public:
    HumanB(const std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
};

#endif