#include "Animal.hpp"

Animal::Animal(): type("Unknown"){
    std::cout << "The Animal Default constructor called\n";
}

Animal::Animal(std::string type): type(type){
    std::cout << "The Animal String Param constructor called\n";
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

std::string Animal::getType() const{
    return this->type;
}