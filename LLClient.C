//=====================================================//
//Name: Alejandro Monje//
//Date: 4/08/16//
//lab: LLClient.C//
//Purpose: make a program that will be used to test the functions we made
//=====================================================//
#include <iostream>
#include "LL_T_E.h"
using namespace std;
int main()
{
  LL<int> t;// make a new object
 try
   {
  //we will add to the front 3 times
  t.deleteFront();
  t.addFront(1);
  t.addFront(2);
  t.addFront(3);
  //we will add to the rear twice
  t.addRear(4);
  t.addRear(5);
  //we will display the contents
  t.displayAll();
  cout << endl;
  //will show the elements that where deleted from the front and the rear
  cout << t.deleteFront() << " is now deleted: " << endl;
  cout << t.deleteRear() << " is now deleted: " << endl;
  //will display the contents
  t.displayAll();
  cout << endl;
  //will show the elements that was deleted from front and rear
  cout << t.deleteFront() << " is now deleted: " << endl;
  cout << t.deleteRear() << " is now deleted: " << endl;
  //will display the contents at this point
  t.displayAll();
  cout << endl;
  //will show the element that was deleted from the front
  cout << t.deleteFront() << " is now deleted: " << endl;
  // will display the contents
  t.displayAll();
  cout << endl;
  //will add 10 to the front and 11 to the rear
  t.addRear(10);
  t.addFront(11);
  //will display the contents 1110
  t.displayAll();
  cout << endl;
  //will show what is deleted from the rear
  cout << t.deleteRear() << " is now deleted: " << endl;
  cout << t.deleteRear() << " is now deleted: " << endl;
  t.displayAll();
  
   }
 catch(LL<int>::Underflow)
   {
     cout << "Error tring to delete when empty: " << endl; 
   }

  return 0;
}
