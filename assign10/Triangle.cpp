/**************************************************************
FILE:      Triangle.cpp
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:	Contains code and definitions for the Triangle class.   
***************************************************************/
#include "Triangle.h"


/***************************************************************
   FUNCTION: Triangle(string c, int h, int b)
 
   USE:	a constructor that takes a string to initialize the
   triangle's color and two ints to initialize the triangle's 
   height and base. The color string should be passed to the 
   Shape constructor.

 
 

   ARGUMENTS: c: color to be given to Triangle
			  h: height to be given to Triangle
			  b: base to be given to Triangle
***************************************************************/
Triangle::Triangle(string c, int h, int b) : Shape(c)
{
	height = h;
	base = b;

}
/***************************************************************
   FUNCTION: print()
 
   USE:	The method should print the color, then print the word
   "Triangle" followed by the Triangle's height, base, and area  
 

   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
void Triangle::print()
{
	Shape::print();
	cout << "triangle, height " << height << ", base " 
		 << base << ", area " << get_area() << endl;

}
/***************************************************************
   FUNCTION: get_area()
 
   USE:	This method should compute and return the triangle's
   area based on its height and base.  
 

   ARGUMENTS: N/A
   
   RETURNS: area as computed by triangle's base and height
***************************************************************/
double Triangle::get_area()
{
	return (double) ((base * height)/2);

}