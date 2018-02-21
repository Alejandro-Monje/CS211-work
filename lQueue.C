//=====================================================//
//Name: Alejandro Monje//
//Date: 4/08/16//
//lab: lQueue.C//
//Purpose: Holds all the functions that will be needed//
//=====================================================//

#include <iostream>
using namespace std;
#include "lQueue.h" //queue.h holds the prototypes
//Purpose: will be used every time a new object is created
//Algorithm:front and rear are set to null and count set to 0
//Parameters: none
lQueue::lQueue()// constructor
{
  front = NULL; //shows that there are no elements to begin with
  rear = NULL;
  count = 0;
}
//Purpose: will be used every time an object is deleted or goes out of the scope
//Algorthm:while the queue isn't empty it will delete
//parameters: none
lQueue::~lQueue()
{
  while(!isEmpty())
    deleteFront();
}
//Purpose: to check if the queue is empty
//Algorthm: returns true if rear and front are both null because it is empty and
//returns false if it isn't empty
//Parameters: none
bool lQueue::isEmpty() // Checks to see if the queue is empty
{
  if(front == NULL && rear == NULL)
    return true;  // returns true if the queue  is empty
  else
    return false;// else it returns flase meaning there is something in the queue
}
//Purpose: adds an element to the queue
//Algorthm: if count is 0 it will majke front and rear equal and make a new node
//else it will make the rear point to a new cell
//Parameters: luck input
void lQueue::addRear(luck input) // will add an element to the queue
{
  if(count == 0)
    front = rear = new node;
  else
    {
      rear -> next = new node;
      rear = rear -> next;
    }
  rear -> elem = input;
  rear -> next = NULL; 
  count++;  
}
//Purpose: will delete an element from the queue
//Algorthm: will check to see if it empty and if not empty it will delete an element f//rom th front and front will point to next
//Parameters:  none
luck lQueue::deleteFront() // will remove one element from the top of the queue  if not empty
{
  luck a;
  if(isEmpty())
    queueError("queue is empty"); // first it will check if the queue  is empty
  else
    {
      node* p = front;
      front = front -> next;
      a = p -> elem;
      count--;
      delete p;
      if(count == 0)
	{
	  rear = NULL;
	}
    }
  return a;
}
//Purpose: Will display the error
//Algorthm: cout a message and has an emergency exit
//Parameters: string msg
void lQueue::queueError(string msg) // will display an error message
{
  cout << msg << endl;
  exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors
  
}
//Purpose: will display the contents in the queue
//Algorthm: Will create a new pointer p that will point to front so that we dont chang//e the front and then cout p
//Parameters: none
void lQueue::view() 
{
  node* p = front; // make p point to front
  while(p != NULL) 
    {
      cout << p -> elem;
      p = p -> next;
    }
}
//Purpose:Will be used to print the contents in reverse
//Algorthm:call printAllReverse with the parameters front
//Parameters: none
void lQueue::printAllReverse()
{
  printAllReverse(front);
}
//Purpose:Will be used to print contents in reverse
//Algorthm: calls printAllReverse(p -> next) and the displays the contents with 
// cout << P -> elem
//Parameters: node* P
void lQueue::printAllReverse(node* P)
{
    
  if(P == NULL)
    return;
  else
    {
      printAllReverse(P -> next);// Calls itself
      cout << P -> elem; //Display
    }
}
