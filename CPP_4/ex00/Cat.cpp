#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
    std::cout << "The Cat Default constructor called\n";
}

Cat::Cat(std::string type): Animal(type){
    std::cout << "The Cat String Param constructor called\n";
}

Cat::Cat(const Cat &other): Animal(other){
    std::cout << "The Cat Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other){
    if(this != &other)
        this->type = other.type;
    std::cout << "The Cat Copy Assignment Operator called\n";
    return *this;
}

Cat::~Cat(){
    std::cout << "The Cat Destructor called\n";
}

void Cat::makeSound() const{
    std::cout << "The Cat " << type << " says : MEOOOWWW 😺\n";
}
