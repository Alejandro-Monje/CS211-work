//**************************************************************************//
//Name: Alejandro Monje
//Date: 3/3/2016
//cs 211 lab fibonacci.C HW#3
// Purpose: This program will compare the time it takes for the for loop to calculate the fibonacci number to how long it takes the recursive solution to calculate the fibonacci number.//
//*************************************************************************//

#include <time.h>
#include <iostream>
clock_t start, start2, end, end2; // I made to starts and to ends. one for the non recursive and one for the recursive

using namespace std;
int fib(int pos); // the prototype for the recursive solution
int main()
{
  int pos; // for the postion we are looking for
  int fibnum = 0; 
cout << "Enter a position: ";
 cin >> pos;   // gets the position from the user
int firstN = 0, secondN = 1;

//start time
start = clock(); // clock() returns the number of clock ticks elapsed since the beginning of the program execution
//======================================================================//
//The non recrusive solution
 if(pos == 0)
   {
     secondN = 0; // if the user enters 0 for the position then we want 0 to be the answer 
   }
 else
   {
     for(int i = 0; i < pos - 1; i++) //goes through the loop until it reaches one less than the position
  {
    fibnum = firstN + secondN;// This is how the fibonacci is calulted the two previos numbers added together
    firstN = secondN; // after that the first number should be what the second number was
    secondN = fibnum; // the second number is now the fibnum we calulated
    // the loop continues untill the for loop ends
  } 
   }        
end = clock(); //stop timing
 cout << "Time for non recursive: " << endl;
cout << "Elapsed time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
// CLOCKS_PER_SEC is the number of clock ticks per second
cout << "Fibonnaci number at position " << pos << " is " << secondN  << endl;
//=====================================================================//
//This if for the recursive now
 cout << "----------------------------------" << endl;
   cout << "Time for recursive: " << endl;


   start2 = clock();// start of the clock again
   int Num = fib(pos);// calls the recursive function
   end2 = clock();// end of the clock again

cout << "Elapsed time: " << (end2 - start2) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
// CLOCKS_PER_SEC is the number of clock ticks per second
 cout << "Fibonnaci number at position " << pos << " is " << Num << endl;
return 0;
}

int fib(int pos)
{
  //This if the base case
  if(pos <= 1) //position is 0 or 1 
    return pos;
  else
    return fib(pos -2) + fib(pos - 1);// the function calls it self and calculates the fibnumber
}





