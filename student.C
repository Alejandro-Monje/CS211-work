//Name: Alejandro Monje
//Date:2/21/16

#include "student.h"
int  Student::id = 100; //initialize id to 100
int Student::numStu = 0; //initialize numStu to 0

Student::Student()
{
  numStu++; //one more student. increment numStu
    stId = id; //set stId of the new student to the value of the static member "id"
  fName = "unknown";
  lName = "unknown";
  gender = 'X';
  id++; //increment id for stId of the next student
}

Student::Student(string f, string l, char g)
{
  numStu++; //one more student. increment numStu
  stId = id; //set stId of the new student to the value of the static member "id"
  fName = f;//initialize the data members
  lName = l;
  gender = g;
  id++; //increment id for stId of the next student
}

//returns true if crn is added to the vector
//returns false if crn already exists. Do not add the same crn into the vector
bool Student::addCourse(int crn)
{
  //If crn already exists in the vector, don't add it
  for(int i = 0; i < coVec.size(); i++)
    if( coVec[i] == crn)
      return false;

  //If the vector doesn't have the same crn, add it to the vector
  coVec.push_back(crn);
  return true;
}

//return true if the crn is dropped from vector
//return false if the crn is not found in vector
bool Student::dropCourse(int crn)
{
  for(int i = 0; i < coVec.size(); i++)
  {
    if(coVec[i] == crn)
      {
	coVec.erase(coVec.begin() + i);
	return true;
      }
  }

  return false;
}

string Student::getFirstName() const
{
  return fName;
}

string Student::getLastName() const
{
  return lName;
}

char Student::getGender() const
{
  return gender;
}

int Student::getId() const
{
  return stId;
}

int Student::getNumStu()
{
  return numStu;
}

int Student::getDollar() const
{
  return balance.getDollar();
}

int Student::getCent() const
{
  return balance.getCent();
}

//Returns the vector of course the student is enrolled in

vector<int> Student::getCourses() const
{
  return coVec;
}

//$d.c is added to the student's fee
void Student::chargeFee(int d, int c)
{
  Price p(d, c);

  balance = balance + p;
}

//The student's fee is reduced by $d.c
void Student::reduceFee(int d, int c)
{
  Price p(d, c);

  balance = balance - p;

}

