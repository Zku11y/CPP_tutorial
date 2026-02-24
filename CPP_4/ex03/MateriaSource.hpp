#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{

private:
    AMateria* inv[4];

public:
    MateriaSource();
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);
    ~MateriaSource();

    virtual void learnMateria(AMateria* tmp);
    virtual AMateria* createMateria(std::string const & type);

};

#endif