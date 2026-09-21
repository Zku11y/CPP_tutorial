#include "Base.hpp"

int main(){

  Base *base_1;
  Base *base_2;
  Base *base_3;

std::cout << "1. Generating the Derived Classes randomly\n";
  
  base_1 = generate();
  base_2 = generate();
  base_3 = generate();

std::cout << "\n2. Identifying using pointer\n";

  identify(base_1);
  identify(base_2);
  identify(base_3);

std::cout << "\n3. Indentifying using reference\n";

  identify(*base_1);
  identify(*base_2);
  identify(*base_3);

std::cout << "\n4. Cleaning up memory leaks\n";

  delete(base_1);
  delete(base_2);
  delete(base_3);

  return 0;
}
