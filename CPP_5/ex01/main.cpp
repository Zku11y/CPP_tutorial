#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main(){
  try{ 
    Bureaucrat Mr_dude("Mr_dude", 5);
    std::cout << Mr_dude << std::endl;

    Form NDA("Rockstar Games Contract", 160, 50);

    Bureaucrat Ms_girl("Ms_girl", 120);
    std::cout << Ms_girl << std::endl;

    Mr_dude.signForm(NDA);
    
    Ms_girl.signForm(NDA);
    
  }
  catch(std::exception &e){
  std::cout << e.what() << std::endl;
  }
  return 0;
}
