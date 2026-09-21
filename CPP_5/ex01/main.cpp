#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(){
  try{

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "TEST 1: Bureaucrat's Grade too low for form" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Bureaucrat Mr_Accountant("Mr_Accountant", 3);
    std::cout << "Bureaucrat: " << Mr_Accountant << std::endl;
    Form form("Rockstar Games Contract", 1, 50);
    Mr_Accountant.signForm(form);
    std::cout << form << std::endl;

  }catch(std::exception &e){
    std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 2: Form's grade is too low" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Form form("Ubisoft Contract", 159, 170);
    std::cout << form << std::endl;

  }
  catch(std::exception &e){
  std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 3: Form's grade is too high" << std::endl;
    std::cout << "---------------------------------------------\n\n";

    Form form("Ubisoft Contract", 0, -30);
    std::cout << form << std::endl;

  }
  catch(std::exception &e){
  std::cout << e.what() << std::endl;
  }

  try{
    std::cout << "\n---------------------------------------------" << std::endl;
    std::cout << "TEST 4: Form is signed successfully!" << std::endl;
    std::cout << "---------------------------------------------\n\n";
    Bureaucrat Mr_ceo("Mr_ceo", 1);
    std::cout << "Bureaucrat: " << Mr_ceo << std::endl;
    Form form("Ubisoft Contract", 6, 20);
    std::cout << form << std::endl;
    Mr_ceo.signForm(form);
    std::cout << form << std::endl;
  }
  catch(std::exception &e){
  std::cout << e.what() << std::endl;
  }

  return 0;
}
