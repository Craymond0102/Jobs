//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//this is main for assignment 3

#include "CompilerChecker.h"


using namespace std;

int main(int argc, char** argv)
{
	//string for filename
	string filename = "";

	//gets the filename, or not
	if(argc > 1)
		filename = argv[1];
	else
	{
		cout << "Please give a file as an argument" << endl;
		return 0;
	}

	//creates class instance
	CompilerChecker test;

	cout << "Starting Syntax Checker" << endl;
	//test.display();
	//writes in the file
	test.writeInFile(filename);

	return 0;
}
