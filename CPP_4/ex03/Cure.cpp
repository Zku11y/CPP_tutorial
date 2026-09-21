#include "Cure.hpp"

Cure::Cure(std::string const &type): AMateria(type){
    std::cout << "Cure Default constructor called\n";
}

Cure::Cure(const Cure &other): AMateria(other){
    std::cout << "Cure Copy constructor called\n";
}

Cure &Cure::operator=(const Cure &other){
    std::cout << "Cure Copy assignment operator called\n";
    if(this != &other){
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure(){
    std::cout << "Cure Default destructor called\n";
}

AMateria *Cure::clone() const{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}