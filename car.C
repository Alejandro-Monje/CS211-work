//Name: Alejandro Monje
//Date:2/17/16

#include <iostream> 
using namespace std;
#include "car.h" 

Car::Car(string f, string l, int d, string re, int m, int xp, int yp)
{
  make = f;
  model = l;
  year = d;
  color = re;
  miles = m;
  x = xp;
  y = yp;
}
string Car::getMake() const
{
  return make;
}
string Car::getModel() const
{
  return model;
}
int Car::getYear() const
{
  return year;
}
int Car::getMiles() const
{
  return miles;
}
string Car::getColor() const
{
  return color;
}
void Car::chColor(string rePaint)
{
  color = rePaint;
  
}
int Car::goFowards(int block)
{
  y += block;
  miles += block;
}
int Car::goBackwards(int block)
{
  y -= block;
  miles += block;
  
}
int Car::goLeft(int block)
{
  x -= block;
  miles += block;
  
}

int Car::goRight(int block)
{
  x += block;
  miles += block;

}
