#ifndef Triangle_H
#define Triangle_H


#include "Shape.h"
/**************************************************************
FILE:      Triangle.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:   Contains the declaration for the Triangle class.
***************************************************************/ 
class Triangle: public Shape{

   private:

	// Data members
	int height;
	int base;
    

   public:

	//constructors
	Triangle(string, int, int);
	
	//virtual methods
	virtual void print();
	
	//pure virtual methods
	double get_area();
};

#endif 