#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria{

protected:
    std::string type;

public:
    AMateria(AMateria const &other);
    AMateria(std::string const &type = "None");
    AMateria &operator=(AMateria const &other);
    virtual ~AMateria();

    std::string const &getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif