#include "AMateria.hpp"

AMateria::AMateria(){
}

AMateria::AMateria(AMateria const &other): type(other.type){
}

AMateria::AMateria(std::string const &type): type(type){
}

AMateria &AMateria::operator=(AMateria const &other){
    if(this != &other){
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria(){
}

std::string const &AMateria::getType() const{
    return type;
}

void AMateria::use(ICharacter &target){
        (void) target;
}