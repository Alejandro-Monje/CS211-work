//Name: Alejandro Monje
//Date:2/18/16

#include <iostream>
using namespace std;
#include "price.h"

Price::Price()
{
  dollar = 0;
  cent = 0;
}

Price::Price(int d, int c)
{
   dollar = d;
   cent = c;
}

Price Price::operator+(const Price& another)
{
  int Dollar = this->dollar + another.dollar;
  int Cent = this->cent + another.cent;
  if(Cent >= 100)
    {
    Cent = Cent - 100;
    Dollar += 1;
    }
  Price l(Dollar, Cent);
  return l;
}

Price Price::operator-(const Price& another)
{
    int dol;
    int cen;
    //The second price is greater than the first price
    if(this->dollar < another.dollar)
      {
	int c = (this->dollar*100) + this->cent - (another.dollar*100) - another.cent;
	dol = c/100;
	cen = c%100;
      }
    else
      {
	dol = this->dollar - another.dollar;
	cen = this->cent - another.cent;
	if(cen < 0)
	  {
	    cen += 100;
	    dol--;
	  }
      }
    Price newPrice(dol, cen);
    return newPrice;
  }

int Price::getDollar() const
{
  return dollar;
}

int Price::getCent() const
{
  return cent;
}
