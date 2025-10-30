#include "Point.hpp"

#define LEFT 0
#define RIGHT 1

struct Node{
  Node* left;
  Node* right;
  Point const p1;
  Point const p2;

  Node(Point const t1, Point const t2): left(NULL), right(NULL), p1(t1), p2(t2){}
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
