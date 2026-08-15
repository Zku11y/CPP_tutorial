#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstddef>


Intern::Intern(){
  
}

Intern::Intern(Intern const &other){
  (void)other;
}

Intern &Intern::operator=(Intern const &other){
  if(this == &other)
    return *this;
  return *this;  
}

Intern::~Intern(){
  
}


typedef AForm * (*formcreator)(std::string target);


AForm *Intern::makeForm(const std::string &name,const std::string &target){

  std::string names[3];
  names[0] = "shruberry creation";
  names[1] = "robotomy request";
  names[2] = "presidential pardon";

  int i = 0;

  while(i < 3 && names[i] != name){
    i++;
  } 

switch (i) {
  case 0:
    std::cout << "Intern creates shruberry form\n";
    return new ShrubberyCreationForm(target);
  case 1:
    std::cout << "Intern creates robotomy form\n";
    return new RobotomyRequestForm(target);
  case 2:
    std::cout << "Intern creates presidential form\n";
    return new PresidentialPardonForm(target);
  default:
    std::cout << "Intern Couldn't create the form :(\n";
    return NULL;
}

 
}
