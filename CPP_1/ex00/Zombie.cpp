/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:06:38 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 11:35:37 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string str): name(str){}

void Zombie::announce(void){
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie(){
    std::cout << name << ": Destructioooooooooon...\n";
}
