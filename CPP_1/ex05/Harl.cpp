#include "Harl.hpp"

void Harl::debug(){
    std::cout << "I love having extra bacon for my " <<
        "7XL-double-cheese-triple-pickle-special-ketchup" <<
        " burger. I really do!" << std::endl;
}

void Harl::info(){
    std::cout << " love having extra bacon for my " <<
    "7XL-double-cheese-triple-pickle-special-" <<
    "ketchup burger. I really do!" << std::endl;
}

void Harl::warning(){
    std::cout << " love having extra bacon for my" <<
    " 7XL-double-cheese-triple-pickle-special-" <<
    "ketchup burger. I really do!" << std::endl;
}

void Harl::error(){
    std::cout << "This is unacceptable! I want to" <<
    " speak to the manager now." << std::endl;
}

typedef  void(Harl::*fct_ptr)();

void Harl::complain(std::string level){

    std::map<std::string, fct_ptr> ft_map = {
        {"debug", &Harl::debug},
        {"info", &Harl::info},
        {"warning", &Harl::warning},
        {"error", &Harl::error}
    };

    auto tmp = ft_map.find(level);
    if()
}