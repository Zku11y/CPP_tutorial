#pragma once

#include <iostream>
#include <string>
#include <cmath>

class Fixed{
private:
    int n;
    static const int shift = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int other);
    Fixed(const float other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt( void ) const;
};


std::ostream& operator<<(std::ostream& os,const Fixed& f);
