#ifndef Stack_H
#define Stack_H

#include <iostream>
#include <stdexcept>
using namespace std;

/**************************************************************
FILE:      Stack.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  4/12/11
         
PURPOSE:   Contains the declaration for the Stack class.
***************************************************************/ 
class Stack
{

	//friend declarations
   friend ostream& operator<<(ostream&, const Stack&);//output operator
   
   private:

	// Data members
	int * stackAR;
	int stackCapacity;
	int stackSize;
	int stackTop;
    

   public:

	//constructors
	Stack();
	//destructor
	~Stack();
	//copy constructor
	Stack(const Stack& s);
	//operator overloads
	Stack& operator=(const Stack& rightOp); //assignment operator
	
	//methods
	void clear();
	int size() const;
	bool empty() const;
	int top() const;
	void push(int item);
	void pop();
};

#endif                     
