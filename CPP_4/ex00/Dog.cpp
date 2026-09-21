#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
    std::cout << "The Dog Default constructor called\n";
}

Dog::Dog(std::string type): Animal(type){
    std::cout << "The Dog String Param constructor called\n";
}

Dog::Dog(const Dog &other): Animal(other){
    std::cout << "The Dog Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other){
    if(this != &other)
        this->type = other.type;
    std::cout << "The Dog Copy Assignment Operator called\n";
    return *this;
}

Dog::~Dog(){
    std::cout << "The Dog Destructor called\n";
}

void Dog::makeSound() const{
    std::cout << "The Dog " << type << " says: WOOF WOOF 🐶\n";
}
