#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon): _weapon(weapon), _name(name){}

void HumanA::attack(){
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}