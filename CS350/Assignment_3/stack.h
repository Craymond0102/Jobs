//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the stack class for assignment 3

#include <iostream>
#include <fstream>

using namespace std;

//const for stack size
const int SIZE = 25;

//creating template stack class
template <typename T>
class GenStack
{
	public:
		//GenStack();	//constructors
		GenStack();
		~GenStack();	//deconstructor

		T pop();
		void push(T to_add);
		T peek();

		bool isEmpty();
		bool isFull();
		void display();
		int getSize();
		void resize();


		T * myArray;
		int size;
		int top;
};
/*
template <class T>
GenStack<T>::GenStack()
{
	myArray = NULL;
}
*/

//initializes
template <typename T>
GenStack<T>::GenStack()
{
	myArray = new T[SIZE];
	size = SIZE;
	top = -1;
}

//deallocates
template <typename T>
GenStack<T>::~GenStack()
{
	delete myArray;
}

//deletes an element of the array and returns the value
template <typename T>
T GenStack<T>::pop()
{
	if(isEmpty())
	{
		cout << "There is nothing in the list"<< endl;
		exit(-1);
	}

	return myArray[top--];
}

//looks at the top and returns the value
template <typename T>
T GenStack<T>::peek()
{
	if(isEmpty())
	{
		cout << "The array is empty" << endl;
		exit(-1);
	}

	return myArray[top];
}

//adds to the top of the stack
template <typename T>
void GenStack<T>::push(T to_add)
{
	if(isFull())
	{
		resize();
		//exit(-1);
	}
	myArray[++top] = to_add;
}

//checks to see if the stack is empty
template <typename T>
bool GenStack<T>::isEmpty()
{
	return top == -1;
}

//checks to see if the array is full
template <typename T>
bool GenStack<T>::isFull()
{
	return top == size-1;
}

//displays the whole stack
template <typename T>
void GenStack<T>::display()
{
	for(int i = 0; i < top+1; ++i)
	{
		cout << myArray[i] << endl;
	}
}

//gets the size of how many items are in the array
template <typename T>
int GenStack<T>::getSize()
{
	return top + 1;
}

//resizes array to twice the size
template <typename T>
void GenStack<T>::resize()
{
	T * temp = new T[size + SIZE];

	for(int i = 0; i < size; ++i)
	{
		temp[i] = myArray[i];
	}
	
	delete [] myArray;
	myArray = temp;

	size = size + SIZE;
}
