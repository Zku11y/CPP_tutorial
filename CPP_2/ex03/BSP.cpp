#include "BSP.hpp"

float get_side(Point const &a, Point const &b, Point const &c){
  Fixed side = (b.get_x() - a.get_x()) * (c.get_y() - a.get_y())
    - (b.get_y() - a.get_y()) * (c.get_x() - a.get_x());
  return side.toFloat();
}

Node *get_tree(Point const &a, Point const &b, Point const &c){
  Node* list = new Node(a, b);
  Node *next;
  float side = get_side(a, b, c);
  if(side == 0){
    return NULL;
  }
  if(side > 0){
    list->left = new Node(b, c);
    next = list->left;
  }
  else{
    list->right = new Node(b, c);
    next = list->right;
  }

  side = get_side(b, c ,a);
  if(side > 0)
    next->left = new Node(c, a);
  else
    next->right = new Node(c, a);

  return list;
}

bool get_pos(Node* node, int &Dir, const Point &p){
  if(!node)
    return true;

  float side = get_side(node->p1, node->p2, p);
  if(Dir == LEFT && side > 0)
    return get_pos(node->left, Dir, p);
  if(Dir == RIGHT && side < 0)
    return get_pos(node->right, Dir, p);
  return false;
}

void free_list(Node *list, int &Dir){
  if(Dir == RIGHT){
    delete(list->right->right);
    delete(list->right);
    delete(list);
  }
  else{
    delete(list->left->left);
    delete(list->left);
    delete(list);
  }
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
  Node *list = get_tree(a, b, c);
  int Dir;
  if(list == NULL)
    return false;
  if(list->right != NULL)
    Dir = RIGHT;
  else
    Dir = LEFT;
  bool result = get_pos(list, Dir, point);
  free_list(list, Dir);
  if(result == true)
    return true;
  return false;
}
