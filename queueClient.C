//****************************************************************************
//CS211
//Lab 8, Assignment 4
//queueClient.C
//Name: Alejandro Monje
//Date: 3/16/16
//Purpose: uses a menu to ask user to enter there choice. The user inputs test the queue.
//////////

#include <iostream>
#include "queue.h"
#include "inputCheck.h"
using namespace std;
int main()
{
  Queue newQueue;
  int pick;
  luck elem;
     cout << "\n==============================================" << endl;
     cout << "1: Add a new element:" << endl; // menu option 1
     cout << "2: Remove an element:" << endl;  //menu option 2
     cout << "3: Check to see what is at the front:" << endl;//menu option 3
     cout << "4: Goes back to the rear of queue:" << endl;//menu option 4
     cout << "5: Gets the number of elements in the queue:" << endl;//menu option 5
     cout << "6: Display elements in the queue:" << endl;//menu option 6
     cout << "7: End the program: " << endl;//menu option 7
   do
    {
      cout << "Enter your choice: ";
      pick = getNumberInRange(1, 7, "Invalid choice. Enter 1 through 6: ");
      
      switch(pick)
	{
	case 1:
	  cout << "Enter an element here: "; //wil allow user to add element
          cin >> elem;
           newQueue.add(elem);
          break;
	case 2:
          cout << "The element that has been removed is: " << newQueue.remove() << endl;// will remove element 
          break;
	case 3:
          cout << "The element in front is: " <<  newQueue.topElem() << endl; // will check to see what is at the front
	  break;
	case 4:
	  cout << "Went back to the rear: " << endl; // will take the user back to the rear
	   newQueue.goToBack();
	  break;
	case 5:
	  cout << "The size of the queue is: " << newQueue.getSize() << endl; // gets the queue size
	  break;
	case 6:
	  newQueue.view();// displays the contents of the queue
	  break;
	case 7:
	  cout << "Ending the program ..............." << endl;// will end the program
	}
    }while(pick < 7);

  return 0;
}
