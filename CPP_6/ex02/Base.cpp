#include "Base.hpp"

Base::~Base(){
  
}

long long get_time_ms(){
  
  struct timeval tv;

  gettimeofday(&tv, NULL);

  return tv.tv_usec;
}

Base *generate(void){

  long long t = get_time_ms();

    t = (t + 6568) * 32;

  int result = t % 100;

  if(result < 30)
    return (new A);
  else if(result < 60)
    return (new B);
  else
    return (new C);    
}

void identify(Base *p){
  if(A* a = dynamic_cast<A *>(p))
    {std::cout << "Class Type : A\n"; return (void)a;}
  if(B* b = dynamic_cast<B *>(p))
    {std::cout << "Class Type : B\n"; return (void)b;}
  if(C* c = dynamic_cast<C *>(p))
    {std::cout << "Class Type : C\n"; return (void)c;}
}

void identify(Base &p){

  try{
    A a = dynamic_cast<A&>(p);
    std::cout << "Class Type : A\n";
    (void)a;
    return;
  } catch(...){}

  try{
    B b = dynamic_cast<B&>(p);
    std::cout << "Class Type : B\n";
    (void)b;
    return;
  } catch(...){}

  try{
    C c = dynamic_cast<C&>(p);
    std::cout << "Class Type : C\n";
    (void)c;
    return;
  } catch(...){} 

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
