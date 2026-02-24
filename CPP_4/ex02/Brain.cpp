#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain's Default constructor called\n";
}

Brain::Brain(const Brain &other){
    for(int i = 0; i < 100; i++){
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain's Copy constructor called\n";
}

Brain &Brain::operator=(const Brain &other){
    if(this != &other){
        for(int i = 0; i < 100; i++){
            this->ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain's Copy Assignment Operator called\n";
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain's Destructor called\n";
}