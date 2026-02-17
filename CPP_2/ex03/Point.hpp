/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:18:30 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/14 17:56:15 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#define LEFT 0
#define RIGHT 1

class Point {
private:
  Fixed x;
  Fixed y;

public:
  Point();
  Point(const float x, const float y);
  ~Point();
  Point(const Point& other);
  Point& operator=(const Point& other);
  Fixed get_x() const;
  Fixed get_y() const;
};

struct Node{
  Node* left;
  Node* right;
  Point const p1;
  Point const p2;

  Node(Point const t1, Point const t2): left(NULL), right(NULL), p1(t1), p2(t2){}
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
