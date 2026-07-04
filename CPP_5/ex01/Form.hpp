#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class Form{
private:
  const std::string name;
  bool is_signed;
  const int sign_grade;
  const int exec_grade;
  
    
public:
  Form(std::string name, int sign_grade, int exec_grade);
  Form(Form const &other);
  Form &operator=(Form const &other);
  ~Form();

  std::string getName() const;
  int getSignGrade() const;
  int getExecGrade() const;
  bool IsSigned() const;
  void beSigned(Bureaucrat const &bro);

  class GradeTooHighException : public std::exception{
  private:
    std::string msg;
    
  public:
    GradeTooHighException(void);
    GradeTooHighException(std::string msg);
    virtual ~GradeTooHighException() throw();
    const char* what() const throw();
  };
  
  class GradeTooLowException : public std::exception{
  private:
    std::string msg;

  public:
    GradeTooLowException(void);
    GradeTooLowException(std::string msg);
    virtual ~GradeTooLowException() throw();
    const char* what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
