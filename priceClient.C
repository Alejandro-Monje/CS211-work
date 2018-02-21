//Name: Alejandro Monje
//Date:2/19/16

#include <iostream>
using namespace std;
#include "price.h"
int main()
{
  Price P;
  Price Dollar(3, 50);
  Price Cent(2, 75);
  Price l = Dollar + Cent;
  
  cout << "The total price is " << l.getDollar() << " dollars and " << l.getCent() << " cents" << endl;  
  return 0;
}



