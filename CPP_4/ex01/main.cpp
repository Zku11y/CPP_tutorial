#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "\n====================================================\n";
    std::cout << "  TEST 1: THE SUBJECT ARRAY (POLYMORPHISM & LEAKS)\n";
    std::cout << "====================================================\n";
    
    const int arraySize = 4; // Kept small to make terminal output readable
    Animal* animals[arraySize];

    std::cout << "--- Allocating Animals ---\n";
    for(int i = 0; i < arraySize / 2; i++)
        animals[i] = new Dog();
    for(int i = arraySize / 2; i < arraySize; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Testing Sounds ---\n";
    for(int i = 0; i < arraySize; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting Animals ---\n";
    for(int i = 0; i < arraySize; i++)
        delete animals[i]; 
    // Valgrind will scream here if your Animal destructor isn't virtual!

    std::cout << "\n====================================================\n";
    std::cout << "  TEST 2: DEEP COPY (COPY CONSTRUCTOR)\n";
    std::cout << "====================================================\n";
    
    Dog basicDog;
    {
        // We create a scope block `{ }` so cloneDog is destroyed early
        std::cout << "\n--- Creating Clone ---" << std::endl;
        Dog cloneDog(basicDog); 
        
        std::cout << "\n--- cloneDog is about to be destroyed ---" << std::endl;
    } // cloneDog dies here and deletes its Brain.
    
    std::cout << "\n--- basicDog is still alive ---" << std::endl;
    // If the copy was shallow, basicDog's Brain was just deleted above.
    // When basicDog dies at the end of main(), Valgrind will flag a Double Free!

    std::cout << "\n====================================================\n";
    std::cout << "  TEST 3: DEEP COPY (ASSIGNMENT OPERATOR)\n";
    std::cout << "====================================================\n";
    
    Cat cat1;
    Cat cat2;
    
    std::cout << "\n--- Assigning cat1 to cat2 ---" << std::endl;
    cat2 = cat1; 
    // Valgrind will check if you deleted cat2's old brain before giving it a copy of cat1's brain.

    std::cout << "\n====================================================\n";
    std::cout << "  END OF TESTS (Check Valgrind!)\n";
    std::cout << "====================================================\n";

    return 0;
}