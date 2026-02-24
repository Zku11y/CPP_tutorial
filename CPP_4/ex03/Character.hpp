#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter{
private:
    std::string name;
    int sk_floor_i;

    AMateria* inv[4];
    AMateria* sk_floor[100];


public:
    Character(std::string name);
    Character(Character const &other);
    Character &operator=(Character const &other);
    ~Character();

    virtual std::string const &getName() const;
    virtual void equip(AMateria *m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter &target);
};

#endif