#pragma once
#include <iostream>
#include <string>
#include <map>
class Harl{
private:
    void debug();
    void info();
    void warning();
    void error();

public:
    void complain(std::string level);
};