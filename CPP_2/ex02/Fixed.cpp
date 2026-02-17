/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:17:13 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/14 17:33:41 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): n(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): n(other.n){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int other): n(other * (1 << shift)){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float other): n((int)roundf(other * (1 << shift))){
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const{
  return ((float)((float)n / (1 << shift)));
}

int Fixed::toInt(void) const{
  return ((int)((float)n / (1 << shift)));
}

Fixed &Fixed::operator=(const Fixed &other){
    if(this != &other)
        this->n = other.n;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

bool Fixed::operator>(const Fixed &other){
  return (this->n > other.n);
}


bool Fixed::operator<(const Fixed &other){
  return (this->n < other.n);
}


bool Fixed::operator>=(const Fixed &other){
  return (this->n >= other.n);
}


bool Fixed::operator<=(const Fixed &other){
  return (this->n <= other.n);
}


bool Fixed::operator==(const Fixed &other){
  return (this->n == other.n);
}


bool Fixed::operator!=(const Fixed &other){
  return (this->n != other.n);
}

Fixed Fixed::operator+(const Fixed &other){
  Fixed tmp;
  tmp.n = this->n + other.n;
  return tmp;
}

Fixed Fixed::operator++(){
  this->n++;
  return *this;
}

Fixed Fixed::operator++(int){
  Fixed tmp;
  tmp.n = this->n++;
  return tmp;
}

Fixed Fixed::operator--(){
  this->n--;
  return *this;
}

Fixed Fixed::operator--(int){
  Fixed tmp;
  tmp.n = this->n--;
  return tmp;
}

Fixed Fixed::operator-(const Fixed &other){
  Fixed tmp;
  tmp.n = this->n - other.n;
  return tmp;
}

Fixed Fixed::operator*(const Fixed &other){
  Fixed tmp;
  tmp.n = (this->n * other.n) / (1 << shift);
  return tmp;
}

Fixed Fixed::operator/(const Fixed &other){
  Fixed tmp;
  tmp.n = (this->n / other.n) * (1 << shift);
  return tmp;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return n;
}

void Fixed::setRawBits(int const raw){
  std::cout << "setRawBits member function called" << std::endl;
    n = raw;
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2){
  if(n1.n <= n2.n)
    return n1;
  return n2;
}

const Fixed& Fixed::min(const Fixed &n1, const Fixed &n2){
  if(n1.n <= n2.n)
      return n1;
  return n2;
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2){
  if(n1.n >= n2.n)
    return n1;
  return n2;
}

const Fixed& Fixed::max(const Fixed &n1, const Fixed &n2){
  if(n1.n >= n2.n)
    return n1;
  return n2;
}

Fixed::~Fixed(){
  std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os,const Fixed& f){
    os << f.toFloat();
    return os;
}

