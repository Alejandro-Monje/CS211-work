
//=====================================================//
//Name: Alejandro Monje//
//Date: 5/12/16//
//lab: DLL.C//
//Purpose: Holds all the functions that will be needed//
//=====================================================//

#include <iostream>
using namespace std;
#include "DLL.h" //queue.h holds the prototypes
//Purpose: will be used every time a new object is created
//Algorithm:front and rear are set to null and count set to 0
//Parameters: none
DLL::DLL()// constructor
{
  front = NULL; //shows that there are no elements to begin with
  rear = NULL;
  count = 0;
}
//Purpose: will be used every time an object is deleted or goes out of the scope
//Algorthm:while the queue isn't empty it will delete
//parameters: none
DLL::~DLL()
{
  while(!isEmpty())
    deleteFront();
}
//Purpose: finds out if the queue is empty
//Algorthm: returns true if rear and front are both null because it is empty and
//returns false if it isn't empty
//Parameters: none
bool DLL::isEmpty() // Checks to see if the queue is empty
{
  if(front == NULL && rear == NULL)
    return true;  // returns true if the queue  is empty
  else
    return false;// else it returns flase meaning there is something in the queue
}
//Purpose: adds an element to the rear of the queue
//Algorthm: if count is 0 it will majke front and rear equal and make a new node
//else it will make the rear point to a new cell
//Parameters: luck input
void DLL::addRear(luck input) // will add an element to the queue
{
  
  if(isEmpty())
    {
      front = rear = new node;
//when empty a new node is created and both f and r point at it
// front then move back to the front.
      front -> next = NULL;
      front -> prev = NULL;
    }
  else
    {
      //when its not empty make rear point to a new node and make a new rear
	rear -> next = new node;
	rear -> next -> prev = rear;
	rear = rear -> next;
      }
  rear -> next = NULL; 
  rear -> elem = input;
  count++;  
}
//Purpose: will delete an element from the front of the queue
//Algorthm: will check to see if it empty and if not empty it will delete an element f//rom th front and front will point to next
//Parameters:  none
luck DLL::deleteFront() // will remove one element from the top of the queue  if not empty
{
  luck a;
  if(isEmpty())
    DLLError("queue is empty"); // first it will check if the queue  is empty
  else if(count == 1)
    {
      //if only on e thing then just delete it
      a = front -> elem;
      delete front;
      front = rear = NULL;
    }
  else
    {
      //if more than one thing point to front delete
      a = front -> elem;
      front = front -> next;
      delete front -> prev;
      front -> prev = NULL;
    }
  count--;
  // points to what we deleted and returns that value
  return a;
}
//Purpose: Will display the error
//Algorthm: cout a message and has an emergency exit
//Parameters: string msg
void DLL::DLLError(string msg) // will display an error message
{
  cout << msg << endl;
  exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors
  
}
//Purpose: will display the contents in the queue
//Algorthm: Will create a new pointer d that will point to front so that we dont chang//e the front and then display the element. then oint to the next.
//Parameters: none
void DLL::displayAll() 
{
  node* d = front; // make d point to front
  while(d != NULL) 
    {
      cout << d -> elem;
      d = d -> next;
    }
}
//Purpose:Will be used to print the contents in reverse
//Algorthm:call printAllReverse with the parameters front
//Parameters: none
void DLL::printAllReverseDLL()
{
  printAllReverseDLL(rear);
}
//Purpose:Will be used to print contents in reverse
//Algorthm: calls printAllReverse(a -> next) and the displays the contents with 
// cout << a -> elem to print the reverse order
//Parameters: node* a
void DLL::printAllReverseDLL(node* P)
{
  
  for(P; P != NULL; P = P -> prev)
    {
      cout << P -> elem;
    }  
}
//purpose: Will add to the front of the queue
//Algorthm: checks isEmpty and if it is it will creat a new node so that we can add to the front else a we make front point and also make another node so we can add to the front
//parameters: input
void DLL::addFront(luck input)
{
  if(isEmpty())
    {

      // if empty we make a new node then move front to the node infront of that node
      front = rear = new node;
      front -> next = NULL;
      front -> prev = NULL;
      rear -> next = NULL;
      rear -> elem = input;
    }
  else
    {
      // we find the orginall front then make front move in front of that orginal 
      node* a = front;
      front = new node;
      front -> elem = input;
      front -> next = a;
      a -> prev = front;
      front -> prev = NULL;
    }
  count++;
}
//Purpose: to delete from the rear
//Algorthm: Checks to see if it is empty. if count = 1 then the front will be deleted. Else we make a new node* that isnt the rear so that we can delete the rear and then the new rear is the node we made.
//parameters: none
luck DLL::deleteRear()
{
  luck a = rear -> elem;
  if(isEmpty())
    DLLError("Is Empty");
  if(count > 1)
    {
      node* d = rear;
      rear = rear -> prev;
      delete d;
      rear -> next = NULL;
    }
  else if(count == 1)
    {
      delete rear;
      rear = front = NULL;
    }
  count --; 
  return a;
}
//Purpose: to delete a node
//Algorithm: Check is empty then if the element is in the linked list it will be deleted
//if the front element = the inputed element it will delete the front else if del != Null and del doesn't equal the element the del will move to next node if it reaches Null without finding the lement it will return else if del is equal to rear then rear will become the p[rvios node and del will be deleted and then it will decrement
//Parameters:Luck input
//How to call: deleteNode(input)
void DLL::deleteNode(luck input)
{ 
  // check if its empty
  if(isEmpty())
    return;
  else
    {
      // deleteFront if the fron element is equal to the inputed element
      if(input == front -> elem )
	deleteFront();
      else if(input == rear -> elem)
	deleteRear();
      else
	{
	  
	  node* del;
	  for(del = front ->next; del != NULL && del -> elem != input; del = del -> next)
;
       
          if(del != NULL)
	    {
	      del -> prev -> next = del -> next;
	      del -> next -> prev = del -> prev;
	    }
	  else if(del == NULL)
            return;
	  else if(del == rear)
	    {
	      rear = del -> prev;
              rear -> next = NULL;
	    }
	  delete del;
	  count --;
	}
    }
}
//Purpose: will put the elements in ascending order
//algorthm:if its empty or the input is less than front element then the inputed element i\
//s added to the front else p is used to put the element that is less than the inputed eleme//nt \
// in front and then it will increment
  //Parameters:Luck input
  //How to call: addInOrderAscend(input)
void DLL::addInOrderAscend(luck input)
{

  if(isEmpty())
    {
      addRear(input);
    }
  else if(rear -> elem <= input)
    {// if there is nothing there
      addRear(input);
    }
  else if(front -> elem >= input)
    {
      // if the input is less than the front element
      addFront(input);
    }
  else 
    {
      node* p = front;
      while(p -> next != NULL && p -> next -> elem <= input)
	p = p -> next;
      node* n = new node;
      n -> next = p -> next;
      n -> prev = p; 
      p -> next -> prev = n;
      p -> next = n;
      n -> elem = input;
      count ++;
     
    }    
}
//Purpose: To delete multiple of the same node
//Algorthm: check to see if the linked list is empty if not it will go throuh the list unt\
//ill the element we want is deleted and will go through the entire list to get rid of multi\
//ples of that element
//Parameters:Luck input
//How to call: deleteNodes(input)

void DLL::deleteNodes(luck input)
{
  //check to see if its empty
  if(isEmpty())
    return;
  else
    {
      node* del;
      node* pre;
      // if the front element is equal to the inputed element delete the front
      if(front -> elem == input)
        {
          deleteFront();
        }
      if(count > 1)
        {
          pre = front;
          del = front -> next;
          for(del, pre; del != NULL; pre = del, del = del -> next)
            {
	      //if del is equal to the inputed element and the rear then deleteRear
              if(del -> elem == input && del == rear)
                deleteRear();
              else if(del -> elem == input)
                {
		  //if del points to the element that is equal to the inputed element than
                  //delete del
                  pre -> next = del -> next;
                  delete del;
                  count --;
                }
            }
        }
    }
}
//Purpose: will put the elements in descending order
//Algorthm: if its empty or the input is greater than the front element then the inputed e\
//lement is added to the front else P is used to put the element that is greater than the in//putted element in front and increment.
  //Parameters:Luck input
  //How to call: addInOrderDescend(input)

void DLL::addInOrderDescend(luck input)
{
  if(isEmpty())
    {
      addRear(input);
    }
  else if(rear -> elem >= input)
    {// if there is nothing there
      addRear(input);
    }
  else if(front -> elem <= input)
    {
      // if the input is less than the front element
      addFront(input);
    }
  else
    {
      node* p = front;
      while(p -> next != NULL && p -> next -> elem <= input)
        p = p -> next;
      node* n = new node;
      n -> next = p -> next;
      n -> prev = p;
      p -> next -> prev = n;
      p -> next = n;
      n -> elem = input;
      count ++;
    }

}
//Purpose: will search for an element
//Algorthm: if a pointer isn't null then it will go throught the linked list until it is e\
//qual to the element and returns true if found else it returns false
  //Parameters:Luck input
  //How to call: search(input)

bool DLL::search(luck input)
{
  int comp = 0;
  if(isEmpty())
    return false;
  else
    {
      node* a = front;
      //goes throught the whole linked list
      for(a; a != NULL; a = a -> next)
	{
          comp ++;
	  if(a -> elem == input)// if the element is found return true
	    {
	    cout << comp << " times compared: " << endl; 
          return true;
	    }
	}
      cout << comp << " times compared: " << endl;
      return false;// if not found return false
    }
}
