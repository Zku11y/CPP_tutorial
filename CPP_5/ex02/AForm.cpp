#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <ostream>
#include <string>


void AForm::execute(Bureaucrat const &executor) const{
  if(!this->IsSigned()){
   throw AForm::GradeTooLowException("Form is not signed yet!");
 }

  if(executor.getGrade() > this->exec_grade){
    std::string ss = executor.getName() + "'s Grade not High enough to execute Form!\n";
    throw AForm::GradeTooLowException(ss.c_str());
  }

  exec_action();
}


AForm::AForm(std::string name, int sign_grade, int exec_grade):
  name(name), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade){
  if(this->sign_grade < 1 || this->exec_grade < 1)
      throw AForm::GradeTooHighException();
  else if(this->sign_grade > 150 || this->exec_grade > 150)
      throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other):
  name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), exec_grade(other.exec_grade){
}

AForm &AForm::operator=(AForm const &other){
  if(this != &other){
    this->is_signed = other.is_signed;
  }
  return *this;
}

AForm::~AForm(){
  
}

AForm::GradeTooHighException::GradeTooHighException(){
  msg = "AForm Grade is too High! (Highest is 1)";
}

AForm::GradeTooHighException::GradeTooHighException(std::string msg): msg(msg){
}

const char* AForm::GradeTooHighException::what() const throw(){
  return msg.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw(){
  
}


AForm::GradeTooLowException::~GradeTooLowException() throw(){
  
}


AForm::GradeTooLowException::GradeTooLowException(){
  msg = "AForm Grade is too Low! (Lowest is 150)";
}

AForm::GradeTooLowException::GradeTooLowException(std::string msg): msg(msg){
}

const char* AForm::GradeTooLowException::what() const throw(){
  return msg.c_str();
}

const char* AForm::FormNotSignedException::what() const throw(){
  return "Can't Execute unsigned Form! please sign it before execution.";
}

std::string AForm::getName() const{
  return name;
}

int AForm::getSignGrade() const{
  return sign_grade;
}

int AForm::getExecGrade() const{
  return exec_grade;
}

bool AForm::IsSigned() const{
  return is_signed;
}

void AForm::beSigned(Bureaucrat const &bro){
  int grade = bro.getGrade();
  int sign_grade = this->getSignGrade();
  if(grade > sign_grade)
    throw AForm::GradeTooLowException(
      bro.getName()+ "'s Grade is too Low!");
  if(is_signed == false)
    is_signed = true;
}

std::ostream &operator<<(std::ostream& os, AForm const &form){
  os << form.getName() << ", sign grade: " << form.getSignGrade() <<
  ", exec grade: " << form.getExecGrade() << ", is signed: " << form.IsSigned();
  return os;
}
