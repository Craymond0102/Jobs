//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//this is the class that will use a stack to check a file for errors

#include "stack.h"

//the class to check for compiler errors
class CompilerChecker
{
	public:
		CompilerChecker();	//constructor
		~CompilerChecker();	//deconstructor


		void writeInFile(string filename);		//Writes in the file of syntax
		void getMatch(string line, int lineNum);	//gets the delimiter matches
		void toAdd(char check);				//Adds match to stack	
		bool Check(char check);				//Checks for opposite delimiter
		bool toRemove(char check, char temp);		//removes from stack	
		char getDelim(char check);			//gets delimiter
		void getRemainder(int size);			//displays the lasting of the stack
		void display();					//display helper method


		//DO I need to initiate?
		GenStack<char> stack;				//stack class
};
