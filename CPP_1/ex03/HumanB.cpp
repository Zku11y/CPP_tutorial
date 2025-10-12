#include "HumanB.hpp"

HumanB::HumanB(const std::string name):_weapon(""), _name(name){
    _name = name;
}

void HumanB::setWeapon(Weapon weapon){
    _weapon = weapon.getType();
}

void HumanB::attack(){
    std::cout << _name << " attacks with their " << _weapon << std::endl;
}