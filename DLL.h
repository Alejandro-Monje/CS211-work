//=====================================================//
//Name: Alejandro Monje//
//Date: 5/12/16//
//lab: DLL.h//
//Purpose: will have the prototypes for all the functions//
//=====================================================//
#include <string>
using namespace std;
#ifndef DLL_H
#define DLL_H
typedef int luck; //int for test one and test2 and string for dictionary
struct node
{
  luck elem;
  node* next;
  node* prev;
};
//Purpose: to create a class called lQueue
//algorithm: will hold the prototypes
//parameters: private and public
class DLL
{
 private:
  int count;
  node* front;
  node* rear;
  node* prev;
  //Purpose: Will display the error
  //Algorthm: cout a message and has an emergency exit
  //Parameters: string msg
  //How to call: 
  void DLLError(string msg);

 public:
  //Purpose: will be used every time a new object is created
  //Algorithm:front and rear are set to null and count set to 0
  //Parameters: none
  //How to call: will be used wheever an object is made.
  DLL(); //Constructor
  //Purpose: will be used every time an object is deleted or goes out of the scope
  //Algorthm:while the queue isn't empty it will delete
  //parameters: none
  //how to call: will be used whenever an object is deleted or leaves the scope
  ~DLL();// Destructor
  //Purpose: finds out if the queie is empty
  //Algorthm: returns true if rear and front are both null because it is empty and
  //returns false if it isn't empty
  //Parameters: none
  //how to call: isEmpty();
  bool isEmpty (); //checks to see if the stack is empty
  //Purpose: adds an element to the rear of the queue
  //Algorthm: if count is 0 it will majke front and rear equal and make a new node
  //else it will make the rear point to a new cell
  //Parameters: luck input
  //How to call: func name an element passed to it
  void addRear(luck input); //adds a new element
  //if it is full there will be an error
  //Purpose: will delete an element from the front of the queue
  //Algorthm: will check to see if it empty and if not empty it will delete an element f//rom th front and front will point to next
  //Parameters:  none
  //How to call: deleteFront();
  luck deleteFront(); //deletes an element
  //if empty there will be an error
  //Purpose: will display the contents in the queue
  //Algorthm: Will create a new pointer d that will point to front so that we dont chang//e th\e front and then display the element. then point to the next.
  //Parameters: none
  // How to call: view();
  void displayAll();//Will display the contents
  //Purpose:Will be used to print the contents in reverse
  //Algorthm:call printAllReverse with the parameters front
  //Parameters: none
  //How to call: printAllReverse();
  void printAllReverseDLL();//will be used to reverse
  //Purpose:Will be used to print contents in reverse
  //Algorthm: calls printAllReverse(a -> next) and the displays the contents with
  // cout << a -> elem to print the reverse order
  //Parameters: node* a
  //how to call: function name with the pointer paseed to it
  void printAllReverseDLL(node* P);//will be used to reverse the linked list
  //purpose: Will add to the front of the queue
  //Algorthm: checks isEmpty and if it is it will creat a new node so that we can add to the front else a we make front point and also make another node so we can add to the front
 //parameters: luck input 
  //how to call: function with an element passed to it
  void addFront(luck input);
  //Purpose: to delete from the rear
  //Algorthm: Checks to see if it is empty. if count = 1 then the front will be deleted. Else we make a new node* that isnt the rear so that we can delete the rear and then the new rear is the node we made.
  //parameters: none
  //how to call: deleteRear();
  luck deleteRear();
  //Purpose: to delete a node
  //Algorithm: Check is empty then if the element is in the linked list it will be deleted
  //Parameters:Luck input 
  //How to call: deleteNode(input)
  void deleteNode(luck input);
  //Purpose: To delete multiple of the same node
  //Algorthm: check to see if the linked list is empty if not it will go throuh the list untill the element we want is deleted and will go through the entire list to get rid of multiples of that element
  //Parameters:Luck input
  //How to call: deleteNodes(input)
  void deleteNodes(luck input);
  //Purpose: will put the elements in ascending order
  //algorthm:if its empty or the input is less than front element then the inputed element is added to the front else p is used to put the element that is less than the inputed element in front and then it will increment
  //Parameters:Luck input
  //How to call: addInOrderAscend(input)
  void addInOrderAscend(luck input);
  //Purpose: will put the elements in descending order
  //Algorthm: if its empty or the input is greater than the front element then the inputed element is added to the front else P is used to put the element that is greater than the inputed element in front and increment. 
  //Parameters:Luck input
  //How to call: addInOrderDescend(input)
  void addInOrderDescend(luck input);
  //Purpose: will search for an element
  //Algorthm: if a pointer isn't null then it will go throught the linked list until it is equal to the element and returns true if found else it returns false
  //Parameters:Luck input
  //How to call: search(input)
  bool search(luck input);
};
#endif
