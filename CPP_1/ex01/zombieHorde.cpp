/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:47:25 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 21:08:24 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::assign_name(std::string new_name){name = new_name;}


Zombie* zombieHorde(int N, std::string name)
{
    Zombie* z = new Zombie[N];
    for(int i = 0; i < N; i++)
        z[i].assign_name(name);
    return z;
}