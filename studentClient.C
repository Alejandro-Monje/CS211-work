//Name: Alejandro Monje
//Date:2/22/16

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>  //include vector.h
using namespace std;
#include "student.h"
#include "inputCheck.h"

void showMenu();
void addStudentsFromFile(vector<Student>& o);
void addOneStudent(vector<Student>& o);
void printAllStudents(vector<Student>& o);
void addCourseToStudent(vector<Student>& o);
void dropCourseFromStudent(vector<Student>& o);

int main()
{
  cout << "\n *** TEST: the number of students at the beginning is " << Student::getNumStu() << endl;
 
  vector<Student> o; //declare a vector of students  
  int choice;

  do
  {
    showMenu();
    cout << "Enter your choice ----> ";
    choice = getNumberInRange(1, 6, "Invalid choice. Enter 1 through 6: ");

    switch(choice)
      {
      case 1:
	  addStudentsFromFile(o);
	  break;
      case 2:
          addOneStudent(o);
	  break;
      case 3:
	  printAllStudents(o);
	   cout << "\n *** TEST: the number of students is " << Student::getNumStu() << endl;
	break;
      case 4:
	addCourseToStudent(o);
	break;
      case 5:
	dropCourseFromStudent(o);
	break;
      case 6:
	cout << "Ending the program ..............." << endl;
      }
  }while(choice < 6);


  cout << "\n *** TEST: the number of students at the end is " << Student::getNumStu() << endl;

  return 0;
}

 void showMenu()
 {
   cout << "\n*****************************************************************" << endl;
   cout << "1: Add students from a file" << endl;
   cout << "2: Add one student" << endl;
   cout << "3: Print all students" << endl;
   cout << "4: Add a course to a student" << endl;
   cout << "5: drop a course from a student" << endl;
   cout << "6: End the program" << endl;
 }

//This function adds students from an input file
//e.g. for input file (for each student, first last gen)
//  Mike Smith M
//  Kathy Ross F
void addStudentsFromFile(vector<Student>& o)
{
  string fileName;

  cout << "Enter the file name: ";
  cin >> fileName;

  ifstream fin;
  fin.open(fileName.c_str()); //open the file

  if(!fin)
    {
      cout << fileName << " doesn't exist " << endl;
    }
  else//The file exists
    {
      string fn, ln;
      char gn;
   
      fin >> fn >> ln >> gn;//read the first student
      while(fin)//if reading was successful, enter the while
	{
	  Student h(fn, ln, gn);//create a new student with the data from input
	  o.push_back(h); //add it to the vector
	  fin >> fn >> ln >> gn; //read the next student
	}
    }
}

//This function adds one student to the vector.
void addOneStudent(vector<Student>& o)
{
      string fn, ln;
      char gn;

      cout << "Enter the student's first name: ";
      cin >>  fn;
      cout << "Enter the student's last name: ";
      cin >>  ln;
      cout << "Enter the student's gender: ";
      gn = getGender("Invalid input. Enter M or F: ");

      Student h(fn, ln, gn); //create a new student with the data from the user's input
      o.push_back(h); //add the new student to the vector
}
 
//Print the information about all the students
void printAllStudents(vector<Student>& o)
{
  //Show the labels
  cout << left << setw(10) << "Id" <<  setw(10) << "First" << setw(10) << "Last" << left << setw(10) << "Fee" << left << setw(10) << "Courses" << endl; 

  //Go through each student in the vector 

  for(int n = 0; n < o.size(); n++)
    {
      cout << left << setw(10) << o[n].getId() << setw(10) << o[n].getFirstName() << setw(10) << o[n].getLastName() << left << o[n].getDollar() << ".";

      //If the cent is less than 10, show a 0 first.
      //e.g. cent = 3, 03 will be shown.
      if(o[n].getCent() < 10)
	{
	cout << "0";
	}
        cout << o[n].getCent();
      
      //show all courses the student is enrolled in
      cout << left << "  ";
      vector<int> co = o[n].getCourses(); //get the vector of courses for this student
      for(int c = 0; c < co.size(); c++)
	{
	  cout << left << setw(10) << co[c];
      
	}

      cout << endl;
    }
}

//Add a new course to a student.
//Charge $50.10 per course
void addCourseToStudent(vector<Student>& o)
{

  bool found = false;
  int t;
  cout << "Enter the student id: ";
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: ";
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");
  bool enter = false;
  for(int i = 0; i < o.size(); i++)  //Big section
    {
      if(o[i].getId() == id)
	{
	  found = true; 
          enter = o[i].addCourse(crn);
          t = i;
        }
    }
  if(!found)
    {
      cout << "Didn't find the student " << endl;
    }

  else if(!enter)
    {
    cout << "Student is already enrolled: " << endl;
    }
  else if(found)
	{
	  o[t].chargeFee(50, 10);
	cout << "Added a course: " << endl;
	}
	
}

//drop a course from a student
//reduct $50.10 from the student's balance
void dropCourseFromStudent(vector<Student>& o)
{ 
  int t;
  bool found;
  cout << "Enter the student id: " << endl;
  int id = getNumberInRange(1, 99999, "Invalid id. Enter the student id: ");
  cout << "Enter the CRN: " << endl;
  int crn = getNumberInRange(1, 99999, "Invalid CRN. Enter the CRN: ");
  bool last = false;
  for(int i = 0; i < o.size(); i++)  //Big section
    {  
     if(o[i].getId() == id)
       {
	 found = true; 
         last = o[i].dropCourse(crn);
	 t = i;
       } 
    }   
  if(!found)
    {
      cout << "Student was not found " << endl;
    }
  else if(!last)
    {
      cout << "Not enrolled in the class: " << endl;
    }
  else if(found)
    {
      o[t].reduceFee(50, 10);
      cout << "Dropped the course: " << endl;
    }
}
 


