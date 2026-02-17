/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:06:40 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 11:57:37 by mdakni           ###   ########.fr       */
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
    Zombie(std::string str);
    ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif