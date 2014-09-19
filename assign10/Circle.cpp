/**************************************************************
FILE:      Circle.cpp
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:	Contains code and definitions for the Circle class.  
***************************************************************/
#include "Circle.h"


/***************************************************************
   FUNCTION: Circle(string c, int r)
 
   USE:	a constructor that takes a string to initialize the 
   circle's color and an int to initiallize the circle's radius.
   The color string should be passed to the Shape constructor. 
 

   ARGUMENTS: c: color to be given to circle
			  r: radius to be given to circle
***************************************************************/
Circle::Circle(const string& c, int r) : Shape(c)
{
	
	radius = r;

}
/***************************************************************
   FUNCTION: print()
 
   USE:	The method should print the color, then print the word
   "circle" followed by the circle's radius and area  
 

   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
void Circle::print()
 
{
	Shape::print();
	cout << "circle, radius " << radius << ", area " << get_area() 
		 << endl;

}
/***************************************************************
   FUNCTION: get_area()
 
   USE:	This method should compute and return the circle's 
   area based on its radius.  
 

   ARGUMENTS: N/A
   
   RETURNS: area of circle as computed by radius and pi
***************************************************************/
double Circle::get_area()
{
	return (double) (3.1415926 * (radius * radius));

}