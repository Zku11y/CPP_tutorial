#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data{
  std::string name;
  int         age;
  float       height;
};


class Serializer{

public:
  static uintptr_t serialize(Data* ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer();
  Serializer(Serializer const &other);
  Serializer *operator=(Serializer const &other);
  ~Serializer();
  
};

#endif
