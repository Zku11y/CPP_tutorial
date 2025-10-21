#include <iostream>
#include "Fixed.hpp"

int main(){
  Fixed a(33);
  const Fixed c_a(33);
  Fixed b(67);
  const Fixed c_b(67);

  if(a < b)
    std::cout << "a smaller than b" << std::endl;
  if(a > b) 
    std::cout << "a bigger than b" << std::endl;
  if(a == b)
    std::cout << "a equals b" << std::endl;
  if(a != b)
    std::cout << "a is different from b" << std::endl;
  std::cout << "a + b = " << a + b << std::endl;
  std::cout << "a - b = " << a - b << std::endl;
  std::cout << "a * b = " << a * b << std::endl;
  std::cout << "a / b = " << a / b << std::endl;
  std::cout << "before a++ = " << a++ << ", after = " << a << std::endl;
  std::cout << "before ++a = " << ++a << ", after = " << a << std::endl;
  std::cout << "before a-- = " << a-- << ", after = " << a << std::endl;
  std::cout << "before --a = " << --a << ", after = " << a << std::endl;
  std::cout << "max(a, b) : " << Fixed::max(a, b) << std::endl;
  std::cout << "const max(a, b) : " << Fixed::max(a, b) << std::endl;
  std::cout << "min(a, b) : " << Fixed::min(a, b) << std::endl;
  std::cout << "const min(a, b) : " << Fixed::min(a, b) << std::endl;
  return 0;

  return 0;
}
