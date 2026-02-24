#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << "AMateria Default constructor called\n";
}

AMateria::AMateria(AMateria const &other): type(other.type){
    std::cout << "AMateria Copy constructor called\n";
}

AMateria::AMateria(std::string const &type): type(type){
    std::cout << "AMateria Param constructor called\n";
}

AMateria &AMateria::operator=(AMateria const &other){
    if(this != &other){
        this->type = other.type;
    }
    std::cout << "AMateria Copy assignment Operator called\n";
    return *this;
}

AMateria::~AMateria(){
    std::cout << "AMateria destructor called\n";
}

std::string const &AMateria::getType() const{
    return type;
}

void AMateria::use(ICharacter &target){
        (void) target;
}