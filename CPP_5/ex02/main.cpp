#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(){
  try{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "TEST 1: Execute unsigned form" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Bureaucrat Mr_ceo("Mr_ceo", 1);
    std::cout << "Bureaucrat: " << Mr_ceo << std::endl;
    ShrubberyCreationForm form("Shrubbery_1");
    std::cout << form << std::endl;
    Mr_ceo.executeForm(form);

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 2: Grade too low to execute form" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Bureaucrat Mr_Accountant("Mr_Accountant", 140);
    std::cout << "Bureaucrat: " << Mr_Accountant << std::endl;
    ShrubberyCreationForm form("Shrubbery_2");
    std::cout << form << std::endl;
    Mr_Accountant.signForm(form);
    Mr_Accountant.executeForm(form);

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 3: ShrubberyCreationForm executes successfully!" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Bureaucrat Mr_Gardener("Mr_Gardener", 130);
    std::cout << "Bureaucrat: " << Mr_Gardener << std::endl;
    ShrubberyCreationForm form("Gradening License");
    std::cout << form << std::endl;
    Mr_Gardener.signForm(form);
    Mr_Gardener.executeForm(form);

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 4: RobotomyRequestForm executes successfully!" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Bureaucrat Mr_Scientist("Mr_Scientist", 40);
    std::cout << "Bureaucrat: " << Mr_Scientist << std::endl;
    RobotomyRequestForm form("Clearance");
    std::cout << form << std::endl;
    Mr_Scientist.signForm(form);
    Mr_Scientist.executeForm(form);

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 5: PresidentialPardonForm executes successfully!" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Bureaucrat Mr_President("Mr_President", 4);
    std::cout << "Bureaucrat: " << Mr_President << std::endl;
    PresidentialPardonForm form("Offical Pardon");
    std::cout << form << std::endl;
    Mr_President.signForm(form);
    Mr_President.executeForm(form);

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  return 0;
}