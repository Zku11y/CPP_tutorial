/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:12:41 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 21:23:47 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA{
private:
    Weapon& _weapon;
    std::string _name;

public:
    HumanA(const std::string name, Weapon& weapon);
    void attack();
};

#endif