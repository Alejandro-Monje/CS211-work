#include <iostream>
using namespace std;
#include "stack.h"
void pushPerson(Stack& myStack, string a);
void popPerson(Stack& myStack);

int main()
{
  Stack myStack;

  
  
  if(myStack.isEmpty())
    {
      cout << "stack is empty: " << endl;
    }
      pushPerson(myStack,"mike");
      pushPerson(myStack,"Kathy");
      cout << myStack.topElem() << " is at the top:" << endl;
      pushPerson(myStack,"Dave");
      pushPerson(myStack,"Alice");
      pushPerson(myStack,"Tom");
  if(myStack.isFull())
    {
     cout << "Stack is full: " << endl;
    }
      myStack.view();
      pushPerson(myStack,"Meg");
      myStack.pop();
      cout << myStack.topElem() << " is at the top:" << endl;
      myStack.clear();
      if(myStack.isEmpty())
    {      
    cout << "stack is empty: " << endl;
    }
  return 0;
}

void pushPerson(Stack& myStack, string a)
{
  if(myStack.isFull())
    cout << "We cannot add any more students. the stack is full: " << endl;
  else
    myStack.push(a);
}

void popPerson(Stack& myStack)
{
  if(myStack.isEmpty())
    cout << "We cannot pop any more students. SWtack is empty: " << endl;
  else
    myStack.pop();
}
