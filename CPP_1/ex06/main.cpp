/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:55:47 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/10 20:57:10 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av){
    if(ac != 2)
        return(std::cout << "wrong arguments\n", 1);
    Harl harl;
    std::string str = av[1];
    harl.complain(str);
    return 0;
}
