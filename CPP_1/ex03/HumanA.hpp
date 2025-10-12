#pragma once
#include "Weapon.hpp"

class HumanA{
private:
    Weapon _weapon;
    std::string _name;

public:
    HumanA(const std::string& name, const Weapon& weapon);
    void attack();
};