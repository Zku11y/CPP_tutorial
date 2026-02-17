/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:13:03 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/11 21:13:30 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>


class Weapon{
private:
    std::string type;

public:
    const std::string& getType();
    void setType(std::string str);
    Weapon(std::string new_type);
};

#endif