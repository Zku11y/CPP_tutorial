#pragma once
#include "Weapon.hpp"

class HumanB{
private:
    Weapon* _weapon;
    std::string _name;

public:
    HumanB(const std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
};
