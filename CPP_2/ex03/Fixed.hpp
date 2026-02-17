/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:16:35 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/14 17:17:19 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
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
    bool operator>(const Fixed &other);
    bool operator<(const Fixed &other);
    bool operator>=(const Fixed &other);
    bool operator<=(const Fixed &other);
    bool operator==(const Fixed &other);
    bool operator!=(const Fixed &other);
    Fixed operator+(const Fixed &other);
    Fixed operator-(const Fixed &other);
    Fixed operator*(const Fixed &other);
    Fixed operator/(const Fixed &other);
    Fixed operator++();
    Fixed operator++(int);
    Fixed operator--();
    Fixed operator--(int);
    static Fixed &min(Fixed &n1, Fixed &n2);
    static const Fixed &min(const Fixed &n1, const Fixed &n2);
    static Fixed &max(Fixed &n1, Fixed &n2);
    static const Fixed &max(const Fixed &n1, const Fixed &n2);
  ~Fixed(); 
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt( void ) const;
    
};


std::ostream& operator<<(std::ostream& os,const Fixed& f);

#endif