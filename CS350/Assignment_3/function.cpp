//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//this is the function file for the Compiler Checker using the stack

#include "CompilerChecker.h"

//constructor - didn't know what to do with this. Dont think I did this quite right
CompilerChecker::CompilerChecker()
{

}

//deconstructor
CompilerChecker::~CompilerChecker()
{

}

//Writes in the file from user, if file doesn't exist quits and tells user
void CompilerChecker::writeInFile(string filename)
{
	fstream file_in(filename);

	int count = 0;
	string line = "";
	
	if(file_in)
	{
		if(file_in.is_open())
		{
			while(getline(file_in, line) && !file_in.eof())
			{
				++count;
				getMatch(line, count);
			}
		}
	}
	else
	{
		cout << "The file does not exist" << endl;
		return;
	}

	int size = stack.getSize();
	if(size > 0)
	{
		getRemainder(size);
	}
	else
		cout << "The delimiter syntax is correct!" << endl;
}

//Constructs the stack and checks for matches
void CompilerChecker::getMatch(string line, int lineNum)
{
	int length = line.length();
	char temp = ' ';
	char delimiter= ' ';
	//int count = 0;

	for(int i = 0; i < length; ++i)
	{
		//++count;
		toAdd(line[i]);	
		if(Check(line[i]) == true)
		{
			temp = stack.peek();	

			if(toRemove(line[i], temp) == false)
			{
				delimiter = getDelim(temp);
				cout << "Line " << lineNum << ": "<< "expected ";
				cout << delimiter << ", but found " << line[i] << endl;
				exit(-1);
			}
		}
	}
}

//adds to the stack
void CompilerChecker::toAdd(char check)
{
	if(check == '{')
	{
		stack.push(check);
	}
	if(check == '(')
	{
		stack.push(check);
	}
	if(check == '[')
	{
		stack.push(check);
	}
}

//Checks for the opposing delimiter
bool CompilerChecker::Check(char check)
{
	if(check == '}')
		return true; 
	else if(check == ')')
		return true;
	else if(check == ']')
		return true;
	else
		return false;
}

//Removes from the stack
bool CompilerChecker::toRemove(char check, char temp)
{
	if(check == '}' && temp == '{')
	{
		stack.pop();
		return true;
	}
	else if(check == ')' && temp == '(')
	{
		stack.pop();
		return true;
	}
	else if(check == ']' && temp == '[')
	{
		stack.pop();
		return true;
	}
	else
		return false;
}

//checks for delimiters
char CompilerChecker::getDelim(char check)
{
	if(check == '{')
		return '}';
	if(check == '(') 
		return ')';
	if(check == '[') 
		return ']';

	return 'p';
}

//displays the stack
void CompilerChecker::display()
{
	stack.display();
}

//gets the remaining stack and displays
void CompilerChecker::getRemainder(int size)
{
	char temp = ' ';
	char delimiter = ' ';

	for(int i = 0; i < size; ++i)
	{
		temp = stack.pop();		

		delimiter = getDelim(temp);

		if(i == 0)
		{
			cout << "Reached end of file, missing " << endl;
		}
		cout << delimiter << ", ";
	}	
	cout << endl;
}



