#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(){
  try{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "TEST 1: Intern creates ShrubberyCreationForm" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("shrubbery creation", "Gardening License");
    Bureaucrat Mr_Gardener("Mr_Gardener", 130);
    std::cout << "Bureaucrat: " << Mr_Gardener << std::endl;

    if (form) {
      std::cout << *form << std::endl;
      Mr_Gardener.signForm(*form);
      Mr_Gardener.executeForm(*form);
      delete form;
    }

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 2: Intern creates RobotomyRequestForm" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat Mr_Scientist("Mr_Scientist", 40);
    std::cout << "Bureaucrat: " << Mr_Scientist << std::endl;

    if (form) {
      std::cout << *form << std::endl;
      Mr_Scientist.signForm(*form);
      Mr_Scientist.executeForm(*form);
      delete form;
    }

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 3: Intern creates PresidentialPardonForm" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("presidential pardon", "Official Pardon");
    Bureaucrat Mr_President("Mr_President", 4);
    std::cout << "Bureaucrat: " << Mr_President << std::endl;

    if (form) {
      std::cout << *form << std::endl;
      Mr_President.signForm(*form);
      Mr_President.executeForm(*form);
      delete form;
    }

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 4: Intern tries to create an unknown form" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Intern someRandomIntern;
    AForm* form = someRandomIntern.makeForm("some invalid form", "Nobody");

    if (form) {
      std::cout << *form << std::endl;
      delete form;
    }

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  return 0;
}