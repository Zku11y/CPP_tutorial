#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria{

public:
    ~Cure();    
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);
    Cure(std::string const &type = "cure");

    virtual AMateria* clone() const;
    virtual void use(ICharacter &target);
};

#endif