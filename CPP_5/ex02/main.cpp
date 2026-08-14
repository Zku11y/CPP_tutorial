#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <exception>

int main(){
  try{ 
    Bureaucrat Mr_dude("Mr_dude", 50);
    std::cout << Mr_dude << std::endl;

    ShrubberyCreationForm GardenTS("Land Aquisition Contract");
    RobotomyRequestForm Automation("Robot sale contract");
    PresidentialPardonForm Pardon("Presidential pardon contract");


    Bureaucrat Ms_girl("Ms_girl", 120);
    std::cout << Ms_girl << std::endl;

    Mr_dude.signForm(GardenTS);
    
    Mr_dude.signForm(Automation);

    Mr_dude.signForm(Pardon);

    Mr_dude.executeForm(GardenTS);

    Mr_dude.executeForm(Automation);

    Mr_dude.executeForm(Pardon);

  }
  catch(std::exception &e){
  std::cout << e.what() << std::endl;
  }
  return 0;
}
