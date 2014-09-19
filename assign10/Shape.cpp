/**************************************************************
FILE:      Shape.cpp
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:	Contains code and definitions for the Shape class.   
***************************************************************/
#include "Shape.h"
/***************************************************************
   FUNCTION: Shape(const string& c)
 
   USE:	a constructor that takes a const string& argument and
   uses it to initialize the shape's color. Since the Shape 
   class is abstract, this constructor will only be invoked 
   by a derived-class constructor.  
 

   ARGUMENTS: c - color to be given to shape.
***************************************************************/
Shape::Shape(const string& c)
{
	color = c;

}
/***************************************************************
   FUNCTION: print()
 
   USE:	The method should print the color.  
 

   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
void Shape::print()
{
	cout << color << " ";

}
