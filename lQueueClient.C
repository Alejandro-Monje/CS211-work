//=====================================================//
//Name: Alejandro Monje//
//Date: 4/08/16//
//lab: lQueueClient.C//
//Purpose: make a program that will be used to test the functions we made
//=====================================================//
#include <iostream>
#include "lQueue.h"
using namespace std;
int main()
{
  lQueue t;// make a new object
  
  if(t.isEmpty())// check if it is empty
    cout << "Error the queue is empty: " << endl;
  else
    t.view();//Will display the contents 
  
  t.addRear(1);//Will add an element to the rear
  t.view();// will display the contents
  cout << endl; 
      t.addRear(2);//Will add an element to the rear
      
      t.addRear(3);//Will add an element to the rear
      
      t.addRear(4);//Will add an element to the rear
      
      t.view();//Will display the contents
      cout << endl;      
      cout << "The element that was deleted is: " << t.deleteFront() << endl;
      // deletes the front element and displays what is deleted
      cout << "The element that was deleted is: " << t.deleteFront() << endl;
      // deletes the front element and displays what is deleted
      cout << "The element that was deleted is: " << t.deleteFront() << endl;
      // deletes the front element and displays what is deleted
      
      t.view();//Will display the contents
      cout << endl;
      
      if(t.isEmpty())//Checks if it is empty
	cout << "Error the queue is empty: " << endl;
      else        
	cout << "Queue is not empty: " << endl;
      cout << "The element that was deleted is: " << t.deleteFront() << endl;
      
      if(t.isEmpty())//Checks if it is empty
	cout << "Error the queue is empty: " << endl;
      else
	
	t.view();//Will display the contents
	  
      cout << "The element that was deleted is: " << t.deleteFront() << endl;
      
      
      
      return 0;
}
