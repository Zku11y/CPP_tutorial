#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria{

    Ice();
    ~Ice();    
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    Ice(std::string const &type = "ice");

    virtual AMateria* clone() const;
    virtual void use(ICharacter &target);
};
#endif