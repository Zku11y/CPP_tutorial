#include <iostream>
#include <string>
#include "Harl.hpp"

int main(){
    Harl harl;
    harl.complain("debug");
    harl.complain("info");
    harl.complain("warning");
    harl.complain("error");
}