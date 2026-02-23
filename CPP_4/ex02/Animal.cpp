#include "Animal.hpp"

Animal::Animal(): type("Unknown"){
    std::cout << "The Animal " << type << "'s Default constructor called\n";
}

Animal::Animal(std::string type): type(type){
    std::cout << "The Animal " << type << "'s String Param constructor called\n";
}

Animal::Animal(const Animal &other): type(other.type){
    std::cout << "The Animal " << type << "'s Copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other){
    if(this != &other)
        this->type = other.type;
    std::cout << "The Animal " << type << "'s Copy Assignment Operator called\n";
    return *this;
}

Animal::~Animal(){
    std::cout << "The Animal " << type << "'s Destructor called\n";
}

std::string Animal::getType() const{
    return this->type;
}