#ifndef ITER_HPP
#define ITER_HPP


#include <cstddef>
#include <iostream>

template <typename A, typename B>

void iter(A *arr , std::size_t const b, B fn){
  for(std::size_t i = 0; i < b; i++){
    fn(arr[i]);
  }
}

#endif
