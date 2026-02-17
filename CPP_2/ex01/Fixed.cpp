/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:56:12 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/14 17:33:59 by mdakni           ###   ########.fr       */
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
        this->n = other.getRawBits();
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}


int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return n;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    n = raw;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os,const Fixed& f){
    os << f.toFloat();
    return os;
}
