//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the main .cpp file for Assingment 4, which simulates a
//registers office

#include <iostream>
#include <fstream>
#include "Simulation.h"

using namespace std;


int main(int argc, char** argv)
{
	string filename = "";

	if(argc > 1)
		filename = argv[1];
	else
	{
		cout << "Please give a file as an argument" << endl;
		return 0;
	}

	Simulation sim;

	sim.writeInFile(filename);


	return 0;
}
