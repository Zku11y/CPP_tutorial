#include "Base.hpp"

int main(){

  Base *base_1;
  Base *base_2;
  Base *base_3;

// < --- Generating the Derived Classes randomly --- >
  
  base_1 = generate();
  base_2 = generate();
  base_3 = generate();

// < --- --- >

// < --- Indentifying using pointer --- >

  identify(base_1);
  identify(base_2);
  identify(base_3);

// < --- --- > 

// < --- Indentifying using reference --- >

  identify(*base_1);
  identify(*base_2);
  identify(*base_3);

// < --- --- > 

// < --- Cleaning up memory leaks --- >

  delete(base_1);
  delete(base_2);
  delete(base_3);

// < --- --- >
  return 0;
}
