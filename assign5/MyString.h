#ifndef MyString_H
#define MyString_H

#include <iostream>
using namespace std;

/**************************************************************
FILE:      MyString.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  3/22/11
         
PURPOSE:   Contains the declaration for the MyString class.
***************************************************************/ 
class MyString
{

	//friend declarations
   friend ostream& operator<<(ostream&, const MyString&);
   friend istream& operator>>(istream& , MyString& );
   friend bool operator==(const char* leftOp, const MyString& rightOp);
	
   private:

	// Data members
	static const int stringCapacity = 80;
	char stringArray[81];
	int stringSize;
    

   public:

	//constructors
	MyString();
	MyString(const char* s);
	//methods
	bool operator==(const MyString& rightOp) const;
	bool operator==(const char* rightOp) const;
	char operator[](int sub) const;
	char& operator[](int sub);
	const char* c_str() const;
	bool empty() const;
	int size() const;
	void clear();
};

#endif   // MyString_H                   
