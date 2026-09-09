#include <stdexcept>
#include <iostream>

template <typename T>

class Array{
private:
  T* arr;
  unsigned int _size;

public:

  Array();
  ~Array();
  Array(unsigned int n);
  Array(Array const &other);
  Array &operator=(Array const &other);
  const T& operator[](unsigned int a) const;
  T& operator[](unsigned int a);
  unsigned int size(void) const;  

};


 template <typename T>
 Array<T>::Array(): arr(NULL), _size(0){
}

 template <typename T>
 Array<T>::Array(unsigned int n): arr(new T[n]()), _size(n){
 }


 template <typename T>
 Array<T>::Array(Array const &other){

  if(other.size() == 0){
    arr = NULL;
    _size = 0;
    return;
  }
  
  unsigned int max = other.size();

  arr = new T[max]();
  _size = max;
  for(unsigned int i = 0; i < _size; i++){
    arr[i] = other.arr[i];
  }

 }



 template <typename T>
 Array<T> &Array<T>::operator=(Array const &other){

  if(this == &other)
    return *this;
  
  delete[] arr;
   
  if(other.size() == 0){
    arr = NULL;
    _size = 0;
    return *this;
  }
  
  unsigned int max = other.size();

  arr = new T[max]();
  _size = max;
  for(unsigned int i = 0; i < _size; i++){
    arr[i] = other.arr[i];
  }

  return *this;
 }

 template <typename T>
 Array<T>::~Array(){
   delete[] arr;
 }

template <typename T>
const T &Array<T>::operator[](unsigned int a) const{
  if(a >= _size){
    throw std::out_of_range("Invalid size");
  }

  return arr[a];
}

template <typename T>
T &Array<T>::operator[](unsigned int a){
  if(a >= _size){
    throw std::out_of_range("Invalid size");
  }

  return arr[a];
}

template <typename T>
unsigned int Array<T>::size() const {
  return _size;
}
