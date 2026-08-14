#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
  : AForm("ShrubberyCreationForm", 145, 137), target(target){
  }


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
  : AForm("ShrubberyCreationForm", 145, 137), target(other.target){  
  }


ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
  if(this != &other){
    this->target = other.target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::exec_action() const {
  std::string file_name = this->target + "_shrubbery";

  std::ofstream outfile(file_name.c_str());

  if(!outfile.is_open())
    throw std::runtime_error("why yo file tweekin boi");

  outfile << DA_TREE;

  outfile.close();
}
