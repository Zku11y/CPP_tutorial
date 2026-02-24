#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){
    std::cout << "Ice default constructor called\n";
}

Ice::Ice(std::string const &type): AMateria(type){
    std::cout << "Ice Param constructor called\n";
}

Ice::Ice(const Ice &other): AMateria(other){
    std::cout << "Ice Copy constructor called\n";
}

Ice &Ice::operator=(const Ice &other){
    if(this != &other){
        AMateria::operator=(other);
    }
    return *this;
}

Ice::~Ice(){
    std::cout << "Ice destructor called\n";
}

AMateria *Ice::clone() const{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}