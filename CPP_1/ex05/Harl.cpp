/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:49:15 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/14 18:05:22 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(){
    std::cout << "I love having extra bacon for my " <<
        "7XL-double-cheese-triple-pickle-special-ketchup" <<
        " burger. I really do!" << std::endl;
}

void Harl::info(){
    std::cout << "I cannot believe adding extra bacon costs" <<
    " more money. You didn’t put enough bacon in my burger" <<
    "! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(){
    std::cout << "I think I deserve to have some extra bacon for free." <<
    " I’ve been coming for years, whereas you started" <<
    " working here just last month." << std::endl;
}

void Harl::error(){
    std::cout << "This is unacceptable! I want to" <<
    " speak to the manager now." << std::endl;
}

typedef  void(Harl::*fct_ptr)();

void Harl::complain(std::string level){

    std::string lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*func[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int i = 0;
    while(level != lvl[i] && i < 4)
        i++;

    switch (i){

        case 0:
            (this->*func[0])();
            break;

        case 1:
            (this->*func[1])();
            break;

        case 2:
            (this->*func[2])();
            break;

        case 3:
            (this->*func[3])();
            break;

        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    };
}