#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): target("RobotomyRequestForm"){

}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
  : AForm("RobotomyRequestForm", 72, 45), target(target){
  }


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
  : AForm("RobotomyRequestForm", 72, 45), target(other.target){  
  }


RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other){
  if(this != &other){
    this->target = other.target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::exec_action() const {

  srand(time(0));
  
  int val = rand() % 100;
  
  if(val < 50)
    std::cout << this->target << "'s Robotomy is a success :D\n";
  else
    std::cout << this->target << "'s Robotomy failed D:\n";
}
