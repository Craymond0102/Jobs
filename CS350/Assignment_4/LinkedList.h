//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the Linked List class for assignment 4

#include <iostream>
#include <ostream>
#include <fstream>
//#include "Student.h"
//#include "Node.h"

using namespace std;


//node for the Linked List
template <typename T>
class Node
{
	public:
		Node();
		Node(T value);
		~Node();

		T data;
		Node<T> * next;
		Node<T> * previous;
};

//constructor
template <typename T>
Node<T>::Node()
{
	data = NULL;
	next = NULL;
	previous = NULL;
}
//constructor with data
template <typename T>
Node<T>::Node(T value)
{
	data = value;
	next = NULL;
	previous = NULL;
}

//deconstructor, deallocates all dynamic memory
template <typename T>
Node<T>::~Node()
{
	delete next;
	delete previous;
}


//List interface
template <typename T>
class List
{
	public:
		virtual void insertFront(T data) = 0;
		virtual void insertBack(T data) = 0;
		virtual T removeFront() = 0;
		virtual T removeBack() = 0;
		
		virtual void displayAll() = 0;
		virtual bool isEmpty() = 0;
		virtual int getSize() = 0;
		virtual T& getFront() = 0;

};


//linked list class that extends List interface
template <typename T>
class LinkedList : List<T>
{
	public:
		LinkedList();
		~LinkedList();

		virtual void insertFront(T data);
		virtual void insertBack(T data);
		virtual T removeFront();
		virtual T removeBack();
		
		virtual void displayAll();
		virtual int getSize();
		virtual bool isEmpty();
		virtual T& getFront();

	private:
		Node<T> * head;
		Node<T> * tail;
		unsigned int size;
};


//constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

//deconstructor, deallocates
template <typename T>
LinkedList<T>::~LinkedList()
{
	if(!head)
		return;

	Node<T> * current = head;

	while(head)
	{
 		current = head -> next;
		delete head;
		head = current;
	}

	head = NULL;
}

//inserts at the front
template <typename T>
void LinkedList<T>::insertFront(T data)
{
	Node<T> * node  = new Node<T>(data);

	if(!head)
	{
		cout << "List is empty" << endl;
		head = node;
	}
	else
	{
		head -> previous = node;
		node -> next = head;
	}
		head = node;
		++size;
}

//inserts at the back
template <typename T>
void LinkedList<T>::insertBack(T data)
{
	Node<T> * node = new Node<T>(data);

	if(!head)
	{
		head = node;
	}
	else
	{
		tail-> next = node;
		node -> previous = tail;
	}
	tail = node;
	++size;
}

//removes front
template <typename T>
T LinkedList<T>::removeFront()
{
	Node<T> * node = head;

	if(head -> next == NULL)
	{
		tail = NULL;
	}
	else
	{
		head -> next -> previous = NULL;
	}
		head = head -> next;
		--size;
		node -> next = NULL;
		T temp = node -> data;
		delete node;
		return temp;
}

//removes back
template <typename T>
T LinkedList<T>::removeBack()
{
	Node<T> * node = tail;

	if(tail -> previous == NULL)
	{
		head = NULL;
	}
	else
	{
		tail -> previous -> next = NULL;
	}
		tail = tail -> previous;
		--size;
		node -> previous = NULL;
		T temp = node -> data;
		delete node;
		return temp;
}

//display (doesn't work...)
template <typename T>
void LinkedList<T>::displayAll()
{
	Node<T> * current = head;

	while(current)
	{
	//	cout << current -> display();
		current = current -> next;
	}

}

//checks to see if empty
template < typename T>
bool LinkedList<T>::isEmpty()
{
	if(!head)
		return true;
	return false;
}

//gets the size
template <typename T>
int LinkedList<T>::getSize()
{
	return size;
}

//returns the front
template <typename T>
T & LinkedList<T>::getFront()
{
	return head -> data;
}

