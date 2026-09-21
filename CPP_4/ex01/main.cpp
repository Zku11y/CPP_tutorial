#include <iostream>
#include <string>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    Animal* animals[10];

    for (int k = 0; k < 5; k++)
        animals[k] = new Dog();
    for (int k = 5; k < 10; k++)
        animals[k] = new Cat();

    Dog dogA;
    Dog dogB(dogA);
    Dog dogC;
    dogC = dogA;

    Cat catA;
    Cat catB(catA);
    Cat catC;
    catC = catA;

    for (int k = 0; k < 10; k++)
        delete animals[k];
    delete j;
    delete i;

    return 0;
}