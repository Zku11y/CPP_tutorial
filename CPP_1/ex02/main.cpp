#include <iostream>
#include <string>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string* ptr = &str;
    std::string& ref = str;
    std::cout << "str memory : " << &str << std::endl;
    std::cout << "ptr value  : " << ptr << std::endl;
    std::cout << "ref memory : " << &ref << std::endl;
    std::cout << "str value  : " << str << std::endl;
    std::cout << "ptr deref  : " << *ptr << std::endl;
    std::cout << "ref value  : " << ref << std::endl;
}