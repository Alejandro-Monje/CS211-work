#include <iostream>
#include <cctype>
using namespace std;

char getLetter(string msg);
char getResponse(string msg);
char getGender(string msg);
int getNumberInRange(int low, int high, string msg);

char getLetter(string msg)
{
  string input;
  cin >> input;
  while(input.length() != 1 || !isalpha(input[0]))
    {
      cout << msg;
      cin >> input;
    }
  return input[0];
}
char getResponse(string msg)
{
  char ch;
  ch = getLetter(msg);
  while(toupper(ch) != 'Y' && toupper(ch) != 'N')
    {
      cout << msg;
      ch = getLetter(msg);
    }
  return toupper(ch);
}
char getGender(string msg)
{
  char ch;
  ch = getLetter(msg);
  while(toupper(ch) != 'F' && toupper(ch) != 'M')
    {
      cout << msg;
      ch = getLetter(msg);
    }
  return toupper(ch);
}
int getNumberInRange(int low, int high, string msg)
{
  string input;
  bool nonNum; 
  bool invalid;
  cin >> input;
 do
   {
     nonNum = false;
     for(int i = 0; i < input.length(); i++)
       {
         if(!isdigit(input[i]))
	   {
           nonNum = true;
	   }
       }
     invalid = atoi(input.c_str()) < low || atoi(input.c_str()) > high || nonNum;
     if(invalid) 
       {
         cout << msg;
         cin >> input;
       }
   }while(invalid);
 return atoi(input.c_str());
}

