#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain()){
    std::cout << "The Dog Default constructor called\n";
}

Dog::Dog(std::string type): Animal(type), brain(new Brain()){
    std::cout << "The Dog String Param constructor called\n";
}

Dog::Dog(const Dog &other): Animal(other), brain(new Brain(*other.brain)){
    std::cout << "The Dog Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other){
    if(this != &other){
        this->type = other.type;
        if(other.brain){
            delete(this->brain);
            this->brain = new Brain(*other.brain);
        }
    }
    std::cout << "The Dog Copy Assignment Operator called\n";
    return *this;
}

Dog::~Dog(){
    delete brain;
    std::cout << "The Dog Destructor called\n";
}

void Dog::makeSound() const{
    std::cout << "The Dog " << type << " says: WOOF WOOF 🐶\n";
}
