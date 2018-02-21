#include <string>
#include <iostream>
using namespace std;
#ifndef LL_T_E_h
#define LL_T_E_h

template <class T>
struct node
{
   T elem;
  node<T>* next;
};
//Purpose: to create a class called lQueue
//algorithm: will hold the prototypes
//parameters: private and public
template <class T>
class LL
{
 private:
  int count;
  node<T>* front;
  node<T>* rear;
  //Purpose: Will display the error
  //Algorthm: cout a message and has an emergency exit
  //Parameters: string msg
  //How to call:
  //  void LLError(string msg);

 public:
  
  //Purpose: will be used every time a new object is created
  //Algorithm:front and rear are set to null and count set to 0
  //Parameters: none
  //How to call: will be used wheever an object is made.
  LL(); //Constructor
  //Purpose: will be used every time an object is deleted or goes out of the scope
  //Algorthm:while the queue isn't empty it will delete
  //parameters: none
  //how to call: will be used whenever an object is deleted or leaves the scope
  ~LL();// Destructor
  //Purpose: finds out if the queie is empty
  //Algorthm: returns true if rear and front are both null because it is empty and
  //returns false if it isn't empty
  //Parameters: none
  //how to call: isEmpty();
  bool isEmpty (); //checks to see if the stack is empty
  //Purpose: adds an element to the rear of the queue
  //Algorthm: if count is 0 it will majke front and rear equal and make a new node
  //else it will make the rear point to a new cell
  //Parameters: luck input
  //How to call: func name an element passed to it
  void addRear(T input); //adds a new element
  //if it is full there will be an error
  //Purpose: will delete an element from the front of the queue
  //Algorthm: will check to see if it empty and if not empty it will delete an element f//ro\m th front and front will point to next
  //Parameters:  none
  //How to call: deleteFront();
  T deleteFront(); //deletes an element
//if empty there will be an error
//Purpose: will display the contents in the queue
//Algorthm: Will create a new pointer d that will point to front so that we dont chang//e \
    //the front and then display the element. then point to the next.
  //Parameters: none
  // How to call: displayAll();
  void displayAll();//Will display the contents
//Purpose:Will be used to print the contents in reverse
  //Algorthm:call printAllReverse with the parameters front
  //Parameters: none
  //How to call: printAllReverse();
  void printAllReverse();//will be used to reverse
  //Purpose:Will be used to print contents in reverse
  //Algorthm: calls printAllReverse(a -> next) and the displays the contents with
  // cout << a -> elem to print the reverse order
  //Parameters: node* a
  //how to call: function name with the pointer paseed to it
  void printAllReverse(node<T>* a);//will be used to reverse the linked list
  //purpose: Will add to the front of the queue
  //Algorthm: checks isEmpty and if it is it will creat a new node so that we can add to the\front else a we make front point and also make another node so we can add to the front
	 //parameters: luck input
	 //how to call: function with an element passed to it
  void addFront(T input);
  //Purpose: to delete from the rear
  //Algorthm: Checks to see if it is empty. if count = 1 then the front will be deleted. Els\//e we make a new node* that isnt the rear so that we can delete the rear and then the new rear is the node we made.
  //parameters: none
  //how to call: deleteRear();
  T deleteRear();
//Purpose: to delete a node
//Algorithm: Check is empty then if the element is in the linked list it will be deleted
//Parameters:Luck input
//How to call: deleteNode(input)
 void deleteNode(T input);
 //Purpose: To delete multiple of the same node
 //Algorthm: check to see if the linked list is empty if not it will go throuh the list unt\
   //ill the element we want is deleted and will go through the entire list to get rid of mu//ltipes of that element
  //Parameters:Luck input
  //How to call: deleteNodes(input)
  void deleteNodes(T input);
  //Purpose: will put the elements in ascending order
  //algorthm:if its empty or the input is less than front element then the inputed element i//s added to the front else p is used to put the element that is less than the inputed eleme//n in front and then it will increment
 //Parameters:Luck input
 //How to call: addInOrderAscend(input)
   void addInOrderAscend(T input);
 //Purpose: will put the elements in descending order
 //Algorthm: if its empty or the input is greater than the front element then the inputed e\
   //lement is added to the front else P is used to put the element that is greater than the //inpu\ted element in front and increment.
   //Parameters:Luck input
   //How to call: addInOrderDescend(input)
  void addInOrderDescend(T input);
  //Purpose: will search for an element
  //Algorthm: if a pointer isn't null then it will go throught the linked list until it is e//qual to the element and returns true if found else it returns false
  //Parameters:Luck input
  //How to call: search(input)
  bool search(T input);
  class Underflow{};
};
#endif
//Purpose: will be used every time a new object is created
//Algorithm:front and rear are set to null and count set to 0
//Parameters: none
template <class T>
LL<T>::LL()// constructor
{
  front = NULL; //shows that there are no elements to begin with
  rear = NULL;
  count = 0;
}
//Purpose: will be used every time an object is deleted or goes out of the scope
//Algorthm:while the queue isn't empty it will delete
//parameters: none
template <class T>
LL<T>::~LL()
{
  while(!isEmpty())
    deleteFront();
}
//Purpose: finds out if the queue is empty
//Algorthm: returns true if rear and front are both null because it is empty and
//returns false if it isn't empty
//Parameters: none
template <class T>
bool LL<T>::isEmpty() // Checks to see if the queue is empty
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
template <class T>
void LL<T>::addRear(T input) // will add an element to the queue
{
  if(count == 0)
    front = rear = new node<T>;
  else
    {
      rear -> next = new node<T>;
      rear = rear -> next;
    }
  rear -> elem = input;
  rear -> next = NULL;
  count++;
}
//Purpose: will delete an element from the front of the queue
//Algorthm: will check to see if it empty and if not empty it will delete an element f//rom //th front and front will point to next
//Parameters:  none
template <class T>
T LL<T>::deleteFront() // will remove one element from the top of the queue  if not empty
{
  T a;
  if(isEmpty())
    throw Underflow(); // first it will check if the queue  is empty
  else
    {
      node<T>* P = front;
      front = front -> next;// point to the next node
      a = P -> elem;// will point to the element
      count--;// will decrement
      delete P;//deletes p
      if(count == 0)
	rear = NULL;
      return a;

    }
}
//Purpose: Will display the error
//Algorthm: cout a message and has an emergency exit
//Parameters: string msg
//template <class T>
//void LL<T>::LLError(string msg) // will display an error message
//{
// cout << msg << endl;
// exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors

//}
//Purpose: will display the contents in the queue
//Algorthm: Will create a new pointer d that will point to front so that we dont chang//e th\//e front and then display the element. then oint to the next.
//Parameters: none
template <class T>
void LL<T>::displayAll()
{
  node<T>* d = front; // make d point to front
  while(d != NULL)
    {
      cout << d -> elem;
      d = d -> next;
    }
}
//Purpose:Will be used to print the contents in reverse
//Algorthm:call printAllReverse with the parameters front
//Parameters: none
//Purpose:Will be used to print the contents in reverse
//Algorthm:call printAllReverse with the parameters front
//Parameters: none
template <class T>
void LL<T>::printAllReverse()
{
  printAllReverse(front);
}
//Purpose:Will be used to print contents in reverse
//Algorthm: calls printAllReverse(a -> next) and the displays the contents with
// cout << a -> elem to print the reverse order
//Parameters: node* a
template <class T>
void LL<T>::printAllReverse(node<T>* a)
{

  if(a == NULL)
    return;
  else
    {
      printAllReverse(a -> next);// Calls itself
      cout << a -> elem; //Display
    }
}
//purpose: Will add to the front of the queue
//Algorthm: checks isEmpty and if it is it will creat a new node so that we can add to the f\//ront else a we make front point and also make another node so we can add to the front
  //parameters: input
template <class T>
void LL<T>::addFront(T input)
{
  if(isEmpty())
    {
      front = new node<T>;//makes a new node because the queue is empty
      rear = front;// makes rear = to the front
      rear -> next = NULL;
      rear -> elem = input;
      count++;
    }
  else
    {
      node<T>* p = front;// if the queue is not empty then will add to the front
      front = new node<T>;
      front -> elem = input;
      front -> next = p;
      count++;
    }

}
//Purpose: to delete from the rear
//Algorthm: Checks to see if it is empty. if count = 1 then the front will be deleted. Else \/we make a new node* that isnt the rear so that we can delete the rear and then the new rear \
  //is the node we made.
  //parameters: none
template <class T>
T LL<T>::deleteRear()
{
  T t;

  if(count == 0)// if the queue is empty there is nothing to delete
    throw Underflow();
  else if(count == 1)//if there is one thing then we just delete the front sine the front an     \//d rear are the same
    {
  t = deleteFront();
    }
  else
    {
      t = rear -> elem;
      node<T>* v;
      v = front;
      while(v -> next != rear)
	{
	  v = v -> next;//point to node before the last so that when the rear is delted it\
	   	            // becomes the new rear
	    }
      delete rear;
      rear = v;
      rear -> next = NULL;
      count--;
    }

  return t;
}
//Purpose: to delete a node
//Algorithm: Check is empty then if the element is in the linked list it will be deleted
//if the front element = the inputed element it will delete the front else if del != Null an\d del doesn't equal the element the del will move to next node if it reaches Null without finding the lement it will return else if del is equal to rear then rear will become the p[rvios node and del will be deleted and then it will decrement
//Parameters:Luck input
//How to call: deleteNode(input)
template <class T>
void LL<T>::deleteNode(T input)
{
  // check if its empty
  if(isEmpty())
    return;
  else
    {
      // deleteFront if the fron element is equal to the inputed element
      if(front -> elem == input)
        deleteFront();
      else
        {
          node<T>* pre;
          node<T>* del;
          for( pre = front, del = front ->next; del != NULL && del -> elem != input; pre = del, del = del -> next);

          if(del != NULL)
            pre -> next = del -> next;
          else if(del == NULL)
            return;
          else if(del == rear)
	    rear = pre;
          delete del;
          count --;
        }
    }
}
//Purpose: will put the elements in ascending order
//algorthm:if its empty or the input is less than front element then the inputed element i\
//s added to the front else p is used to put the element that is less than the inputed eleme\
//nt \
// in front and then it will increment
//Parameters:Luck input
//How to call: addInOrderAscend(input)
template <class T>
void LL<T>::addInOrderAscend(T input)
{
  if(count == 0)
    {//addFront if there is nothing there
      addFront(input);
    }
  else if(input < front -> elem)
    {
      //addfront if the input is less than the front element
      addFront(input);
    }
  else
    {
      node<T>* p = front;
      while(p -> next != NULL && p -> next -> elem < input)
        p = p -> next;
      node<T>* a = new node<T>;
      a -> next = p -> next;
      p -> next = a;
      a -> elem = input;
      count ++;

    }
}
//Purpose: To delete multiple of the same node
//Algorthm: check to see if the linked list is empty if not it will go throuh the list unt\
//ill the element we want is deleted and will go through the entire list to get rid of multi\\
//ples of that element
//Parameters:Luck input
//How to call: deleteNodes(input)
template <class T>
void LL<T>::deleteNodes(T input)
{
  //check to see if its empty
  if(isEmpty())
    return;
  else
    {
      node<T>* del;
      node<T>* pre;
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
//lement is added to the front else P is used to put the element that is greater than the in\
//putted element in front and increment.
//Parameters:Luck input
//How to call: addInOrderDescend(input)
template <class T>
void LL<T>::addInOrderDescend(T input)
{
  if(count == 0)
    {//if nothing is there then addFront
      addFront(input);
    }
  else if(input > front -> elem)
    { //addFront if the inputted element is greatewr than the front element
      addFront(input);
    }
  else
    {//go through list and move the largest elements to the front
      node<T>* p = front;
      while(p -> next != NULL && p -> next -> elem >= input)
        p = p -> next;
      node<T>* a = new node<T>;
      a -> next = p -> next;
      p -> next = a;
      a -> elem = input;
      count ++;

    }
}
//Purpose: will search for an element
//Algorthm: if a pointer isn't null then it will go throught the linked list until it is e\
//qual to the element and returns true if found else it returns false
//Parameters:Luck input
//How to call: search(input)
template <class T>
bool LL<T>::search(T input)
{
  int comp = 0;
  if(isEmpty())
    return false;
  else
    {
      node<T>* a = front;
      //goes throught the whole linked list
      for(a; a != NULL; a = a -> next)
        {
          comp ++;
          if(a -> elem == input)// if the element is found return true
            {
	      // cout << comp << " times compared: " << endl;
	      return true;
            }
        }
      //cout << comp << " times compared: " << endl;
      return false;// if not found return false
    }
}


