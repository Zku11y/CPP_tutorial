#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    this->type = "WrongCat";
    std::cout << "The WrongCat " << type << "'s Default constructor called\n";
}

WrongCat::WrongCat(std::string type): WrongAnimal(type){
    std::cout << "The WrongCat " << type << "'s String Param constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other){
    std::cout << "The WrongCat " << type << "'s Copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other){
    if(this != &other)
        this->type = other.type;
    std::cout << "The WrongCat " << type << "'s Copy Assignment Operator called\n";
    return *this;
}

WrongCat::~WrongCat(){
    std::cout << "The WrongCat " << type << "'s Destructor called\n";
}

void WrongCat::makeSound() const{
    std::cout << "The WrongCat " << type << " says : MEOOOWWW 😺\n";
}
