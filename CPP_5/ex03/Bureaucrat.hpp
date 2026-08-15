#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class AForm;

class Bureaucrat{
public:
  Bureaucrat(std::string name, int grade);
  Bureaucrat(Bureaucrat const &other);
  Bureaucrat &operator=(Bureaucrat const &other);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;
  void signForm(AForm &form);
  void executeForm(AForm const & form) const;

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
  
private:
  const std::string name;
  int grade;
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &bureaucrat);


#endif
