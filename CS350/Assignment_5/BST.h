//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the Binary Search Tree class and implementation for assignment 5

#ifndef BST_H
#define BST_H
//#endif //BST_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <string>

#include "Student.h"
#include "Faculty.h"

using namespace std;

//template class for Node
template <typename T>
class Node
{
	public:
		Node();
		Node(T value);
		~Node();

		T data;
		Node<T> * left;
		Node<T> * right;
};
//#endif

//constructor
template <typename T>
Node<T>::Node()
{
	left = NULL;
	right = NULL;
}

//constructor
template <typename T>
Node<T>::Node(T value)
{
	data = value;
	left = NULL;
	right = NULL;
}

//deconstructor
template <typename T>
Node<T>::~Node()
{
	delete left;
	delete right;
}

//interface for the BST
template <typename T>
class BSTInterface
{
	public:
		virtual bool insert(T data) = 0;
		virtual bool deleteNode(T data) = 0;
		virtual bool search(T data) = 0;
};

//template class for BST
template <typename T>
class BST : BSTInterface<T>
{
	public:
		BST();	//constructor
		~BST();	//deconstructor

		virtual bool insert(T data);	//insert
		virtual bool deleteNode(T data);	//delete node
		virtual bool search(T data);	//searches

		Node<T> * getSuccessor(Node<T> * node);	//gets successor
		void removeAll(Node<T> * & root);	//removes all
		void display(Node<T> * root);	//dispalys
		void display();			//displays

		T searchID(T data);		//sreaches and returns the data
		void findReplace(T data);	//replaces the nodes data
		//Node<T> & operator*();

		void writeToFile(ofstream & file);	//writes out to file
		void writeToFile(Node<T> * node, ofstream & file);	//writes out to file
	private:
		Node<T> * root;
};

template <typename T>
BST<T>::BST()
{
	root = NULL;
}

template <typename T>
BST<T>::~BST()
{
	removeAll(root);
}

template <typename T>
void BST<T>::removeAll(Node<T> * & root)
{
	if(!root)
		return;
	removeAll(root -> left);
	removeAll(root -> right);

	delete root;
	root = NULL;
}

template <typename T>
bool BST<T>::insert(T data)
{
	Node<T> * node = new Node<T>(data);

	if(!root)
	{
		root = node;
		return true;;
	}

		Node<T> * current = root;
		Node<T> * parent = NULL;

	while(true)
	{
		parent = current;

		if(data < current -> data)
		{
			current = current -> left;
			if(!current)
			{
				parent -> left = node;
				return true;
			}
		}
		else if(data > current -> data)
		{
			current = current -> right;
			if(!current)
			{
				parent -> right = node;
				return true;
			}
		}
		else
			return false;

	}
	return false;
}

template <typename T>
bool BST<T>::search(T data)
{
	Node<T> * node = new Node<T>(data);

	if(!root)
	{
		return false;
	}
		Node<T> * current = root;
		Node<T> * parent = NULL;

	while(true)
	{
		parent = current;

		if(data == current -> data)
		{
			return true;
		}
		if(data < current -> data)
		{
			current = current -> left;
			if(!current)
			{
				return false;
			}
		}
		if(data > current -> data)
		{
			current = current -> right;
			if(!current)
			{
				return false;
			}
		}

	}

	return false;
}

template <typename T>
T BST<T>::searchID(T data)
{
	Node<T> * node = new Node<T>(data);

		Node<T> * current = root;
		Node<T> * parent = NULL;

	while(true)
	{
		parent = current;

		if(data == current -> data)
		{
			return current -> data;
		}
		else if(data < current -> data)
		{
			current = current -> left;
		}
		else if(data > current -> data)
		{
			current = current -> right;
		}

	}

}

template <typename T>
void BST<T>::findReplace(T data)
{
	Node<T> * node = new Node<T>(data);

	if(!root)
	{
		root = node;
		return;
	}
	
		Node<T> * current = root;
		Node<T> * parent = NULL;

	while(true)
	{
		parent = current;


		if(data == current -> data)
		{
			node -> data.display();
			current -> data = data;		//this replaces the node with the new node & data
			current -> data.display();
			cout << "REPLACE WORKING" << endl;
			return;
		}
		else if(data < current -> data)
		{
			current = current -> left;
		}
		else if(data > current -> data)
		{
			current = current -> right;
		}
		else
			return;

	}
}

template <typename T>
bool BST<T>::deleteNode(T data)
{
	if(!root)
	{
		return false;
	}

	Node<T> * current = root;
	Node<T> * parent = NULL;
	bool isLeft = true;

	while(current -> data != data)
	{
		parent = current;

		if(data < current -> data)
		{
			isLeft = true;
			current = current -> left;
		}
		else if(data > current -> data)
		{
			isLeft = false;
			current = current -> right;
		}
		else
			return false;
	}

	//No children delete case
	
	if(current -> left == NULL && current -> right == NULL)
	{
		if(current == root)
			root = NULL;
		else if(isLeft)
			parent -> left = NULL;
		else
			parent -> right = NULL;
	}
	
	//one child case, right case
	else if(current -> right == NULL)
	{
		if(current == root)
			root = current -> left;
		else if(isLeft)
			parent -> left = current -> left;
		else
			parent -> right = current -> left;
	}
	//no left child
	else if(current -> left == NULL)
	{
		if(current == root)
			root = current -> right;
		else if(isLeft)
			parent -> left = current -> right;
		else
			parent -> right = current -> right;
	}

	//two Children case
	else
	{
		Node<T> * successor = getSuccessor(current);

		if(current == root)
			root = successor;
		else if(isLeft)
			parent -> left = successor;
		else
			parent -> right = successor;

		successor -> left = current -> left;
	}



	return true;
}


template <typename T>
Node<T> * BST<T>::getSuccessor(Node<T> * node)
{
	Node<T> * sp = node;
	Node<T> * successor = node;
	Node<T> * current = node -> right;

	while(!current)
	{
		sp = successor;
		successor = current;
		current = current -> left;
	}

	if(successor != node ->right)
	{
		sp -> left = successor -> right;
		successor -> right = node -> right;
	}
	return successor;
}



template <typename T>
void BST<T>::display()
{
	display(root);
}

template <typename T>
void BST<T>::display(Node<T> * root)
{

	if(!root)
		return;
	display(root -> left);
	root -> data.display();
	display(root -> right);
}

template <typename T>
void BST<T>::writeToFile(ofstream & file)
{
	writeToFile(root, file);
}

template <typename T>
void BST<T>::writeToFile(Node<T> * root, ofstream & file)
{

	if(!root)
		return;
	writeToFile(root -> left, file);
	root -> data.serialize(file);
	writeToFile(root -> right, file);
}

#endif
