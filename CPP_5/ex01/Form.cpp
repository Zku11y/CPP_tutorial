#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

Form::Form(std::string name, int sign_grade, int exec_grade):
  name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade){
  if(this->sign_grade < 1 || this->exec_grade < 1)
      throw Form::GradeTooHighException();
  else if(this->sign_grade > 150 || this->exec_grade > 150)
      throw Form::GradeTooLowException();
}

Form::Form(Form const &other):
  name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade){
}

Form &Form::operator=(Form const &other){
  if(this != &other){
    this->is_signed = other.is_signed;
  }
  return *this;
}

Form::~Form(){
  
}

Form::GradeTooHighException::GradeTooHighException(){
  msg = "Form Grade is too High! (Highest is 1)";
}

Form::GradeTooHighException::GradeTooHighException(std::string msg): msg(msg){
}

const char* Form::GradeTooHighException::what() const throw(){
  return msg.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw(){
  
}


Form::GradeTooLowException::~GradeTooLowException() throw(){
  
}


Form::GradeTooLowException::GradeTooLowException(){
  msg = "Form Grade is too Low! (Lowest is 150)";
}

Form::GradeTooLowException::GradeTooLowException(std::string msg): msg(msg){
}

const char* Form::GradeTooLowException::what() const throw(){
  return msg.c_str();
}

std::string Form::getName() const{
  return name;
}

int Form::getSignGrade() const{
  return sign_grade;
}

int Form::getExecGrade() const{
  return exec_grade;
}

bool Form::IsSigned() const{
  return is_signed;
}

void Form::beSigned(Bureaucrat const &bro){
  int grade = bro.getGrade();
  int sign_grade = this->getSignGrade();
  if(grade > sign_grade)
    throw Form::GradeTooLowException(
      bro.getName()+ "'s Grade is too Low!");
  if(is_signed == false)
    is_signed = true;
}

std::ostream &operator<<(std::ostream& os, Form const &form){
  os << form.getName() << ", sign grade: " << form.getSignGrade() <<
  ", exec grade: " << form.getExecGrade() << ", is signed: " << form.IsSigned();
  return os;
}
