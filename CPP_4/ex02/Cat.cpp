#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain()){
    std::cout << "The Cat Default constructor called\n";
}

Cat::Cat(std::string type): Animal(type), brain(new Brain()){
    std::cout << "The Cat String Param constructor called\n";
}

Cat::Cat(const Cat &other): Animal(other), brain(new Brain(*other.brain)){
    std::cout << "The Cat Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other){
    if(this != &other){
        this->type = other.type;
        if(other.brain){
            delete(this->brain);
            this->brain = new Brain(*other.brain);
        }
    }
    std::cout << "The Cat Copy Assignment Operator called\n";
    return *this;
}

Cat::~Cat(){
    delete brain;
    std::cout << "The Cat Destructor called\n";
}

void Cat::makeSound() const{
    std::cout << "The Cat " << type << " says : MEOOOWWW 😺\n";
}
