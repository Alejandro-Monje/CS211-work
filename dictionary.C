//=====================================================//
//Name: Alejandro Monje//
//Date: 4/21/16//
//lab: Dictionary.C//
//Purpose: to organize the words in the text files based on the letters they start with //
//=====================================================//
#include <iostream>
#include <fstream>
using namespace std;
#include "LL_t.h"
void buildLL(LL<string>& Mt);
void removeBadWords(LL<string>& Mt);
void outputFile(LL<string>& Mt);
int main()
{
  LL<string> w;
  buildLL(w);
  removeBadWords(w);
  outputFile(w);
  return 0;
}
//Purpose: to get words out of the essay.txt and make a linked list, get rid of non alphabetics and also lowercase the words
//Algorthm: open the txt file get the words and check to see if they are alphabetic and lowe//r case aswell as make the linked list
//Parameters: LL& Mt
//how to call: void buildLL(LL& Mt)
void buildLL(LL<string>& Mt)
{
  ifstream infile;
  string op;
 
  infile.open("essay.txt");
  infile >> op;//gets words from essay.txt
  while(infile)
    {
      for(int i = 0; i < op.length(); i++)
	{
	  if(!isalpha(op[i]))//if not an alphabetic letter get rid of it
	    {
	      op.erase(op.begin() + i);
		}
	  else if(isalpha(op[i]))//if its an alphabetic letter make it lowercase
	    {
	      op[i] = tolower(op[i]);
	    }
	}
      if(!Mt.search(op))
        Mt.addInOrderAscend(op);
      infile >> op;
    }
  infile.close();;
}
//Purpose: to get rid of the bad words
//algorthm: gets the bad words from bad.txt and then search for those words 
//Parameters: LL& Mt
//How to call removeBadWords(LL& Mt)
void removeBadWords(LL<string>& Mt)
{
  string badWords;
  ifstream infile;
  infile.open("bad.txt");
  infile >> badWords;//gets the bad words from bad.txt

  while(infile)
    {
      while(Mt.search(badWords))//search the text file for all the bad words
        Mt.deleteNode(badWords);//will delete the bad words
      infile >> badWords;
    }
  infile.close();
}
//Purpose: To put the words in the correct place based on the words
//Algorthm: will get words that match up with the same letters and the close in while loop a//nd open the next .txt
//Parameters: LL& Mt
//how to call outputFile(LL& Mt)
void outputFile(LL<string>& Mt)
{
  string firstword;
  string secondword;
  ofstream g;

  firstword = Mt.deleteFront();

  string fileName = "./dictionary/?.txt";
  fileName[13] = toupper(firstword[0]); //Replacing ? with T
  g.open(fileName.c_str()); //opens T.txt in the “dictionary” directory under the current di//rectory.
  g << "" << firstword << " ";
  
  while(!Mt.isEmpty())
    {
  secondword = Mt.deleteFront();
  if(firstword[0] != secondword[0])
    {
      g.close();
      string fileName = "./dictionary/?.txt";
      fileName[13] = toupper(secondword[0]); //Replacing ? with T
      g.open(fileName.c_str());//opens T.txt in the “dictionary” directory under the current //directory.

    }
  g << "" << secondword << " ";
  firstword = secondword;
    }
  g.close();
}
