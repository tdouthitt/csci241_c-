/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 10
   PROGRAMMER: Taylor Douthitt
   LOGON ID:   z1579803
   DUE DATE:   5-3-11

   FUNCTION:   This program tests the functionality of the Shape
               class and its derived classes.
*********************************************************************/  

#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


using std::vector;
using std::cout;
using std::endl;


int main()
   {
	    cout << "CSCI241 Assignment 10 Program Output" << endl;
		//create pointer to shape vector
		vector<Shape *> shapes(6);
		//create new objects and put them into vector
		shapes[0] = new Circle("blue", 4);
		shapes[1] = new Circle("red", 12);
		shapes[2] = new Triangle("orange", 7, 3);
		shapes[3] = new Triangle("yellow", 6, 9);
		shapes[4] = new Rectangle("green", 4, 2);
		shapes[5] = new Rectangle("purple", 3, 3);
		
		
		
		cout << "Print all shapes:" << endl << endl;
		//prints each element in vector
		for(unsigned int i = 0; i < shapes.size(); i++)
		{
			shapes[i]->print();
		}
		cout << endl;
		cout << "Print only circles:" << endl << endl;
		//prints circles in vector
		for(unsigned int i = 0; i < shapes.size(); i++)
		{
			Shape * ptr = dynamic_cast<Circle *>(shapes[i]);
			if(ptr != NULL)//if circle
				shapes[i]->print();
		}
		cout << endl;
		//delete pointers to shapes in vector
		for(unsigned int i = 0; i < shapes.size(); i++)
		{
			delete shapes[i];
		}
		

   return 0;
   }

