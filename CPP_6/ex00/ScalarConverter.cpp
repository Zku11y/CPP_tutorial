#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iterator>
#include <string>

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
  if(literal.size() == 1 && isalpha(literal[0]))
    return true;
  return false;
}

bool check_int(std::string const &literal){

  if(isdigit(literal[0]) || literal[0] == '-'){
    int i = 1;
    while(isdigit(literal[i]))
      i++;
    if(literal[i] == '\0')
      return true;
  }
  return false;
}

void ScalarConverter::convert(const std::string &literal){
  if(literal.empty()){
  std::cout << "char : impossible\n";
  std::cout << "int : impossible\n";
  std::cout << "float : impossible\n";
  std::cout << "double : impossible\n";
 }

  if(check_char(literal)){
    std::cout << "char : " << literal << std::endl;
    std::cout << "int : " << static_cast<int>(literal[0]) << std::endl;
    std::cout << "float : " << static_cast<float>(literal[0]) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(literal[0]) << ".0" << std::endl;
    return;
  }

  if(check_int(literal)){
    int a = std::atoi(literal.c_str());

    if(a >= 32 && a <= 126)
      std::cout << "char : " << static_cast<char>(a) << std::endl;
    else
      std::cout << "char : Non Displayable\n";
    std::cout << "int : " << a << std::endl;
    std::cout << "float : " << static_cast<float>(a) << ".0f" << std::endl;
    std::cout << "double : " << static_cast<double>(a) << ".0" << std::endl;
  }

}
