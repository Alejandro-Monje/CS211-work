#include <iostream>
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

//If you want to change the maximum number of students, change the number in one place.
const int MAX = 20;

int main()
{
  //delare an array of students with size MAX.
  student ar[MAX];
  int look, i, low, high;
  int amount; //the number of students
  //call the getStuData function to fill the array with students' information 
  amount = getStuData(ar);
  //The id the user is looking for
  cout << "Enter the id you are looking for: ";
  cin >> look;
  
  i = findID(ar, amount, look);
  if(look)
  displayStu(ar[i]);
  else
     cout << "No student with id " << look << " was found" << endl;
  findLowHigh(ar, amount, low, high);
   return 0;
}
int getStuData(student ar[])
{
  cout << "Do you want the student information? Y or N " << endl;
    char ans;
   int  amount = 0;
    cin >> ans;
    
    while(ans == 'Y' || ans =='y')
      {
        cout << "Enter the student id " << endl;
        cin >> ar[amount].id;
	cout << "Enter the student name " << endl;
	cin >> ar[amount].name;
	cout << "Enter the student gender(m or f) " << endl;
	cin >> ar[amount].gender;
	cout << "Enter the student major " << endl;
	cin >> ar[amount].major;
	cout << "Enter the student age " << endl;
	cin >> ar[amount].age;
        cout << "Is there another student? Y or N" << endl;
        cin >> ans;
        amount++;
      }

    student Default = {0, " ", ' ', " ", 999}; //defalut values
      
    for(int i = amount; i < MAX; i++)                   
       {    
	 ar[i] = Default;
       }   
     
     return amount;
}
//Find a student with that id and display the information about that student. If no student has the id, show an appropriate message.
int findID(student ar[], int amount, int look)
{
  int i;
  for(i = 0; i < amount; i++)
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

/* This function searches through the array to find the student with the id the user is looking for.
   The user is asked to enter the id she is looking for in the main. 
   Return the index or -1 if not found. */  
//}

/*This function will be passed one student struct and display all the information (name, gender, major and age) about that student.*/
void displayStu(student s)
{
  cout << "Student id: " << s.id << endl;
  cout << "Student name: " << s.name << endl;
  cout << "Student gender: " << s.gender << endl;
  cout << "Student major: " << s.major << endl;
  cout << "Student age: " << s.age << endl;
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
