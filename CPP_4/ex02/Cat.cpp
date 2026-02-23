#include "Cat.hpp"

Cat::Cat(): Animal(), brain(new Brain()){
    this->type = "Cat";
    std::cout << "The Cat " << type << "'s Default constructor called\n";
}

Cat::Cat(std::string type): Animal(type), brain(new Brain()){
    std::cout << "The Cat " << type << "'s String Param constructor called\n";
}

Cat::Cat(const Cat &other): Animal(other), brain(new Brain(*other.brain)){
    std::cout << "The Cat " << type << "'s Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other){
    if(this != &other){
        this->type = other.type;
        for(int i = 0; i < 100; i++)
            this->brain[i] = other.brain[i];
    }
    std::cout << "The Cat " << type << "'s Copy Assignment Operator called\n";
    return *this;
}

Cat::~Cat(){
    delete brain;
    std::cout << "The Cat " << type << "'s Destructor called\n";
}

void Cat::makeSound() const{
    std::cout << "The Cat " << type << " says : MEOOOWWW 😺\n";
}
