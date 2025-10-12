#pragma once
#include <iostream>
#include <string>


class Weapon{
private:
    std::string type;

public:
    const std::string& getType();
    void setType(std::string str);
    Weapon(std::string new_type);
};
