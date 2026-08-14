#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>

PresidentialPardonForm::PresidentialPardonForm(std::string target)
  : AForm("PresidentialPardonForm", 25, 5), target(target){
  }


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
  : AForm("PresidentialPardonForm", 25, 5), target(other.target){  
  }


PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other){
  if(this != &other){
    this->target = other.target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::exec_action() const {

  std::cout << this->target << " has been officially pardoned by his majesty Zaphod Beeblebrox!\n";

}
