#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <sys/time.h>

class Base{
public:
  virtual ~Base();


};

class A : public Base {
public:
  void _speak();
};

class B : public Base {
public:
  void _speak();
};

class C : public Base {
public:
  void _speak();
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
