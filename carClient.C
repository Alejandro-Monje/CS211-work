//Name: Alejandro Monje
//Date:2/17/16

#include <iostream>
using namespace std;

#include "car.h"
void View(const Car& c);
int main()
{
  Car num1(" Toyota ", "Celica ", 2016, " White ", 0, 0, 0);
  cout << endl;
  Car num2(" Honda ", "Civic ", 2008, " Black ", 20000, 2, 2);
  num1.goFowards(3);
  num2.goBackwards(1);
  num1.goRight(2);
  num2.goLeft(5);
  View(num1);
  View(num2);
  num1.chColor("Red");
  View(num1);
  return 0;
}
void View(const Car& c)
{
    cout << c.getMake() << ", "  << c.getModel() << ", " << c.getYear() << ", " << c.getColor() << ", " << c.getMiles();
    cout << endl;
}
