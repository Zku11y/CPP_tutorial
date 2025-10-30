#include "Fixed.hpp"

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
  Fixed get_x() const {return x;}
  Fixed get_y() const {return y;}
};
