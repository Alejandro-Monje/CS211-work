//=====================================================//
//Name: Alejandro Monje//
//Date: 4/08/16//
//lab: LLClient.C//
//Purpose: make a program that will be used to test the functions we made
//=====================================================//
#include <iostream>
#include "LL.h"
using namespace std;
int main()
{
  LL t;// make a new object

  t.addRear(3);
  t.addRear(9);
  t.addRear(2);
  t.addRear(1);
  t.addRear(9);
  t.addRear(11);
  t.deleteNode(9);
  t.displayAll();
  t.deleteNode(9);
  cout << endl;
  t.displayAll();
  cout << endl;
  t.deleteNode(5);
  t.displayAll();
  cout << endl;
  t.deleteNode(3);
  t.displayAll();
  cout << endl;
  t.deleteNode(11);
  t.displayAll();
  cout << endl;
  t.deleteNode(1);
  t.displayAll();
  cout << endl;
  t.deleteNode(2);
  t.displayAll();
  cout << endl;
  t.deleteNode(5);
 
  return 0;
}
