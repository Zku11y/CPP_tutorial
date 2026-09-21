#include "Animal.hpp"

Animal::Animal(): type("Unknown"){
    std::cout << "The Animal Default constructor called\n";
}

Animal::Animal(std::string type): type(type){
    std::cout << "The Animal Param constructor called\n";
}

Animal::Animal(const Animal &other): type(other.type){
    std::cout << "The Animal Copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other){
    if(this != &other)
        this->type = other.type;
    std::cout << "The Animal Copy Assignment Operator called\n";
    return *this;
}

Animal::~Animal(){
    std::cout << "The Animal Destructor called\n";
}

void Animal::makeSound() const{
    std::cout << "The Animal " << type << " makes generic Animal sounds\n";
}

std::string Animal::getType() const{
    return this->type;
}