//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .cpp Main file for assignment 6

#include "SortingClass.h"

using namespace std;

int main(int argc, char** argv)
{
	//gets filename from command promt
	string filename = "";
	int size = 0;
	double time = 0;

	if(argc > 1)
		filename = argv[1];
	//gets the size of how big the array should be
	Sorting getSize;
	size = getSize.writeInSize(filename);

	//makes class, with size
	Sorting algorithm(size);;

	//writes in the array
	algorithm.writeInArray(filename);


	//gets time and displays for each function
	algorithm.BubbleSortTime();
	algorithm.displayBubble();

	algorithm.InsertionSortTime();
	algorithm.displayInsertion();

	algorithm.SelectionSortTime();
	algorithm.displaySelection();

	algorithm.QuickSortTime();
	algorithm.displayQuick();


	return 0;
}
