//****************************************************************************
//CS211
//Lab 8, Assignment 4
//queue.h
//Name: Alejandro Monje
//Date: 3/16/16
//Purpose: to make the prototypes for the queue.C file
//////////

#include <string>
using namespace std;
#ifndef QUEUE_H
#define QUEUE_H
const int QUEUE_SIZE = 10;
enum op {ADD, SUB, MUL, DIV};
struct expr
{
  int oprd1;
  op oprt;
  int oprd2;
};

typedef expr luck; //the type defenition makes it easier to change between data types like string or int.
class Queue
{
 private:
  luck arr[QUEUE_SIZE];
  int count;
  int front;
  int rear;
  void queueError(string msg);

 public:
  Queue(); //Constructor
  bool isEmpty (); //checks to see if the stack is empty
  bool isFull(); //checks to see if the stack is full
  void add(luck elem); //pushes a new element into the stack
  //if it is full there will be an error
  luck remove(); //pops an element out of the stack
  //if empty there will be an error
  luck topElem();
  // checks to see what is at the top of the stack
  //  void view();
  // view is commented out because you must change typedef to char for running queue client and expr for game.c
  //it will display what in the stack
  int getSize();
  void goToBack();
};
#endif



