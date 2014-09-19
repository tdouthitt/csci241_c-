#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::endl;
using std::setw;
using std::left;
using std::swap;
/**************************************************************
FILE:      quicksort.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  4/26/11
         
PURPOSE:   Contains the declaration and code for the following template
			functions in use with the vector template
***************************************************************/
	
	template <class T>
	int ascendCompare(const T& item1, const T& item2);
	template <class T>
	int descendCompare(const T& item1, const T& item2);
	template <class T>
	void buildList(vector<T>& itemList, const char* fileName);
	template <class T>
	void printList(const vector<T>& itemList, int itemWidth, int numPerLine);
	template <class T>
	void sortList(vector<T>& itemList, int (*compare)(const T&, const T&));
	template <class T>
	void quickSort(vector<T>&, int, int, int (*compare)(const T&, const T&));
	template <class T>
	int partition(vector<T>&, int, int, int (*compare)(const T&, const T&));

// Method definitions 
/***************************************************************
   FUNCTION: ascendCompare(const T& item1, const T& item2)
 
   USE:	This function should return -1 if item1 is less than 
   item2, 1 if item1 is greater than item2, and 0 if item1 is
   equal to item2. You may assume that the data type T can be
   compared using the standard relational operators. 
 

   ARGUMENTS: item1: item used in comparison with item2
			  item2: item used in comparison with item1
   
   RETURNS: int - number representing comparison data(ascend)
***************************************************************/	
template <class T>
int ascendCompare(const T& item1, const T& item2)
{
	if(item1 == item2)//if equal
		return 0;
	else 
	{
		if(item1 < item2)//if 1 less than 2
			return -1;
		
		return 1;//if 1 greater than 2
	}
	
}
/***************************************************************
   FUNCTION: descendCompare(const T& item1, const T& item2)
 
   USE:	This function should return 1 if item1 is less than 
   item2, -1 if item1 is greater than item2, and 0 if item1
   is equal to item2. You may assume that the data type T 
   can be compared using the standard relational operators. 
 

   ARGUMENTS: item1: item used in comparison with item2
			  item2: item used in comparison with item1
   
   RETURNS: int - number representing comparison data(ascend)
***************************************************************/	
template <class T>
int descendCompare(const T& item1, const T& item2)
{
	if(item1 == item2)//if equal
		return 0;
	else 
	{
		if(item1 < item2)//if 1 less than 2
			return 1;
		
		return -1;//if 1 greater than 2
	}
}
/***************************************************************
   FUNCTION: void buildList(vector<T>& itemList, const char* fileName)
 
   USE:	This function should read items from an input file and 
   put them into a vector. 
   The function should first open the file for input, then read 
   items from the file using the >> operator one at a time until
   end of file, inserting them into the vector. Finally, it should
   close the input file.
 
 

   ARGUMENTS: itemList: a reference to a vector object that 
					    will be used to store the items
			  fileName: a C-style string containing
						the full pathname of the input file
   
   RETURNS: N/A
***************************************************************/	
template <class T>
void buildList(vector<T>& itemList, const char* fileName)
{
   T item;
   ifstream inFile;

   // Open inFile for input using fileName as the name of the file to open
   inFile.open(fileName);
   // Check that the file has been successfully opened
   if (!inFile)
      {
      cerr << "Error - unable to open input file\n";
      exit(1);
      }

   // Read item from input file
   inFile >> item;
   while(inFile)//while inFile still has data
      {
      itemList.push_back(item);
      // Read item from input file
	  inFile >> item;
      }

   // Close the input file
   inFile.close();


}
/***************************************************************
   FUNCTION: void printList(const vector<T>& itemList, int itemWidth, 
							int numPerLine)
 
   USE:	This function should print a list of items stored in a 
   vector. 

   ARGUMENTS: itemList: a reference to 
			  a constant vector object that will 
			  contain the items to print.
			  
			  itemWidth: an integer specifying the 
			  width an individual item should occupy 
			  when printed 
			  
			  numPerLine: an integer specifying the
			  maximum number of items that should be 
			  printed in a single line of output.
   
   RETURNS: N/A
***************************************************************/	
template <class T>
void printList(const vector<T>& itemList, int itemWidth, int numPerLine)
{
	int itemCount = 0;
	for (int i = 0; i < (int) itemList.size(); i++)//loop through vector and print
	{
		
		if(itemCount == numPerLine)//if max number per line met
		{
			cout << endl;
			itemCount = 0;
		}
		cout << setw(itemWidth) << itemList[i] << " ";
		itemCount++;
	}

}
/***************************************************************
   FUNCTION: void sortList(vector<T>& itemList, int (*compare)
   (const T&, const T&))
 
   USE:	This function should sort the items in the vector itemList
   using the heapsort algorithm. 

   ARGUMENTS: itemList: a reference to a vector object 
			  containing the list of items to sort.
			  
			  *compare: a pointer to a comparison function 
			  that can be used to compare two items of the template 
			  type. 
   
   RETURNS: N/A
***************************************************************/	
template <class T>
void sortList(vector<T>& itemList, int (*compare)(const T&, const T&))
{
	 //call recursive quicksort function
	 quickSort(itemList, 0, (int) itemList.size()-1, compare);
}
/***************************************************************
   FUNCTION: void quickSort(vector<T>& itemList, int first, int
   last, int (*compare)(const T&, const T&))
 
   USE:	This function performs the recursive calls to implement
   the quick sort algorithm. 

   ARGUMENTS: itemList: a reference to a vector object 
			  containing the list of items to sort.
			  
			  first: the first index number in the vector(size()-size())
			  
			  last: the last index number in the vector(size()-1)
			  
			  *compare: a pointer to a comparison function 
			  that can be used to compare two items of the template 
			  type. 
   
   RETURNS: N/A
***************************************************************/	
template <class T>
void quickSort(vector<T>& itemList, int first, int last, int 
(*compare)(const T&, const T&))
{
	if (first < last)
    {
		int pivotLocation = partition(itemList, first, last, compare);     // find pivot location
		quickSort(itemList, first, pivotLocation-1, compare);              // sort first section
		quickSort(itemList, pivotLocation+1, last, compare);               // sort second section
    }

}
/***************************************************************
   FUNCTION: int partition(vector<T>& itemList, int first, 
   int last, int (*compare)(const T&, const T&))
 
   USE:	This function selects a pivot element and then 
   partitions the vector around the pivot. 

   ARGUMENTS: itemList: a reference to a vector object 
			  containing the list of items to sort.
			  
			  first: the first index number in the vector(size()-size())
			  
			  last: the last index number in the vector(size()-1)
			  
			  *compare: a pointer to a comparison function 
			  that can be used to compare two items of the template 
			  type. 
   
   RETURNS: smallIndex - 
***************************************************************/	
template <class T>
int partition(vector<T>& itemList, int first, int last, int 
(*compare)(const T&, const T&))
{
	 int index, smallIndex, middle;
   T pivot;
   
   middle = (first + last) / 2;

   // Swap elements first and middle of the vector
   swap(itemList[first],itemList[middle]);
   
   pivot = itemList[first];
   smallIndex = first;
 
   for (index = first+1; index <= last; index++)//loop through and swap elements
      {
      if (compare(itemList[index], pivot) < 0)
         {
         smallIndex++;
         // Swap elements smallIndex and index of the vector
		 swap(itemList[smallIndex],itemList[index]);
         }
      }

   // Swap elements smallIndex and first of the vector
	swap(itemList[smallIndex],itemList[first]);
   
   return smallIndex;  
   

}

#endif /* QUICKSORT_H */