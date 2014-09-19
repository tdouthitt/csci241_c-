#ifndef Rectangle_H
#define Rectangle_H


#include "Shape.h"
/**************************************************************
FILE:      Rectangle.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:   Contains the declaration for the Rectangle class.
***************************************************************/ 
class Rectangle: public Shape{

   private:

	// Data members
    int height;
	int width;

   public:

	//constructors
	Rectangle(string, int, int);
	
	//virtual methods
	virtual void print();
	
	//pure virtual methods
	double get_area();
};

#endif 