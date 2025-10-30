#include "Fixed.hpp"
#include "BSP.hpp"

int main(){
  Point a(1, 1);
  Point b(4, 4);
  Point c(5, 0);
  Point p(3, 1);

  if(bsp(a, b, c, p) == true)
    std::cout << "p is inside the triangle\n";
  else {
    std::cout << "p is outside the triangle\n";
  }
  return 0;
}
