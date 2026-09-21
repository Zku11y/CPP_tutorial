#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "TEST 1: Constructor Grade Too High" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    try {
        Bureaucrat Mr_ceo("Mr_ceo", 0);
    } catch(std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "TEST 2: Constructor Grade Too Low" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    try {
        Bureaucrat Mr_accountant("Mr_accountant", 170);
    } catch(std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "TEST 3: Incrementing Grade Too High" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    try { 
        Bureaucrat Mr_dude("Mr_dude", 2);
        std::cout << "Initial: " << Mr_dude << std::endl;
        Mr_dude.incr_Grade();
        std::cout << "After 1st increment: " << Mr_dude << std::endl;
        Mr_dude.incr_Grade();
        std::cout << "After 2nd increment: " << Mr_dude << std::endl;
    } catch(std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "TEST 4: Decrementing Grade Too Low" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    try {
        Bureaucrat Ms_girl("Ms_girl", 149);
        std::cout << "Initial: " << Ms_girl << std::endl;
        Ms_girl.decr_Grade();
        std::cout << "After 1st decrement: " << Ms_girl << std::endl;
        Ms_girl.decr_Grade();
        std::cout << "After 2nd decrement: " << Ms_girl << std::endl;
    } catch(std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
