#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>
/**************************************************************
FILE:      Queue.h
AUTHOR:    Taylor Douthitt
LOGON ID:  z1579803
DUE DATE:  4/19/11
         
PURPOSE:   Contains the declaration and code for the template
			class Queue and template function operator <<.
***************************************************************/

using std::ostream;
using std::out_of_range;

template <class T>
struct QNode
   {
	
		T queueItem;
		QNode<T> * next;	
		QNode<T>(const T& item);
	
	 
   };

// Method definitions for the QNode class
template <class T>
QNode<T>::QNode(const T& item)
{
	queueItem = item;
	next = NULL;
}

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(ostream&, const Queue<T>&);

template <class T>
class Queue
   {
	
    // friend declaration for the template function - note the
    // special syntax
    friend ostream& operator<< <>(ostream&, const Queue<T>&);
	
	private:
		void copyList(const Queue<T>& rightOp);
		
	public:
		QNode<T> * qFront;
		QNode<T> * qRear;
		
		Queue();
		~Queue();
		Queue(const Queue<T>& s);
		Queue& operator=(const Queue<T>& rightOp);
		void clear();
		int size() const;
		bool empty() const;
		T front() const;
		T back() const;
		void push(const T& q);
		void pop();
   };
   

// Method definitions for the Queue class
/***************************************************************
   FUNCTION: Queue()
 
   USE:	The class should have a default constructor that takes
   no arguments. The constructor should set both pointer queueItem
   members to NULL.  
 

   ARGUMENTS: None.
***************************************************************/	
template <class T>
Queue<T>::Queue()
{
	qFront = NULL;
	qRear = NULL;
}
/***************************************************************
   FUNCTION: ~Queue()
 
   USE: The destructor simply calls the clear() method described below.
 

   ARGUMENTS: N/A
***************************************************************/
template <class T>
Queue<T>::~Queue()
{
	clear();
}
/***************************************************************
   FUNCTION: copyList(const Queue& rightOp)
 
   USE: This method should loop through the queue to assign one
   Queue object list(the object rightOp) to another list(the object 
   that called the method, which is pointed to by this). 
 

   ARGUMENTS: rightOp: Queue object to be passed in.
   
   RETURNS: N/A
***************************************************************/
template <class T>
void Queue<T>::copyList(const Queue<T>& rightOp)
{
	QNode<T>* temp;
	QNode<T>* newNode;
	QNode<T>* lastNode;
	
	
	
	if (rightOp.qFront != NULL) // or if(rightOp.empty())
	{
		// copy first node
		temp = rightOp.qFront;
		newNode = new QNode<T>(temp->queueItem);
		qFront = newNode;
		lastNode = newNode;
		
		// copy other nodes
		for (temp = temp->next; temp != NULL; temp = temp->next)
		{
			newNode = new QNode<T>(temp->queueItem);
			lastNode->next = newNode;
			lastNode = newNode;
		}
		qRear = lastNode;
	}
	
	
}
/***************************************************************
   FUNCTION: Queue(const Queue& s)
 
   USE: This "copy constructor" for the Queue class should
   initialize a new Queue object to the same queueItem as the
   existing Queue object s.
 

   ARGUMENTS: s: the Queue object to be intialized as a new
   Queue object.
***************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& s)
{
	qFront = NULL;
	qRear = NULL;
	copyList(s);
}
/***************************************************************
   FUNCTION: operator=(const Queue& rightOp)
 
   USE: This overloaded assignment operator should assign one
   Queue object (the object rightOp) to another (the object 
   that called the method, which is pointed to by this). 
 

   ARGUMENTS: rightOp: Queue object to be passed in.
   
   RETURNS: Queue object of calling object
***************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rightOp)
{
	if( this != &rightOp)//if addresses not equal
	{
		clear();
		copyList(rightOp);
	}
	return *this;
}
/***************************************************************
   FUNCTION: operator<<(ostream&, const Queue<T>&)
 
   USE: This method should print the item stored in the 
   queueItem of the Queue object passed in as rightOp using the
   stream object passed in as leftOp.
 

   ARGUMENTS: os - stream object being passed in.
              rightOp - Queue object being passed in.
   
   RETURNS: os: ostream object reference.
***************************************************************/
template <class T>
ostream& operator<<(ostream& os, const Queue<T>& rightOp)
{

    QNode<T> * temp = rightOp.qFront;

    if ( temp == NULL ) //if list empty
	{
		return os;
    }

    if ( temp->next == NULL ) //if list has one element
	{
		os << temp->queueItem;
		os << " ";
	}
    else //if list has more than one element
	{
		// Print out items in queue
		do 
		{
			os << temp->queueItem;
			os << " ";
			temp = temp->next;
		}
		while ( temp != NULL );//as long as there are more nodes
    }

	return os;
	
}
/***************************************************************
   FUNCTION: clear()
 
   USE: This method takes no arguments and returns nothing. It
   should properly set the queue back to the empty state. That 
   means deleting all of the nodes in the queue and setting the
   front and rear pointers back to NULL.
 
   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
template <class T>
void Queue<T>::clear()
{
	while ( qFront != NULL )//while not empty
	{
		//make empty
		QNode<T> * temp = qFront;
		qFront = qFront->next;
		delete temp;
	}
	qRear =NULL;
	qFront = NULL;
}
/***************************************************************
   FUNCTION: size()
 
   USE: This method takes no arguments and returns an integer.
   It should return the current size of the queue; i.e., the
   number of queueItem items currently stored in the queue. Since 
   this is not stored as a queueItem member of the queue class, you 
   will have to traverse the linked list and count the nodes.
 
   ARGUMENTS: N/A
   
   RETURNS: size - the number of nodes in the linked list
***************************************************************/
template <class T>
int Queue<T>::size() const 
{
	int size = 0;
	
	QNode<T> * temp = qFront;
	while(temp != NULL)//while more nodes left
	{
		size++;
		temp = temp->next;
	}
		
	return size;
}
/***************************************************************
   FUNCTION: empty()
 
   USE: Returns true if there are no queueItem items currently stored
   in the queue; otherwise returns false.
 
   ARGUMENTS: N/A
   
   RETURNS: bool varaible:True if empty, false otherwise.
***************************************************************/
template <class T>
bool Queue<T>::empty() const
{
	if (qFront == NULL)//if empty
		return true;
	else//if not empty
		return false;
}
/***************************************************************
   FUNCTION: front()
 
   USE: This method takes no arguments and returns the template
   parameter type. If the queue is empty, this method should 
   throw an out_of_range exception. Otherwise, it should return
   the queueItem stored in the front node of the queue.
 
   ARGUMENTS: N/A
   
   RETURNS: template parameter type
***************************************************************/
template <class T>
T Queue<T>::front() const
{
	
	if(empty())//if empty
	{
		
		throw out_of_range("Queue underflow on front()");
		
	}
	else//if not empty
		return qFront->queueItem;	
}
/***************************************************************
   FUNCTION: back()
 
   USE: This method takes no arguments and returns the template
   parameter type. If the queue is empty, this method should throw
   an out_of_range exception. Otherwise, it should return the queueItem
   stored in the rear node of the queue.
 
   ARGUMENTS: N/A
   
   RETURNS: template parameter type
***************************************************************/
template <class T>
T Queue<T>::back() const
{
	if(qFront==NULL)//if empty
	{
		
		throw out_of_range("Queue underflow on back()");
		
	}
	return qRear->queueItem;
}
/***************************************************************
   FUNCTION: push()
 
   USE: This method takes a reference to a constant item of
   the template parameter type as its argument (the item to
   insert into the queue). It returns nothing. The method should 
   insert the item at the rear of the queue.
 
   ARGUMENTS: q - argument to be inserted into queue
   
   RETURNS: N/A
***************************************************************/
template <class T>
void Queue<T>::push(const T& q)
{
    
	QNode<T> * temp = new QNode<T>(q);
        if(qFront == NULL)//if empty
           qFront = temp;
        else//if not empty
           qRear->next = temp;//set qRear to next position as temp
	qRear = temp;
			
}
/***************************************************************
   FUNCTION: pop()
 
   USE: This method takes no arguments and returns nothing.
   If the queue is empty, this method should throw an out_of_range
   exception. Otherwise, it should remove the item at the front
   of the queue.
 
   ARGUMENTS: N/A
   
   RETURNS: N/A
***************************************************************/
template <class T>
void Queue<T>::pop()
{
	
	QNode<T> * temp;
	temp = qFront;
	if(temp==NULL)//if empty
	{
		
		throw out_of_range("Queue underflow on pop()");
		
	}
	qFront = temp->next;
	delete temp;
        if(qFront == NULL)//if empty
            qRear = NULL;

}
#endif /* QUEUE_H */
//with special thanks to kurt mcmahon who made this all possible :)