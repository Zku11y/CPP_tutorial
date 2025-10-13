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

    ft_lvl lvl;

    if(!level.compare("debug")){lvl = DEBUG;}
    else if(!level.compare("info")){lvl = INFO;}
    else if(!level.compare("warning")){lvl = WARNING;}
    else if(!level.compare("error")){lvl = ERROR;}
    else{lvl = UNKNOWN;}

    switch (lvl){
        case UNKNOWN:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;

        case DEBUG:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();

        case INFO:
            std::cout << "[ INFO ]" << std::endl;
            info();

        case WARNING:
            std::cout << "[ WARNING ]" << std::endl;
            warning();

        case ERROR:
            std::cout << "[ ERROR ]" << std::endl;
            error();
    };
}