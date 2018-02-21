//***************************************************************************//
//Name: Alejandro Monje
//Date: 2/28/2016
//cs 211 lab Stack.C HW#3
// Purpose: This program will provide the functions to check is stack is full and empty, also it has the functions for displaying, clearing, errors, pushing, popping, and checking the top element.
//**************************************************************************//
#include <iostream>
using namespace std;
#include "stack.h" //stack.h holds the prototypes

Stack::Stack()// constructor
{
  top = -1; //shows that there are no elements to begin with
}
bool Stack::isEmpty() // Checks to see if the stack is empty
{
  if (top == -1)
    return true;  // returns true if the stack is empty
  else
    return false; // else it returns flase meaning there is something in the stack
}
bool Stack::isFull() // Checks to see if the stack is full
{
  if(top == MAX - 1) // max - 1 because we start at 0 not 1
    return true;    // returns true if stack is full
  else
    return false;  // else returns false meaning there is still space
}
void Stack::push(luck elem) // will add an element to the stack
{
  if(isFull())
    stackError("stack is full"); // first checks to see if the stack is full
  else
    {
      arr[++top] = elem; // if the tack isn't full it will add the new element to the stack 
    }
}
luck Stack::pop() // will remove one element from the top of the stack if not empty
{
  if(isEmpty())
    stackError("stack is empty"); // checks to see if the stack is empty
  else
    return arr[top--]; // if it isn't empty it will remove the top element
}
luck Stack::topElem()  // will check to see what is at the top
{
  if(isEmpty())
    stackError("stack is empty"); // first it will check if the stack is empty 
  else
    return arr[top];  // if it isn't empty it will return what is at the top
}
void Stack::stackError(string msg) // will display an error message
{
  cout << msg << endl;
  exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors
}
void Stack::view() // will display the contents of the stack
{
  for(int i = top; i > -1; i--) // starts at the top and decrements untill it reaches the bottom of the stack
    cout << arr[i] << endl; //will display it at each index
}
void Stack::clear()// will clear the stack
{
  while(!isEmpty()) // while it isnt empty it will pop everything until it is empty
    pop();
}
