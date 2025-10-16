#include "Fixed.hpp"

Fixed::Fixed(): n(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): n(other.n){
    std::cout << "Copy constructor called" << std::endl;
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

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}