//Name: Alejandro Monje
//Date:2/20/16

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;
#include "price.h"

class Student
{
 private:
  static int id;
  static int numStu;
  int stId;
  string fName;
  string lName;
  char gender;
  Price balance;
  vector<int> coVec;

 public:
  Student();
  Student(string f, string l, char g);
  bool addCourse(int crn);
  bool dropCourse(int crn);
  string getFirstName() const;
  string getLastName() const;
  char getGender() const;
  int getId() const;
  static int getNumStu(); //This function returns the static data member 
  int getDollar() const;
  int getCent() const;
  vector<int> getCourses() const;
  void chargeFee(int d, int c);
  void reduceFee(int d, int c);
};

#endif
