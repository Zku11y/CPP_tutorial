#include "ScalarConverter.hpp"
#include <cstdlib>


int main(int ac, char **av){
  if(ac < 2)
    return 1;
  std::string ya = av[1];

  ScalarConverter::convert(ya);

 return 0;
}
