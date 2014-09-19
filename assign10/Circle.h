#ifndef Circle_H
#define Circle_H


#include "Shape.h"
/**************************************************************
FILE:      Circle.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:   Contains the declaration for the Circle class.
***************************************************************/ 
class Circle: public Shape{

   private:

	// Data members
	int radius;
	
    

   public:

	//constructors
	Circle(const string& c, int r);

	//virtual methods
	virtual void print();
	
	//pure virtual methods
	double get_area();
	
};

#endif  