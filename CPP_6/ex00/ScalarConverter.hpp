#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cfloat>
#include <string>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <iostream>

class ScalarConverter{

private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(ScalarConverter const &other);
  ~ScalarConverter();

public:
  static void convert(const std::string &literal);
};

#endif
