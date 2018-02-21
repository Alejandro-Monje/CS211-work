//****************************************************************************
//CS211
//Lab 8, Assignment 4
//game.C
//Name: Alejandro Monje
//Date: 3/16/16
//Purpose: to make a game with different difficulties. If you answer enough questions right in time you win or if you dont answer enough questions correctly in time you lose.
//////////
#include <time.h>
#include <iostream>
#include <pthread.h>
#include "inputCheck.h"
#include "queue.h" //your queue class
using namespace std;

//prototypes
void *answerQuestion(void* data);
void *addQuestion(void* data);
int correctAnswer(int op1, char optr, int op2);
char getOperator(op o);
expr makeQuestion();

//global - easier to share them between threads
Queue anothereQ; //create a queu object. the queue will store math questions
bool win; //set to true if win, false if lose
int numCorrect = 0; //the number of correct questions the user answered
pthread_mutex_t lock; //used to lock a part of code where a shared resource (q) 
                      //is updated by a thread
int level;//level of difficulty (1 for easy/slot, 5 for hard/fast)

int main()
{
  //get a different sequence of random nnumbers in each run
  srand(time(NULL));
 
  cout << "Which level do you want to try? 1 (easy) to 5 (hard): ";
  //level 1 will add a new question every 5 seconds. If level 2, every 4 seconds. If level 5, every 1 second.
  level = getNumberInRange(1, 5, "Invalid level. Enter 1 to 5: "); //from inputCheck.h

  //adds 3 questions into the rear of the queue 
       anothereQ.add(makeQuestion());
	anothereQ.add(makeQuestion());
	anothereQ.add(makeQuestion());
  
  //initialize the mutex
  if(pthread_mutex_init(&lock, NULL) != 0)
    {
      cout << "Creating a mutext failed." << endl;
      return 1; //ending the program. 1 is an error code passed to the operating system
    }

  //delcare 2 threads. first thread to add new questions and second for the user to answer questions.
  pthread_t  tAddQues, tAns;
   
  //thread to add new qustions to the rear of the queue
  pthread_create(&tAddQues, NULL, &addQuestion, NULL);

  //thread for the user to answer questions removed from the front of the queue
  pthread_create(&tAns, NULL, &answerQuestion, NULL);
 

  //wait for the thread to come back from addQuestion()
  pthread_join(tAddQues, NULL);

  //wait for the thread to come back from answerQuestion()
  pthread_join(tAns, NULL);

  //win is set to true in answeQuestion() - if the user answers quickly and the queue gets empty or he answers 100 questions correctly, the user wins the game
  if(win)
    cout << "You win !!!!!!! (you're the best) " << endl;
  else //if the user doesn't answer questions quick enough and the queue grows to have 10 questions, he loses.        
    cout << "Sorry you have lost the game: " << endl;
    cout << "You answered " << numCorrect << " questions correctly." << endl;

  return 0;
}

void *addQuestion(void* data)
{
    expr newproblem;//a new question to be added

    clock_t endWait;
    //a new question will be added to the queue every 1 second if the level is 5, 
    //2 sec onds if the level is 4, .. 5 seconds if the level is 1.
    int waitTime = CLOCKS_PER_SEC * (6 - level);
    endWait = clock() + waitTime;

    //as soon as the queue grows to have 10 questions, gets empty or the user answers 100 questions correctly, the game ends
    while(anothereQ.getSize() < 10 && !anothereQ.isEmpty() && (numCorrect < 100))
	  {
	    //it is time to add a new question to the queue
	    if(clock() >= endWait)
	      {
		//create a new question
		newproblem = makeQuestion();
		//lock the code so this thread has exclusive access to the queue while updating
		pthread_mutex_lock(&lock);
		//add the new question to the rear of the queue
		anothereQ.add(newproblem);
		pthread_mutex_unlock(&lock); //unlock the exclusive access so the other thread 
		                             //can access the queue now
		//reset the end wait time
		endWait = clock() + waitTime;
	      }
	  }
}
void *answerQuestion(void* data)
{
  int answer,correct;
  int op1, op2;
  char opr;

  //as soon as the queue grows to have 10 questions, gets empty, or the user answers 100 questions correctly, the game ends
  while(anothereQ.getSize() < 10 && !anothereQ.isEmpty() && numCorrect < 100)
    {
      //get the question from the front of the queue
      //lock the code so this thread has exclusive access to the queue while updating
      pthread_mutex_lock(&lock);
      expr e = anothereQ.remove();

      
     
      pthread_mutex_unlock(&lock); //unlock the exclusive access so the other thread 
	                           //can access the queue now

      op1 = e.oprd1;
      opr = getOperator(e.oprt);
      op2 = e.oprd2;

      //get the answer to the question
      correct = correctAnswer(op1, opr, op2);
 
      //ask the usert to enter the user's answer
      cout << op1 << " " << opr << " " << op2 << " = ";
      answer = getNumberInRange(0, 400, "Invalid answer. Enter your answer again: ");//from inputCheck.h

      //as long as the user's answer is wrong, she/he will have to retry answering the same question
      while(answer != correct && (anothereQ.getSize() < 10) && !anothereQ.isEmpty())
	{
	  cout << "WRONG. try again. " <<  op1 << " " << opr << " " << op2 << " = ";
	  answer = getNumberInRange(0, 400, "Invalid answer. Enter your answer again: ");//from inputCheck.h
	}
      //the user's answer was correct. the number of correct increases 
      if(answer == correct)
	numCorrect++;
    }

  //if the queue grows to have 10 questions, the user loses the game
  //if the queue gets empty or the user answers 100 questions correctly, the user wins the game
  if(anothereQ.getSize() == 10)
     win = false;
  else 
     win = true;
}

//Converts an enum value to char
char getOperator(op o)
{
  switch(o)
    {
    case ADD: return '+';
    case SUB: return '-';
    case MUL: return '*';
    case DIV: return '/';
    }
}
      
//do the math
int correctAnswer(int op1, char optr, int op2)
{
  switch(optr)
    {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    }
}
 
//creates a question and returns a struct
expr makeQuestion()
{
  int temp;
  expr e;
  
  e.oprt = (op)(rand()%4); //0 for add, 1 for sub, 2 for mult, 3 for divi

  if(e.oprt == MUL) //if the operator is multiplication, make operands between 1 and 20 for the first operand and between 1 and 10 for the second operand.
                     // (large operands would make multiplication hard.)
    {
      e.oprd1 = rand()%20 + 1; //create a random number between 1 and 20
      e.oprd2 = rand()%10 + 1;//create a random number between 1 and 10
    }
  else //the operator is add, sub or divi. Make operands between 1 and 100
    {
      e.oprd1 = rand()%100 + 1;//create a randowm number between 1 and 100
      e.oprd2 = rand()%100 + 1; //create a randowm number between 1 and 100
      
      //if the operator is sub or division, the first operand should be greater than or equal to the second operator (otherwise the calulation
      //would the too difficult for SUB and too easy for DIVI. 
      if(e.oprt == SUB || e.oprt == DIV)
	{
	  if(e.oprd1 < e.oprd2) //if the second operand is larger, swap operand1 and operand2
	    {
	      temp = e.oprd1;
	      e.oprd1 = e.oprd2;
	      e.oprd2 = temp;
	    }
	}
    }
  
  return e;
}

 
 
