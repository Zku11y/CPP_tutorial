#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Unknown"){
    std::cout << "The WrongAnimal " << type << "'s Default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type): type(type){
    std::cout << "The WrongAnimal " << type << "'s String Param constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type){
    std::cout << "The WrongAnimal " << type << "'s Copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
    if(this != &other)
        this->type = other.type;
    std::cout << "The WrongAnimal " << type << "'s Copy Assignment Operator called\n";
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "The WrongAnimal " << type << "'s Destructor called\n";
}

void WrongAnimal::makeSound() const{
    std::cout << "The WrongAnimal " << type << " makes generic WrongAnimal sounds\n";
}

std::string WrongAnimal::getType() const{
    return this->type;
}