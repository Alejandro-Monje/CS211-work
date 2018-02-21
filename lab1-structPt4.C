//Purpose: To find the student whos id the user enters and display all the students entered//
//Name: Alejandro Monje//
//Date: 2/8/16  //
//User info: The user will enter the id, name gender, major, age for each student and also the specific id for one students information//

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include "inputCheck.h"
using namespace std;
struct student
{
  int id;
  string name;
  char gender;
  string major;
  int age;
};
int getStuData(student ar[]);
int findID(student ar[], int, int);
void displayStu(student s);
void findLowHigh(const student ar[], int, int&, int&);
void displayAll(student ar[], int amount);
const int MAX = 2;

int main()
{
  student ar[MAX];
  int look, fi, i, low, high;
  int amount; 
  char ans;
  amount = getStuData(ar);

  if(amount == 0)
    cout << "No students were entered " << endl;
  else
    {
      cout << "Enter the id you are looking for: ";
      cin >> look;
      fi = findID(ar, amount, look);
      if(fi == -1)
	{
	  cout << "No student with id " << look << " was found" << endl;
	}
      else
	{
      displayStu(ar[fi]);
	}
      findLowHigh(ar, amount, low, high);
      cout << "The lowest age is " << low << endl;
      cout << "The oldest age is " << high << endl;
      displayAll(ar, amount);
	
    }
  return 0;
}
int getStuData(student ar[])
{
  cout << "Do you want the student information? Y or N " << endl;
  char ans;
  int i = 0, amount = 0;
  ans  = getResponse("Invalid response: only enter y or n: \n");

  while((ans == 'Y' || ans =='y') && amount != MAX )
    {
      cout << "Enter the student id " << endl;
      ar[amount].id = getNumberInRange(0, 5001, "Invalid. Enter a number betwee\
n 1 and 9999 only: ");
      cin.ignore();
      cout << "Enter the student name " << endl;
      getline(cin, ar[amount].name);
      cout << "Enter the student gender(m or f) " << endl;
      ar[amount].gender = getGender("Invalid response: only enter m or f: \n");
      cin.ignore();
      cout << "Enter the student major " << endl;
      getline(cin,  ar[amount].major);
      cout << "Enter the student age " << endl;
      ar[amount].age = getNumberInRange(-1, 151, "Invalid. Enter a number betwe\
en 0 and 150 only: ");
      cout << "Is there another student? Y or N" << endl;
      ans  = getResponse("Invalid response: only enter y or n: \n");
      amount++;
      if((ans == 'Y' || ans =='y') && amount >= MAX)
        {
          cout << "Array is full " << endl;
        }
    }
  if(amount < MAX)
    {
      student Default = {0, " ", ' ', " ", 999};

      for(int i = amount; i < MAX; i++)
	{
          ar[i] = Default;
        }
    }
  return amount;
}
  int findID(student ar[], int amount, int look)
{
  int fi;
  for(fi = 0; fi < amount; fi++)
    {
      if(ar[fi].id == look)
	{
	  return fi;
	}
    }
  return -1;
}
void displayStu(student s)
{
  cout << left << setw(15) << s.id << setw(15) << s.name << setw(15) << s.gender\
       << setw(15) << s.major << setw(15) << s.age << endl;
}

void displayAll(student ar[], int amount)
{
  cout << left << setw(15) << "Id " << setw(15) << "Name " << setw(17) << "Gend\er " << setw(15) << "Major " << setw(15) << "Age " << endl;
  for(int i = 0; i < amount; i++)
    {
      displayStu(ar[i]);
    }
}
void findLowHigh(const student ar[], int amount, int& low, int& high)
{

  low = high = ar[0].age;
  for(int i = 1; i < amount; i++)
    {
      if(ar[i].age < low)
	low = ar[i].age;
      if(ar[i].age > high)
	high = ar[i].age;
    }
}
