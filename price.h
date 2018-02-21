//Name: Alejandro Monje
//Date:2/18/16

#include <string>
using namespace std;
#ifndef PRICE_H
#define PRICE_H
class Price
{
 private:

  int dollar;
  int cent;

 public:
  Price();
  Price(int, int);
  Price operator+(const Price& another);
  Price operator-(const Price& another);
  int getCent() const;
  int getDollar() const;


};

#endif
