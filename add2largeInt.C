//=====================================================//
//Name: Alejandro Monje//
//Date: 4/08/16//
//lab: add2largeint.C//
//Purpose: make a program that will be used to test the functions we made
//=====================================================//
#include<iostream>
using namespace std;
#include"LL_t.h"

//make the prototypes
void MakeReverse(LL<int> &l, string t);
void addlls(LL<int> &l2, LL<int> &l1, LL<int>& total); 

int main()
{
  // Declare data members
  string n1;
  string n2;
  // ask the user to enter a number
  cout << "Please enter a positive number: " << endl;
  cin >> n1; //Gets the number from the user
  // ask the user to enter a number
  cout << "Please enter another positive number: " << endl;
  cin >> n2;//Gets the number from the user
  
  LL<int> total;
  LL<int> l1;//Creates a new object l1
  MakeReverse(l1, n1);// calls makereverse to reverse the string
  LL<int> l2;//Creates a new object l2
  MakeReverse(l2, n2);// calls makereverse to reverse the string
  cout << endl;
  l1.displayAll(); //displays the reversed contents of the first number entered
  cout << "+";
  l2.displayAll();//displays the reversed contents of the second number entered
  cout << "=";// makes a new line
  addlls(l1, l2, total);
  total.displayAll();

  cout << endl;

  cout << n1 << "+" << n2 << "=";
  total.printAllReverse();
  cout << endl;
    return 0;

}
//Purpose: to reverse the number entered
//Algorthm: will get the ascii value and add the number to rear
//Parameters:(lQueue &l, string t)
void MakeReverse(LL<int> &l, string t)
{  
  char w;
  int  a;
    int i = t.length() - 1;
    while(i != -1)
      {
	w = t[i];
        a = w - 48;// will get the ascii value
	l.addRear(a);
	 i--;
      }
}
void addlls(LL<int> &l2, LL<int> &l1, LL<int> &total)
{
  int final = 0;  
  int k = 0;
  int c;
  int d;
  while(!l2.isEmpty() || !l1.isEmpty() || k == 1)// while not empty
  {
    if(l2.isEmpty())//if empty set c = 0;
      c = 0;
    else
      c = l2.deleteFront();// else delete the front element
    if(l1.isEmpty())// if empty set d = 0
      d = 0;
    else
      d = l1.deleteFront();//else delete the front element

    final = c + d + k; 
    k = 0;
    if(final > 9)
      {
	final = final - 10;
        k = 1;
      }
    total.addRear(final);
  }
}
