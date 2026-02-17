/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:30:42 by mdakni            #+#    #+#             */
/*   Updated: 2026/02/14 17:47:42 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(){
  Point a(1, 1);
  Point b(4, 4);
  Point c(4, 0);
  Point p(2, 1);

  if(bsp(a, b, c, p) == true)
    std::cout << "p is inside the triangle\n";
  else {
    std::cout << "p is outside the triangle\n";
  }
  return 0;
}
