#include "Bureaucrat.hpp"
#include "Form.hpp"


void Bureaucrat::signForm(Form &form){
  try{
    form.beSigned(*this);
    std::cout << this->name << " signed " << form.getName() << std::endl;
  }
  catch(std::exception &e){
    std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
  }
}


Bureaucrat::GradeTooHighException::GradeTooHighException(){
  msg = "Bureaucrat Grade is too High! (Highest is 1)";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string msg): msg(msg){
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
  return msg.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){
  
}


Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){
  
}


Bureaucrat::GradeTooLowException::GradeTooLowException(){
  msg = "Bureaucrat Grade is too Low! (Lowest is 150)";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg): msg(msg){
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
  return msg.c_str();
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name){
  if(grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if(grade > 150)
    throw Bureaucrat::GradeTooLowException();
  this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other): name(other.name), grade(other.grade){
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
  if(this != &other){
    this->grade = other.getGrade();
  }
  return *this;
}

Bureaucrat::~Bureaucrat(){
}

std::string Bureaucrat::getName() const{
  return name;
}

int Bureaucrat::getGrade() const{
  return grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat){
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
