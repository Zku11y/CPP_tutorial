#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog("trigger");
    const Animal* i = new Cat("bigger");
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();

    std::cout << wrong_animal->getType() << " " << std::endl;
    std::cout << wrong_cat->getType() << " " << std::endl;
    wrong_animal->makeSound();
    wrong_cat->makeSound();
    
    delete meta;
    delete j;
    delete i;
    delete wrong_animal;
    delete wrong_cat;
    return 0;
}