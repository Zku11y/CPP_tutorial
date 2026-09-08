#include "iter.hpp"

template <typename T> void iter_prnt(T const &n){
  std::cout << "value is : " << n << "\n";
}

template <typename T> void iter_iter(T &n){
  n++;
}

int main(){
  const int const_arr[5] = {1, 2, 3, 4, 5};

  std::cout << "priting const array...\n";

  ::iter(const_arr, 5, iter_prnt<int>);  

  int arr[5] = {6, 7, 8, 9, 10};

  std::cout << "priting normal array...\n";
  
  ::iter(arr, 5, iter_prnt<int>);

  std::cout << "increasing values...\n";

  ::iter(arr, 5, iter_iter<int>);

  std::cout << "priting result array...\n";
 
  ::iter(arr, 5, iter_prnt<int>);
  return 0;
}
