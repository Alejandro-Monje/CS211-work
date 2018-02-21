//*****************************************************************//
//Name: Alejandro Monje
//Date: 3/1/2016
//CS 211 lab postfix.C HW#3
//Purpose: to use a stack to calculate postfix operations
//****************************************************************//
#include <iostream>  
using namespace std;
#include "stack.h"

bool isOperand(char ch);//return true if ch is an operand 
int charToInt(char ch);//convert a character to integer 
bool isOperator(char ch);//return true if it is an operator 
int doMath(int opr1, char opt, int opr2);//returns the answer
int main()
{
  int tot = 0; // intialize tot to zero
  Stack myStack; // created a new stack called myStack
  bool eror = false;
  string expr; //made a srting to get expression from the user
  int i = 0;
  cout << "Enter your expression:";
  cin >> expr; //retrieves the users expression
  do  // I used a do while loop because i couldn't make the while loop work
    {
      char currItem = expr[i];
      if(isOperand(currItem))
        {
	  int num = charToInt(currItem); // gets the current item
	  myStack.push(num);     // pushes it onto the stack
	}
      else if(isOperator(currItem))
	{
	  int a = myStack.pop(); // pops the opreand out of the stack
	  int b = myStack.pop(); // pops the other opreand out
	  tot = doMath(b, currItem, a); // uses both operands and the operator to calculate the answer
	  myStack.push(tot);
	}
      else
	eror = true; //if it returns true then there is an error
      i++;
    }while(!myStack.isEmpty() && !eror); // gets out of the while loop if the conditions are met
  int l = myStack.pop(); //l holds the answer 
  if(!myStack.isEmpty())
    cout << "Error invalid expression:  " << endl; // checks to see if the stack is not empty because there shouldn't be anything left inside the stack
  else
    cout << "The answer is " << l << endl;  // displays the answer
  
  return 0;
}

bool isOperand(char ch)
{
  if( ch >= '0' && ch <= '9')
    return true; // returns true if ch is an operand
  else
    return false; // else it returns false
}

int charToInt(char ch) // will convert a character to an interger
{
    return ch - 48;
}
bool isOperator(char ch)
{
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/') //ch is an operator
    return true; //returns true if it is
  else //ch is not an operator
    return false; //returns false if it isn't
}

int doMath(int opr1, char opt, int opr2) // uses the operands and operator to calculate an answer
{
  int ans;
         switch(opt)
	   {
	   case '+': ans = opr1 + opr2; // uses + to add
	     break;
	   case '-': ans = opr1 - opr2; // uses - to subtract
	     break;
	   case '/': ans = opr1 / opr2; // uses / to divide
	     break;
	   case '*': ans = opr1 * opr2; // uses * to multiply
	     break;
	   }
	 return ans; // returns the answer
}
