#pragma once
#include "Weapon.hpp"

class HumanB{
private:
    std::string _weapon;
    std::string _name;

public:
    HumanB(const std::string name);
    void setWeapon(Weapon weapon);
    void attack();
};