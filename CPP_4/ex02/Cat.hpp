#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal{
private:
    Brain* brain;

public:
    Cat();
    Cat(std::string type);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    virtual void makeSound() const;
};

#endif