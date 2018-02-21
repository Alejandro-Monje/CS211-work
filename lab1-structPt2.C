#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

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
char getLetter(string msg);
char getResponse(string msg);
char getGender(string msg);
int getNumberInRange(int low, int high, string msg);
//If you want to change the maximum number of students, change the number in on\e place.
  const int MAX = 20;

int main()
{
  //delare an array of students with size MAX.
  student ar[MAX];
  int look, i, low, high;
  int amount; //the number of students
  char ans;  
  //call the getStuData function to fill the array with students' information
 amount = getStuData(ar);

 if(amount == 0)
   cout << "No students were entered " << endl;
 else
   {
  //The id the user is looking for
  cout << "Enter the id you are looking for: ";
  cin >> look;
     i = findID(ar, amount, look);
     if(!look)
       {
       cout << "No student with id " << look << " was found" << endl;
       }
       displayAll(ar, amount);

       findLowHigh(ar, amount, low, high);
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
      ar[amount].id = getNumberInRange(0, 100, "\tInvalid. Enter a score between 0 and 100 only: ");
      cout << "Enter the student name " << endl;
      cin >> ar[amount].name;
      cout << "Enter the student gender(m or f) " << endl;
      ar[amount].gender = getGender("Invalid response: only enter m of f: \n");
      cout << "Enter the student major " << endl;
      cin >> ar[amount].major;
      cout << "Enter the student age " << endl;
      ar[amount].age = getNumberInRange(0, 100, "\tInvalid. Enter a score between 0 and 100 only: ");
      cout << "Is there another student? Y or N" << endl;
      ans  = getResponse("Invalid response: only enter y or n: \n");
      amount++;
  if(amount == MAX)
        {
	  cout << "Array is full " << endl;
	}
    }
  if(amount < MAX)
    {
      student Default = {0, " ", ' ', " ", 999}; //defalut values

      for(int i = amount; i < MAX; i++)
	{
	  ar[i] = Default;
	}
    }
      return amount;
}
  //Find a student with that id and display the information about that student. If no student has the id, show an appropriate message.
int findID(student ar[], int amount, int look)
{
    int i;
      for(i = 0; i < MAX; i++)
	{
	  if(ar[i].id == look)
	    {
	      return i;
	    }
	}
      return -1;
}
    //find the youngest and oldest ages by calling findYoungOld and output those ages
  //return the number of students
  // }

  /* This function searches through the array to find the student with the id the\
 user is looking for.
   The user is asked to enter the id she is looking for in the main.
   Return the index or -1 if not found. */
    //}

    /*This function will be passed one student struct and display all the informati\
      on (name, gender, major and age) about that student.*/
void displayStu(student s)
{
  cout << left << setw(10) <<s.id << setw(10) << s.name << setw(10) << s.gender << setw(10) << s.major << setw(10) << s.age << endl;
}    

void displayAll(student ar[], int amount)
{
  cout << left << setw(10) << "Id " << setw(10) << "Name " << setw(10) << "Gender " << setw(10) << "Major " << setw(10) << "Age " << endl;
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
    cout << "The lowest age is " << low << endl;
    cout << "The oldest age is " << high << endl;
}

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
  bool nonNum; //set to true if the user's input contains a non-digit character
  bool invalid;
  cin >> input;
 do
   {

     //reset something at the beginning of each loop
     nonNum = false;
     //check each character in "input" and if a non-digit character is found, set "nonNumber" to true
     for(int i = 0; i < input.length(); i++)
       {
         if(!isdigit(input[i]))
	   nonNum = true;

       }
     //if one of the following 3 conditions is true, "input" is invalid, then .invalid. is set to true. If all the conditions
     //fail, .input. is valid, then .invalid. is set to false.
     // 1. "nonNumber" is true ("input" contains a non-digit character.) e.g. 1@0
     // 2. the number is less than the bottom boundary. e.g. -1 (if low is 0)
     // 3. the number is larger than the top boundary. e.g. 101 (if high is 100)
     nonNum = atoi(input.c_str()) <= low || atoi(input.c_str()) >= high || nonNum;
     //if .invalid. is true, ask for a new input
     if(nonNum) //same as invalid == true
       {
         cout << msg;
         cin >> input;
       }
   }while(invalid);
 //returning a valid integer between low and high
 return atoi(input.c_str());
}
