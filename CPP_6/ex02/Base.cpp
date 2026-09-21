#include "Base.hpp"

Base::~Base(){
  
}

long long get_time_ms(){
  
  struct timeval tv;

  gettimeofday(&tv, NULL);

  return tv.tv_usec;
}

Base *generate(void){

    static bool seeded = false;

    if(!seeded){
      std::srand(get_time_ms());
      seeded = true;
    }

  int result = std::rand() % 3;

  if(result == 0)
    return (new A);
  else if(result == 1)
    return (new B);
  else
    return (new C);    
}

void identify(Base *p){
  if(A* a = dynamic_cast<A *>(p)){
      a->_speak();
      return ;
    }

  if(B* b = dynamic_cast<B *>(p)){
    b->_speak();
    return ;
  }

  if(C* c = dynamic_cast<C *>(p)){
    c->_speak();
    return ;
  }

  std::cout << "Unknown Class Type\n";
}

void identify(Base &p){

  try{
    A a = dynamic_cast<A&>(p);
    a._speak();
    return;
  } catch(std::exception &e){}

  try{
    B b = dynamic_cast<B&>(p);
    b._speak();
    return;
  } catch(std::exception &e){}

  try{
    C c = dynamic_cast<C&>(p);
    c._speak();
    return;
  } catch(std::exception &e){} 

    std::cout << "Unknown Class Type\n";
}

void A::_speak(){
  std::cout << "I am the one who is A legend\n";
}

void B::_speak(){
  std::cout << "I am going to B a legend\n";
}

void C::_speak(){
  std::cout << "U will C me as a legend\n";
}
