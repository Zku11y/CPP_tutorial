#include <iostream>
#include <string>

void PrintValue(std::string str)
{
    std::cout << "Value : " << str << std::endl;
}

int main(){

    std::string str = "PrintValue";
    auto fct_ptr = str;
    fct_ptr("testing");
}