/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:18:27 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/14 17:30:49 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){}

Point::~Point(){}

Point::Point(const float x, const float y): x(x), y(y){}

Point::Point(const Point& other): x(other.x), y(other.y){}

Point& Point::operator=(const Point& other){
  this->x = other.x;
  this->y = other.y;
  return *this;
}

Fixed Point::get_x() const {
  return x;
}
Fixed Point::get_y() const {
  return y;
}
