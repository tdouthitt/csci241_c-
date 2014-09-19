/**************************************************************
FILE:      MyString.cpp
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  3/29/11
         
PURPOSE:   Contains the instructions for a number
           of methods for the MyString class.
           The MyString class represents a string of characters.
           You can think of it as a "wrapper" we can put around a 
           C string (null-terminated array of char) that provides 
           additional functionality (like the ability to assign one
           string to another, compare strings using the relational 
           operators, etc.)
***************************************************************/
#include "MyString.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::out_of_range;

/***************************************************************
   FUNCTION: MyString()
 
   USE: This "default" constructor for the MyString class
   should initialize a new MyString object to a "null string". 
 

   ARGUMENTS: None.
***************************************************************/
MyString::MyString()
{
	
	
	stringSize = 0; //Set the string size for the new object to 0
	stringCapacity = 16;//Set the string capacity for the new 
					    //object to 16
	stringArray = new char[stringCapacity + 1];//string array
	stringArray[0] = '\0';//array set to null string
	
}
/***************************************************************
   FUNCTION: MyString(const char*)//pointer to a character constant
 
   USE: This constructor for the MyString class should 
   initialize a new MyString object to the C string s.
 

   ARGUMENTS: s: the string to be copied into the string array.
***************************************************************/
MyString::MyString(const char* s)
{
		stringSize = strlen(s);//size equal to arg size
		stringCapacity = (stringSize + 15) & ~15;//next multiple
		stringArray = new char[stringCapacity + 1];//string array
		strcpy(stringArray, s);//array set to argument array
}
/***************************************************************
   FUNCTION: MyString(const MyString&)
 
   USE: This "copy constructor" for the MyString class should
   initialize a new MyString object to the same string as the
   existing MyString object s.
 

   ARGUMENTS: s: the MyString object to be intialized as a new
   MyString object.
   *
***************************************************************/
MyString::MyString(const MyString& s)
{
	stringSize = s.stringSize;//size equal to arg object size
	stringCapacity = s.stringCapacity;//capacity equal to arg
									  //object capacity
	stringArray = new char[stringCapacity + 1];//string array
	strcpy(stringArray, s.stringArray);//copy arg object array
}
/***************************************************************
   FUNCTION: ~MyString()
 
   USE: The destructor for the MyString class should use the 
   delete[] operator to delete the string array.
 

   ARGUMENTS: N/A
   *
***************************************************************/
MyString::~MyString()
{
	delete [] stringArray;
}
/***************************************************************
   FUNCTION: capacity() const
 
   USE: This method should return the string capacity.
 

   ARGUMENTS: N/A
   
   RETURNS: int stringCapacity - data member of MyString class
   *
***************************************************************/
int MyString::capacity() const
{
	return stringCapacity;
}
/***************************************************************
   FUNCTION: operator=(const MyString& rightOp) 
 
   USE: This overloaded assignment operator should assign one
   MyString object (the object rightOp) to another (the object 
   that called the method, which is pointed to by this). 
 

   ARGUMENTS: rightOp: MyString object to be passed in.
   
   RETURNS: MyString object of calling object
   *
***************************************************************/
MyString& MyString::operator=(const MyString& rightOp)
{
	if(&rightOp != this)//if addresses not equal
	{
		delete[] stringArray;
		stringSize = rightOp.stringSize;//size equals arg size
		stringCapacity = rightOp.stringCapacity;//capacity equals
											    //arg capacity
		stringArray = new char[stringCapacity + 1];
		strcpy(stringArray, rightOp.stringArray);//copy arg array
		return *this;//calling object
	}
	else//if addresses equal
	{
	
		return *this;//calling object
	}
}
/***************************************************************
   FUNCTION: operator=(const char* rightOp) 
 
   USE: This overloaded assignment operator should assign a C 
   string (the string rightOp) to a MyString object (the object
   that called the method, which is pointed to by this). 
 

   ARGUMENTS: rightOp: char* object to be passed in.
   
   RETURNS: MyString object of calling object
   *
***************************************************************/
MyString& MyString::operator=(const char* rightOp) 
{
    delete[] stringArray;
	stringSize = strlen(rightOp);//size is arg size
	stringCapacity = (stringSize + 15) & ~15;
	stringArray = new char[stringCapacity + 1];
	strcpy(stringArray, rightOp);//copy arg array
	return *this;//calling object
}
/***************************************************************
   FUNCTION: operator+(const MyString& rightOp) const 
 
   USE: This operator method should concatenate the strings
   stored in two MyString objects (the object that called the
   method, which is pointed to by this, and the object rightOp).  
 

   ARGUMENTS: rightOp: MyString& object to be passed in.
   
   RETURNS: result - MyString object with concatenation result
   *
***************************************************************/
MyString MyString::operator+(const MyString& rightOp) const
{
	MyString result;//object for string concatenation result
	result.stringSize = (stringSize + rightOp.stringSize);
	if(result.stringSize > result.stringCapacity)//if resize needed
	{
		delete[] result.stringArray;//delete old
		result.stringCapacity = (stringSize + 15) & ~15;
		//create new
		result.stringArray = new char[result.stringCapacity + 1];
		
	}
	strcpy(result.stringArray, stringArray);//first part of result
	strcat(result.stringArray, rightOp.stringArray);//2nd part
	return result;
}
/***************************************************************
   FUNCTION: operator+(const char* rightOp) const 
 
   USE: This operator method should concatenate the C string 
   rightOp onto the end of the string stored in the MyString 
   object that called the method, which is pointed to by this. 
   This method will not work if you have not correctly written 
   the copy constructor.  
 

   ARGUMENTS: rightOp: MyString& object to be passed in.
   
   RETURNS: result - MyString object with concatenation result
   *
***************************************************************/
MyString MyString::operator+(const char* rightOp) const
{
	MyString result;//object for concatenation result
	result.stringSize = (stringSize + strlen(rightOp));
	if(result.stringSize > result.stringCapacity)//if resize needed
	{
		//delete old
		delete[] result.stringArray;
		result.stringCapacity = (stringSize + 15) & ~15;
		//create new
		result.stringArray = new char[result.stringCapacity + 1];
		
	}
	strcpy(result.stringArray, stringArray);//1st part of result
	strcat(result.stringArray, rightOp);//2nd part of result
	return result;
}
/***************************************************************
   FUNCTION: char at(int sub) const throw(out_of_range)
 
   USE: If sub is less than 0 or greater than or equal to the
   string size, this method should throw an out_of_range exception.
   Otherwise, it should return element sub of the string array.
 

   ARGUMENTS: sub: the element of the string array to return
   
   RETURNS: exception or char: element of the string array
   *
***************************************************************/
char MyString::at(int sub) const throw(out_of_range)
{
	if(sub >= 0 && sub < stringSize)//if in proper range
		return stringArray[sub];
	else//if out of range
		throw out_of_range("Subscript out of range");
}
/***************************************************************
   FUNCTION: char& at(int sub) throw(out_of_range)
 
   USE: If sub is less than 0 or greater than or equal to the
   string size, this method should throw an out_of_range exception.
   Otherwise, it should return element sub of the string array.
 

   ARGUMENTS: sub: the element of the string array to return
   
   RETURNS: exception or char: element of the string array
   *
***************************************************************/
char& MyString::at(int sub) throw(out_of_range)
{
	if(sub >= 0 && sub < stringSize)//if in proper range
		return stringArray[sub];
	else//if out of range
		throw out_of_range("Subscript out of range");
}
/***************************************************************
   FUNCTION: operator==(const MyString& rightOp) const
 
   USE: This method should return true if the C string stored in the 
        string array of the object that called the method is equal to
        the C string stored in the string array of the MyString object
        passed in as rightOp.
 

   ARGUMENTS: rightOp: MyString object to be passed in.
   
   RETURNS: bool type
***************************************************************/
bool MyString::operator==(const MyString& rightOp) const
{
	if(strcmp(stringArray, rightOp.stringArray) == 0)//if equal
	{
		return true;
	}
	return false;
	
}
/***************************************************************
   FUNCTION: operator==(const char* rightOp) const
 
   USE: This method should return true if the C string stored in the
        string array of the object that called the method is equal to
        the C string passed in as rightOp.
 

   ARGUMENTS: rightOp: C string to be passed in.
   
   RETURNS: bool type
***************************************************************/
bool MyString::operator==(const char* rightOp) const
{
	if(strcmp(stringArray, rightOp) == 0)//if equal
	{
		return true;
	}
	return false;	
	
}
/***************************************************************
   FUNCTION: operator[](int sub) const
 
   USE: This method should return element sub of the string array.
 

   ARGUMENTS: sub: element position to return.
   
   RETURNS: sub - specific element of the string array
***************************************************************/
char MyString::operator[](int sub) const
{
	return stringArray[sub];
}
/***************************************************************
   FUNCTION: operator[](int sub) const
 
   USE: This method should return element sub of the string array.
 

   ARGUMENTS: sub: element position to return.
   
   RETURNS: specific element of the string array
***************************************************************/
char& MyString::operator[](int sub)
{
	return stringArray[sub];
}
/***************************************************************
   FUNCTION: c_str() const
 
   USE: This method should return the name of the string array 
        (which will be converted into a pointer to the first 
        element of the array).
 

   ARGUMENTS: N/A.
   
   RETURNS: name of string array
***************************************************************/
const char* MyString::c_str() const
{
	return stringArray;
}
/***************************************************************
   FUNCTION: empty() const
 
   USE: This method should return true if the string size is 0.
        Otherwise it should return false.
 

   ARGUMENTS: N/A.
   
   RETURNS: bool type
***************************************************************/
bool MyString::empty() const
{
	if(stringSize == 0)//if empty
		return true;
	
	return false;
	
}
/***************************************************************
   FUNCTION: size() const
 
   USE: This method should return the string size.
 

   ARGUMENTS: N/A.
   
   RETURNS: string size
***************************************************************/
int MyString::size() const
{
	return stringSize;
	
}
/***************************************************************
   FUNCTION: clear()
 
   USE: This method does essentially the same thing as the default 
        constructor. It should set the string array to a "null string"
        and set the string size to 0.
 

   ARGUMENTS: N/A.
   
   RETURNS: N/A.
***************************************************************/
void MyString::clear()
{
	stringArray[0] = '\0';//sets string to null
	stringSize = 0;
}




//stand alone functions
/***************************************************************
   FUNCTION: operator+(const char* leftOp, const MyString& rightOp)
 
   USE: This operator function should concatenate the string stored
   in the MyString object rightOp onto the end of the C string leftOp.
 

   ARGUMENTS: leftOp - C string to be passed in
              rightOp - MyString object being passed in.
   
   RETURNS: result: MyString object holding result of string
   concatenation.
   *
***************************************************************/
MyString operator+(const char* leftOp, const MyString& rightOp)
{
	MyString result;//Declare a new MyString object to hold 
					//the result of the string concatenation
	result.stringSize = (strlen(leftOp) + rightOp.stringSize);
	if(result.stringSize > result.stringCapacity)//if resize needed
	{
		result.~MyString();//delete result object's string array
		result.stringCapacity = (result.stringSize + 15) & ~15;
		result.stringArray = new char[result.stringCapacity + 1];
		
	}
	strcpy(result.stringArray, leftOp);//1st part of result
	strcat(result.stringArray, rightOp.stringArray);//2nd part
	return result;
}
/***************************************************************
   FUNCTION: operator<<(ostream& leftOp, const MyString& rightOp)
 
   USE: This method should print the C string stored in the string
        array of the MyString object passed in as rightOp using the
        stream object passed in as leftOp.
 

   ARGUMENTS: leftOp - stream object being passed in.
              rightOp - MyString object being passed in.
   
   RETURNS: N/A.
***************************************************************/
ostream& operator<<(ostream& leftOp, const MyString& rightOp)
{
	leftOp << rightOp.stringArray;
	
	return leftOp;
}
/***************************************************************
   FUNCTION: operator>>(istream& leftOp, MyString& rightOp)
 
   USE: This method should read a string of characters into the string
        array of the MyString object passed in as rightOp using the 
        stream object passed in as leftOp. It should set the string 
        size of the object rightOp equal to the size of the C string 
        read.
 

   ARGUMENTS: leftOp - stream object being passed in.
              rightOp - MyString object being passed in.
   
   RETURNS: N/A.
***************************************************************/
istream& operator>>(istream& leftOp, MyString& rightOp)
{
	leftOp >> rightOp.stringArray;
	rightOp.stringSize = strlen(rightOp.stringArray);
	
	return leftOp;
}
/***************************************************************
   FUNCTION: operator==(const char* leftOp, const MyString& rightOp)
 
   USE: This method should return true if the C string passed in as
        leftOp is equal to the C string stored in the string array 
        of the MyString object passed in as rightOp.
 

   ARGUMENTS: leftOp - C string being passed in.
              rightOp - MyString object being passed in.
   
   RETURNS: N/A.
***************************************************************/
bool operator==(const char* leftOp, const MyString& rightOp)
{
	if(strcmp(leftOp, rightOp.stringArray) == 0)//if equal
	{
		return true;
	}
	return false;
}
