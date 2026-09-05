#include "ScalarConverter.hpp"
#include <cstdlib>


int main(int ac, char **av){
  if(ac < 2)
    return (std::cerr << "Error: bro where da numbr vroooo where is it hrooo\n", 1);
  std::string ya = av[1];

  ScalarConverter::convert(ya);

 return 0;
}
