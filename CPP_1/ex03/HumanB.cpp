#include "HumanB.hpp"

HumanB::HumanB(const std::string name):_weapon(NULL), _name(name){
    _name = name;
}

void HumanB::setWeapon(Weapon& weapon){
    // _weapon.setType(weapon.getType());
    _weapon = &weapon;
}

void HumanB::attack(){
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
