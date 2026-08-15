#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <exception>

int main(){
  try{ 
    Bureaucrat Mr_dude("Mr_dude", 50);
    std::cout << Mr_dude << std::endl;

    Intern randomintern;

    AForm *forms[5];
    forms[0] = randomintern.makeForm("shruberry creation", "GardenTS");
    forms[1] = randomintern.makeForm("robotomy request", "Nigger");
    forms[2] = randomintern.makeForm("presidential pardon", "sori bro");
    forms[3] = randomintern.makeForm("robotomy request", "3tiw Lyassine mnyoun");
    forms[4] = randomintern.makeForm("presidential pardon", "white people");
    

    Bureaucrat Ms_girl("Ms_girl", 120);
    std::cout << Ms_girl << std::endl;

    Mr_dude.signForm(*forms[0]);
    
    Mr_dude.signForm(*forms[1]);

    Mr_dude.signForm(*forms[2]);

    Mr_dude.executeForm(*forms[0]);

    Mr_dude.executeForm(*forms[1]);

    Mr_dude.executeForm(*forms[2]);

  }
  catch(std::exception &e){
  std::cout << e.what() << std::endl;
  }
  return 0;
}
