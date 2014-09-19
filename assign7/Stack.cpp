/**************************************************************
FILE:      Stack.cpp
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  4/12/11
         
PURPOSE:	This program creates and implements a class to 
			represent the Stack ADT using an array.   
***************************************************************/
#include "Stack.h"


/***************************************************************
   FUNCTION: Stack()
 
   USE:	The class has a default constructor that takes 
   no arguments. The constructor should set the stack's initial 
   capacity to 8 and dynamically allocate an array of integers 
   of that capacity. The stack size should be initialized to 0.
   The stack top subscript should be initialized to -1.  
 

   ARGUMENTS: None.
***************************************************************/
Stack::Stack()
{
	stackCapacity = 8;//initial stack Capacity
	stackAR = new int[stackCapacity];//allocate array
	stackSize = 0;//empty array
	stackTop = -1;

}
/***************************************************************
   FUNCTION: ~Stack()
 
   USE: The destructor for the Stack class should use the 
   delete[] operator to delete the stack array.
 

   ARGUMENTS: N/A
***************************************************************/
Stack::~Stack()
{
	delete [] stackAR;
}
/***************************************************************
   FUNCTION: Stack(const Stack&)
 
   USE: This "copy constructor" for the Stack class should
   initialize a new Stack object to the same data as the
   existing Stack object s.
 

   ARGUMENTS: s: the Stack object to be intialized as a new
   Stack object.
***************************************************************/
Stack::Stack(const Stack& s)
{
	stackSize = s.stackSize;//size equal to arg object size
	stackAR = new int[stackCapacity];//stack array
	stackCapacity = s.stackCapacity;//capacity equal to arg
									  //object capacity
	
	for(int i = 0; i < stackSize; i++)
		{
			stackAR[i] = s.stackAR[i];
		}//copy arg object array
}
/***************************************************************
   FUNCTION: operator=(const Stack& rightOp) 
 
   USE: This overloaded assignment operator should assign one
   Stack object (the object rightOp) to another (the object 
   that called the method, which is pointed to by this). 
 

   ARGUMENTS: rightOp: Stack object to be passed in.
   
   RETURNS: Stack object of calling object
   *
***************************************************************/
Stack& Stack::operator=(const Stack& rightOp)
{
	if(&rightOp != this)//if addresses not equal
	{
		delete[] stackAR;
		stackSize = rightOp.stackSize;//size equals arg size
		stackCapacity = rightOp.stackCapacity;//capacities equal
		stackTop = rightOp.stackSize - 1;//top subs equal								    //arg capacity
		stackAR = new int[stackCapacity];//allocate array
		
		for(int i = 0; i < stackSize; i++)
		{
			stackAR[i] = rightOp.stackAR[i];
		}//copy arg array
		
	}
		return *this;//calling object
	
}
/***************************************************************
   FUNCTION: clear() 
 
   USE:  This method should properly set the stack back to the empty
   state (set the stack size to 0 and the stack top subscript to -1).
 

   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
void Stack::clear()
{
	stackSize = 0;//empty array
	stackTop = -1;
}
/***************************************************************
   FUNCTION: size() 
 
   USE:  This method should return the stack size.
 

   ARGUMENTS: N/A
   
   RETURNS: stackSize: the stack size
***************************************************************/
int Stack::size() const
{
	return stackSize;
}
/***************************************************************
   FUNCTION: empty() 
 
   USE: This method should return true if the stack size is 0 
		otherwise it should return false.
 

   ARGUMENTS: N/A
   
   RETURNS: bool value
***************************************************************/
bool Stack::empty() const
{
	if(stackSize == 0)//if empty
		return true;
	else//if not empty
		return false;
}
/***************************************************************
   FUNCTION: top() 
 
   USE: If the stack is empty, this method should throw an 
   out_of_range exception. Otherwise, it should return the top 
   element of the stack array (the one at the stack top subscript).
 

   ARGUMENTS: N/A
   
   RETURNS: bool value
***************************************************************/
int Stack::top() const
{
	if(stackSize == 0)//if empty
		throw out_of_range("Stack underflow on top()");
	else//if not empty
		return stackAR[stackTop];
}
/***************************************************************
   FUNCTION: push(int) 
 
   USE: The method should increment the stack top subscript 
   and then copy the method argument into the stack array as the
   new top item in the stack. The stack size should be incremented
   by 1.
 

   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
void Stack::push(int item)
{
	
	if((stackSize == stackCapacity))//if array needs resizing
	{
		stackCapacity = stackCapacity * 2 ;//double array capacity
		int * tempAR;//new temp pointer to int
		tempAR = new int[stackCapacity];//allocate array
		
		for(int i = 0; i < stackSize; i++)
		{
			tempAR[i] = stackAR[i];
		}//copy arg array
		
		delete [] stackAR;//remove array
		stackAR = tempAR; //set array to address of temp array
	}
	//insert new item into stack
	stackTop++;
	stackAR[stackTop] = item;
	stackSize++; 
	
}
/***************************************************************
   FUNCTION: pop() 
 
   USE:  If the stack is empty, this method should throw an
   out_of_range exception. Otherwise, it should decrement the
   stack top subscript to effectively remove the top item in 
   the stack array. The stack size should be decremented by 1.
 

   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
void Stack::pop()
{
	if(stackSize == 0)//if empty
		throw out_of_range("Stack underflow on pop()");
	else//if not empty
	{
		//remove top element of stack
		stackTop--;
		stackSize--;
	}
	
	
}

//stand alone functions

/***************************************************************
   FUNCTION: operator<<(ostream& leftOp, const Stack& rightOp)
 
   USE: This method should print the array stored in the 
   array of the Stack object passed in as rightOp using the
   stream object passed in as leftOp.
 

   ARGUMENTS: leftOp - stream object being passed in.
              rightOp - Stack object being passed in.
   
   RETURNS: leftOp: ostream object reference.
***************************************************************/
ostream& operator<<(ostream& leftOp, const Stack& rightOp) 
{
	for(int i = 0; i < rightOp.size(); i++)
	{
		//print stack as standard output
		leftOp << rightOp.stackAR[i] << ' ';
		
	}
	return leftOp;
}