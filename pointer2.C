//=====================================================//
//Name: Alejandro Monje//
//Date: 4/08/16//
//lab: pointer lab//
//Purpose: make a program that will use pointers//
//=====================================================//
#include <iostream>
using namespace std;
int main()
{
  //Declare the data members
  int* pf1;
  int* pf2;
  pf1 = new int;//pf1 points to new int cell
  pf2 = new int;//pf2 points to new int cell
  *pf1 = 1;//pf1 points to 1
  *pf2 = 2;//pf2 points to 2

  cout << *pf1 << endl; //dislpays what pf1 is pointing to
  cout << *pf2 << endl; //dislpays what pf2 is pointing to

  delete pf2;//Deletes what pf2 was pointing to

  pf2 = pf1;//makes pf2 point to the same place pf1 points to
  cout << *pf2 << endl; // Displays 1
  delete pf1;// deletes what pf1 is pointing to
  pf1 = NULL;// makes pf1 point to null

  *pf2 = 3;// makes pf2 point to 3

  cout << *pf2 << endl;// displays 3
  return 0;
}
