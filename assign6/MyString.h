#ifndef MyString_H
#define MyString_H

#include <iostream>
#include <stdexcept>
using namespace std;

/**************************************************************
FILE:      MyString.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  3/29/11
         
PURPOSE:   Contains the declaration for the MyString class.
***************************************************************/ 
class MyString
{

	//friend declarations
   friend ostream& operator<<(ostream&, const MyString&);
   friend istream& operator>>(istream& , MyString& );
   friend bool operator==(const char* leftOp, const MyString& rightOp);
   friend MyString operator+(const char* left, const MyString& right);//assign6
   private:

	// Data members
	int stringCapacity;
	char * stringArray;
	int stringSize;
    

   public:

	//constructors
	MyString();//assign6
	MyString(const char* s);//assign6
	MyString(const MyString& s);//assign6
	//destructor
	~MyString();//assign6
	//methods
	int capacity() const;//assign6
	MyString& operator=(const MyString& rightOp);//assign6
	MyString& operator=(const char* rightOp);//assign6
	MyString operator+(const MyString& rightOp) const;//assign6
	MyString operator+(const char* rightOp) const;//assign6
	char at(int sub) const throw(out_of_range);//assign6
	char& at(int sub) throw(out_of_range);//assign6
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
