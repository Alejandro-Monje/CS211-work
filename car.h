//Name: Alejandro Monje
//Date:2/16/16
#include <string>
using namespace std;

const int MAX = 10;

class Car
{
 private:

  string make;
  string model;
  int year;
  string color;
  int miles;
  int x;
  int y;
  
 public:
Car(string, string, int, string, int, int, int);
 string getMake() const;
 string getModel() const;
 int getYear() const;
 string getColor() const;
 void chColor(string rePaint);
 int getMiles() const;
 int goFowards(int block);
 int goBackwards(int block);
 int goLeft(int block);
 int goRight(int block);
 void View(const Car& c);
};


