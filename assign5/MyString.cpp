/**************************************************************
FILE:      MyString.cpp
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  3/22/11
         
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
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::right;

/***************************************************************
   FUNCTION: MyString()
 
   USE: This "default" constructor for the MyString class 
        should set the string array to a "null string".
 

   ARGUMENTS: None.
***************************************************************/
MyString::MyString()
{
	
	stringArray[0] = '\0';//sets string to null
	stringSize = 0;
}
/***************************************************************
   FUNCTION: MyString(const char*)//pointer to a character constant
 
   USE: This constructor for the MyString class should copy the 
        C string s into the string array.
 

   ARGUMENTS: s: the string to be copied into the string array.
***************************************************************/
MyString::MyString(const char* s)
{
		strncpy(stringArray, s, 80);//copies a string up to 80
		stringArray[80] = '\0';//null char in last element of array
		stringSize = strlen(stringArray);//size equal to array size
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
