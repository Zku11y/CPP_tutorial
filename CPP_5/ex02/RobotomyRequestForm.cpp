#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <stdexcept>

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
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
  std::string file_name = this->target + "_shrubbery";

  std::ofstream outfile(file_name.c_str());

  if(!outfile.is_open())
    throw std::runtime_error("why yo file tweekin boi");

  outfile << DA_TREE;

  outfile.close();
}
