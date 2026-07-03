#include "Bureaucrat.hpp"
#include <exception>
#include <iterator>


int main(){
  try{ 
    Bureaucrat Mr_dude("Mr_dude", 5);
    std::cout << Mr_dude << std::endl;
    Bureaucrat Ms_girl("Ms_girl", 170);
    std::cout << Ms_girl << std::endl;
  }
  catch(std::exception &e){
  std::cout << e.what() << std::endl;
  }
  return 0;
}
