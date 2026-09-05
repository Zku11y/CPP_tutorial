#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <ios>
#include <limits>
#include <cstdlib>
#include <iterator>
#include <string>
#include <iomanip>

ScalarConverter::ScalarConverter(){
  
}

ScalarConverter::ScalarConverter(ScalarConverter const &other){
  (void)other;
}

ScalarConverter *ScalarConverter::operator=(ScalarConverter const &other){
    if(this == &other)
      return this;
    return this;
}

ScalarConverter::~ScalarConverter(){
    
}

void convert_output(std::string sk_char, std::string sk_int, std::string sk_float, std::string sk_double){

  std::cout << "char : " << sk_char << std::endl;
  std::cout << "int : " << sk_int << std::endl;
  std::cout << "float : " << sk_float << ".0f" << std::endl;
  std::cout << "double : " << sk_double << ".0" << std::endl;
  
}

bool check_char(std::string const &literal){
  if(literal.size() == 1 && !std::isdigit(literal[0]))
    return true;
  return false;
}

bool check_int(std::string const &literal){

  if(isdigit(literal[0]) || literal[0] == '-' || literal[0] == '+'){
    int i = 1;
    while(isdigit(literal[i]))
      i++;
    if(literal[i] == '\0')
      return true;
  }
  return false;
}

bool check_float(std::string const &literal){

  if(isdigit(literal[0]) || literal[0] == '-' || literal[0] == '+'){
    int i = 1;
   while(isdigit(literal[i]))
      i++;
   if(literal[i++] != '.')
      return false;
   while(isdigit(literal[i]))
      i++;
   if(literal[i] == 'f' && literal[i + 1] == '\0')
        return true;
 }
  return false;
}

bool check_double(std::string const &literal){

  if(isdigit(literal[0]) || literal[0] == '-' || literal[0] == '+'){
    int i = 1;
   while(isdigit(literal[i]))
      i++;
   if(literal[i++] != '.')
      return false;
   while(isdigit(literal[i]))
      i++;
   if(literal[i] == '\0')
        return true;
 }
  return false;
}

bool check_infs(std::string const &literal){
  if(!literal.compare("inf") || !literal.compare("+inf") || !literal.compare("-inf")
      || !literal.compare("inff") || !literal.compare("+inff") || !literal.compare("-inff")){
    std::cout << "char : Impossible\n";
    std::cout << "int : Impossible\n";
    if(!literal.compare("inf") || !literal.compare("+inf")
       || !literal.compare("inff") || !literal.compare("+inff")){
      std::cout << "float : +inff\n";
      std::cout << "double : +inf\n";
      return true;
    }
    std::cout << "float : -inff\n";
    std::cout << "double : -inf\n";
    return true;
  }
  return false;
}

void print_imp(){
  
  std::cout << "char : impossible\n";
  std::cout << "int : impossible\n";
  std::cout << "float : impossible\n";
  std::cout << "double : impossible\n";

}

void ScalarConverter::convert(const std::string &literal){

    if(literal.empty()){ return (print_imp()); }

    if(check_infs(literal)) return;
    
    std::cout << std::fixed << std::setprecision(1);

   if(check_char(literal)){

   
    if(literal[0] < 32 || literal[0] > 126)
      std::cout << "char : Undisplayable\n";
    else
      std::cout << "char : " << literal << std::endl;
    std::cout << "int : " << static_cast<int>(literal[0]) << std::endl;
    std::cout << "float : " << static_cast<float>(literal[0]) << "f" << std::endl;
    std::cout << "double : " << static_cast<double>(literal[0]) << std::endl;
    return;
  }

  if(check_int(literal)){

   
    long double a = std::atof(literal.c_str());

    if(a < CHAR_MIN || a > CHAR_MAX)
      std::cout << "char : Impossible\n";
    else if(a < 32 || a > 126)
      std::cout << "char : Non Displayable\n";
    else
      std::cout << "char : " << static_cast<char>(a) << std::endl;
    if(a > INT_MAX || a < INT_MIN)
      std::cout << "int : Impossible\n";
    else
      std::cout << "int : " << static_cast<int>(a) << std::endl;
    if(a > FLT_MAX || a < -FLT_MAX)
      std::cout << "float : impossible\n";
    else
      std::cout << "float : " << static_cast<float>(a) << "f" << std::endl;
    if(a > DBL_MAX || a < -DBL_MAX)
      std::cout << "double : impossible\n";
    else
      std::cout << "double : " << static_cast<double>(a) << std::endl;
    return;
  }

  if(check_float(literal)){

  long double a = std::atof(literal.c_str());
 
    if(a < CHAR_MIN || a > CHAR_MAX)
      std::cout << "char : Impossible\n";
    else if(a < 32 || a > 126)
      std::cout << "char : Non Displayable\n";
    else
      std::cout << "char : " << static_cast<char>(a) << std::endl;
    if(a > INT_MAX || a < INT_MIN)
      std::cout << "int : Impossible\n";
    else
      std::cout << "int : " << static_cast<int>(a) << std::endl;
    if(a > FLT_MAX || a < -FLT_MAX)
      std::cout << "float : impossible\n";
    else
      std::cout << "float : " << static_cast<float>(a) << "f" << std::endl;
    if(a > DBL_MAX || a < -DBL_MAX)
      std::cout << "double : impossible\n";
    else
      std::cout << "double : " << static_cast<double>(a) << std::endl;
    return;
 }


  if(check_double(literal)){

  long double a = std::atof(literal.c_str());
  
    if(a < CHAR_MIN || a > CHAR_MAX)
      std::cout << "char : Impossible\n";
    else if(a < 32 || a > 126)
      std::cout << "char : Non Displayable\n";
    else
      std::cout << "char : " << static_cast<char>(a) << std::endl;
    if(a > INT_MAX || a < INT_MIN)
      std::cout << "int : Impossible\n";
    else
      std::cout << "int : " << static_cast<int>(a) << std::endl;
    if(a > FLT_MAX || a < -FLT_MAX)
      std::cout << "float : impossible\n";
    else
      std::cout << "float : " << static_cast<float>(a) << "f" << std::endl;
    if(a > DBL_MAX || a < -DBL_MAX)
      std::cout << "double : impossible\n";
    else
      std::cout << "double : " << static_cast<double>(a) << std::endl;
    return;
 }
 
  print_imp();
   
}
