#include <iostream>
#include "LL_t.h"
using namespace std;
void createLL(LL<int> &a, string s);//prototype for creatLL
bool palindrome(LL<int> &v, LL<int> &v2);//portotype fro palindrome

int main()
{
  LL<int> v, v2;
  string s;
  //ask the user to enter a string
  cout << "Enter a palindrome: " << endl;
  getline(cin, s);
  //will check if it is an alphabetic letter
  createLL(v, s);
  createLL(v2, s);
  //will check if it is a palirome
  if(palindrome(v, v2))
  cout << " !Its a palindrome!" << endl;
  else
    cout << "Not a palindrome" << endl;
  

  return 0;
}
//Purpose:will make a linked list for the palidrome
//Algorithm:Will check if what the user entered is alphabetical
//parameters: (LLh &a, string s)
void createLL(LL<int> &a, string s)
{
  for(int i = 0; i < s.length(); i++)
    {
      if(isalpha(s[i]))
	{
	  a.addRear(toupper(s[i]));
	}
    }
}
//Purpose:Will check if it is a palidrome or not
//Algorthm:While it isn't empty checks to see if the elements are the same or not
//Parameters:(LLh &v, LLh &v2)
bool palindrome(LL<int>  &v, LL<int>  &v2)
{
  while(!v.isEmpty())
    {
      if(v.deleteFront() != v2.deleteRear())
	return false;
    }
  return true;
}
