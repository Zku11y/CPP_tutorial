#pragma once
#include <iostream>
#include <string>
#include <map>

enum ft_lvl {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

class Harl{
private:
    void debug();
    void info();
    void warning();
    void error();

public:
    void complain(std::string level);
};