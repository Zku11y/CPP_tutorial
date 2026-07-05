#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm{
private:
  const std::string name;
  bool is_signed;
  const int sign_grade;
  const int exec_grade;
  
    
public:
  AForm(std::string name, int sign_grade, int exec_grade);
  AForm(AForm const &other);
  AForm &operator=(AForm const &other);
  virtual ~AForm();

  std::string getName() const;
  int getSignGrade() const;
  int getExecGrade() const;
  bool IsSigned() const;
  void beSigned(Bureaucrat const &bro);

  void execute(Bureaucrat const &executor);

  virtual void exec_action() const = 0;

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


  class FormNotSignedException : public std::exception{
  public:
    const char* what() const throw();
  };

};


std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif
