#pragma once

#include <iostream>
#include <string>

class Fixed{
private:
    int n;
    static const int shift = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
