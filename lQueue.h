//=====================================================//
//Name: Alejandro Monje//
//Date: 4/08/16//
//lab: lQueue.h//
//Purpose: will have the prototypes for all the functions//
//=====================================================//
#include <string>
using namespace std;
#ifndef LQUEUE_H
#define LQUEUE_H
typedef int luck; //the type defenition makes it easier to change between data \types like string or int.

struct node
{
  luck elem;
  node* next;
};
//Purpose: to create a class called lQueue
//algorithm: will hold the prototypes
//parameters: private and public
class lQueue
{
 private:
  int count;
  node* front;
  node* rear;
  void queueError(string msg);

 public:
  lQueue(); //Constructor
  ~lQueue();// Destructor
  bool isEmpty (); //checks to see if the stack is empty
  void addRear(luck elem); //adds a new element
  //if it is full there will be an error
  luck deleteFront(); //deletes an element
  //if empty there will be an error
  void view();//Will display the contents
  void printAllReverse();//will be used to reverse
  void printAllReverse(node* P);//will be used to reverse the linked list
};
#endif
