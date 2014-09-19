/**************************************************************
FILE:      Rectangle.cpp
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  5/3/11
         
PURPOSE:	Contains code and definitions for the Rectangle class.   
***************************************************************/
#include "Rectangle.h"


/***************************************************************
   FUNCTION: Rectangle(string c, int h, int w)
 
   USE:	a constructor that takes a string to initialize the 
   rectangle's color and two ints to initialize the rectangle's
   height and width. The color string should be passed to the
   Shape constructor. 
 

   ARGUMENTS: c: color to be given to Rectangle
			  h: height to be given to Rectangle
			  w: width to be given to Rectangle
***************************************************************/
Rectangle::Rectangle(string c, int h, int w) : Shape(c)
{
	
	height = h;
	width = w;

}
/***************************************************************
   FUNCTION: print()
 
   USE:	The method should print the color, then print the word
   "rectangle" followed by the rectangle's height, width, and area  
 

   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
void Rectangle::print()
{
	Shape::print();
	cout << "rectangle, height " << height << ", width " 
		 << width << ",area " << get_area() << endl;

}
/***************************************************************
   FUNCTION: get_area()
 
   USE:	This method should compute and return the rectangle's
   area based on its height and width.  
 

   ARGUMENTS: N/A
   
   RETURNS: area of rectangle as computed by width and height
***************************************************************/
double Rectangle::get_area()
{
	return (double) (width * height);

}