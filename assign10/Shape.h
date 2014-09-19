#ifndef Shape_H
#define Shape_H

#include <iostream>
#include <cstring>

using namespace std;
/**************************************************************
FILE:      Shape.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:   Contains the declaration for the Shape class.
***************************************************************/ 
class Shape
{

   private:

	// Data members
	string color;
    

   public:

	//constructors
	Shape(const string&);
	
	//virtual method
	virtual void print();
	
	//pure virtual method
	virtual double get_area() = 0;
	
	
	
};

#endif 