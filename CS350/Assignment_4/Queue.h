//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the queue class for assignment 4

#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

//queue interface
template <typename T>
class QueueInterface
{
	public:
		virtual void enqueue(T data) = 0;
		virtual T dequeue() = 0;

		virtual void display() = 0;
		virtual bool isEmpty() = 0;
		virtual T& peek() = 0;

};

//Queue class, with extended Queue interface
template <typename T>
class Queue : QueueInterface<T>
{
	public:
		Queue();
		~Queue();
		virtual void enqueue(T data);
		virtual T dequeue();
	
		virtual void display();
		virtual bool isEmpty();
		virtual T& peek();
		int getSize();

	private:
		LinkedList<T> list;
		int size;
		int totalSize;
};

//constructor
template <typename T>
Queue<T>::Queue()
{
	size = 0;
	totalSize = 0;
	//list = NULL;
}

//deconstructor, deallocates
template <typename T>
Queue<T>::~Queue()
{
	if(isEmpty() == false)
	{
		list.removeFront();
	}
}

//adds to back
template <typename T>
void Queue<T>::enqueue(T data)
{
	list.insertBack(data);
	++totalSize;
	++size;
}

//removes the back
template <typename T>
T Queue<T>::dequeue()
{
	--size;
	return list.removeFront();
}


template <typename T>
void Queue<T>::display()
{
	//list.displayAll();
}

//checks to see if empty
template <typename T>
bool Queue<T>::isEmpty()
{
	return list.isEmpty();
}

//gets first element in queue
template <typename T>
T& Queue<T>::peek()
{
	return list.getFront();
}

//gets the total amount of elements that have been in the queue
template <typename T>
int Queue<T>::getSize()
{
	return totalSize;
}
	
