#include "Weapon.hpp"

const std::string& Weapon::getType(){return type;}
void Weapon::setType(std::string str){type = str;}

Weapon::Weapon(std::string new_type){
    type = new_type;
}