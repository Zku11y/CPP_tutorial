/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:54:53 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 21:11:47 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>


class Zombie
{
private:
    std::string name;

public:
    void announce(void);
    void assign_name(std::string new_name);
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif