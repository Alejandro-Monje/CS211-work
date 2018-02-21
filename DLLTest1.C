#include <iostream>
#include "DLL.h"
using namespace std;
int main()
{
  DLL t;
  t.addFront(1);
  t.addFront(2);
  t.addFront(3);
  t.addRear(4);
  t.addRear(5);
  t.displayAll(); //3 2 1 4 5 (show all the elements on the same line)
  cout << endl;
     t.printAllReverse(); // 5 4 1 2 3
     cout << endl;
	/* t.deleteFront(); //3 has been deleted (you need to say “ has been deleted”)
  t.deleteRear(); //5 has been deleted
  t.displayAll(); //2 1 4
  t.deleteFront(); //2 has been deleted
  t.deleteRear(); //4 has been deleted
  t.displayAll(); //1
  t.deleteFront(); //1 has been deleted
  t.displayAll(); //[empty]
  t.addRear(10);
  t.addFront(11);
  t.displayAll(); //11 10
  t.deleteRear(); //10 has been deleted
  t.deleteRear(); //11 has been deleted
  t.displayAll(); //[empty]
  */
      return 0;
}
