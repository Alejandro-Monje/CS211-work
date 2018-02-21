//*************************************************************************//
//Name: Alejandro Monje
//Date: 2/28/2016
//cs 211 lab Stack.h HW#3
//Purpose:Holds the prototypes for the stack.C file
//***********************************************************************//
#include <string>
using namespace std;
#ifndef STACK_H
#define STACK_H
const int MAX = 5;
typedef int luck; //the type defenition makes it easier to change between data types like string or int. 
class Stack
{
 private:
  luck arr[MAX];
  int top; 

 public: 
  Stack(); //Constructor
  bool isEmpty (); //checks to see if the stack is empty
  bool isFull(); //checks to see if the stack is full
  void push(luck elem); //pushes a new element into the stack
  //if it is full there will be an error
  luck pop(); //pops an element out of the stack 
  //if empty there will be an error
  luck topElem();
  // checks to see what is at the top of the stack
  void view();
  //it will display what in the stack
  void clear();
  //This will clear the stack
  void stackError(string msg);
  //Will provide the errors
};
#endif
