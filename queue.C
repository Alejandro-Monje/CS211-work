//****************************************************************************
//CS211
//Lab 8, Assignment 4
//queue.C
//Name: Alejandro Monje
//Date: 3/16/16
//Purpose: holds the function to use in client files
//////////
#include <iostream>
using namespace std;
#include "queue.h" //queue.h holds the prototypes

Queue::Queue()// constructor
{
  front = 0; //shows that there are no elements to begin with
  rear = -1;
  count = 0;
}
bool Queue::isEmpty() // Checks to see if the queue is empty
{
  if(count == 0)
    return true;  // returns true if the queue  is empty
  else
    return false;// else it returns flase meaning there is something in the queue 
}
bool Queue::isFull() // Checks to see if the queue  is full
{
  if(rear == QUEUE_SIZE)
    return true;    // returns true if queue  is full
  else
    return false;  // else returns false meaning there is still space 
}
void Queue::add(luck elem) // will add an element to the queue 
{
  if(isFull())
    {
      queueError("queue is empty"); // first it will check if the queue  is empty
    }
  else
    {
      rear = (rear + 1)% QUEUE_SIZE;
      arr[rear] = elem;
      count++;
    
    }
}
luck Queue::remove() // will remove one element from the top of the queue  if not empty
{
  if(isEmpty())
    queueError("queue is empty"); // first it will check if the queue  is empty
  else
    {
      luck e = arr[front];
      front = (front + 1) % QUEUE_SIZE;
      count--;
      return e;
    }
}
luck Queue::topElem()  // will check to see what is at the top
{
  if(isEmpty())
    queueError("Queue is empty");
  else
  return arr[front];
}
void Queue::queueError(string msg) // will display an error message
{
  cout << msg << endl;
  exit(1); //ends the program. 1 is returned to the operating system.
  //0 = end with no errors, 1 = end with errors
 
}
//void Queue::view() // will display the contents of the queue 
//{
// int d = (rear + 1) % QUEUE_SIZE;
// int b = (front + 1) % QUEUE_SIZE;
// if(isEmpty())
//   {
//    queueError("Queue is empty");
//  }
//else
//  {
//    do
//{
//  luck e = arr[front];
//  cout << e;
//  cout << " " << endl;
//  front = (front + 1) % QUEUE_SIZE;
//}while(front != d);
//  }
//}
int Queue::getSize()
{
  return count;
}
void Queue::goToBack()
{ 
if(isEmpty())
    queueError("Queue is empty");
  else
  add(remove());
}
