//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .cpp sorting class file for assignment 6

#include "SortingClass.h"
#include <ctime>
#include <time.h>

using namespace std;

//constructors
Sorting::Sorting()
{
	size = 0;
	Bubble = NULL;
	Insertion = NULL;
	Quick = NULL;
}

//initialize
Sorting::Sorting(int theSize)
{
	size = theSize;

	Bubble = new double[theSize];
	Insertion = new double[theSize];
	Quick = new double[theSize];
	Selection = new double[theSize];
}

//deconstructors
Sorting::~Sorting()
{
	delete [] Bubble;
	delete [] Insertion;
	delete [] Quick;
}

//writes in the size of the array
int Sorting::writeInSize(string filename)
{
	ifstream file_in(filename);

	string line;
	int count = 1;
	int value = 0;

	if(file_in.is_open())
	{
		while(getline(file_in, line) && !file_in.eof())
		{
			if(count == 1)
			{
				value = stoi(line);
				return value;
			}
		}

	}
	return value;
}

//writes in the numbers from the file into the array - one number every line
void Sorting::writeInArray(string filename)
{
	ifstream file_in(filename);

	string line;
	int count = 0;
	double value = 0.0;
	int index = 0;

	if(file_in.is_open())
	{
		while(getline(file_in, line) && !file_in.eof())
		{
			if(count != 0)
			{
				value = stod(line);

				//arrays;
				Bubble[index] = value;
				Insertion[index] = value;
				Quick[index] = value;
				Selection[index] = value;
				++index;
			}
			 
			++count;
		}
	}
}

//bubble sort
void Sorting::BubbleSort()
{
	double temp;
	bool check = true;
	int end = 0;

	while(check)
	{
		end++;
		check = false;

		for(int i = 0; i < size-end; ++i)
		{
			if(Bubble[i] > Bubble[i+1])
			{
				temp = Bubble[i];
				Bubble[i] = Bubble[i+1];
				Bubble[i+1] = temp;
				check = true;
			}
		}

	}
	
}

//gets the time for bubble sort
void Sorting::BubbleSortTime()
{
	clock_t t;
	t = clock();

	BubbleSort();

	t = clock() - t;

	cout << "time for Bubble sort: " << t << " miliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

}

//insertion sort
void Sorting::InsertionSort()
{
	int j = 0;
	for(int i = 1; i < size; ++i)
	{
		double temp = Insertion[i];
		j = i-1;

		while(j >= 0 && Insertion[j] > temp)
		{
			Insertion[j+1] = Insertion[j];
			--j;
		}
		Insertion[j+1] = temp;
	}
}

//gets time for insertion sort
void Sorting::InsertionSortTime()
{
	clock_t t;
	t = clock();

	InsertionSort();

	t = clock() - t;

	cout << "time for Insertion Sort: " << t << " miliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

}

//selection sort
void Sorting::SelectionSort()
{
	int minIndex = 0;
	double temp = 0;

	for(int i = 0; i < size-1; ++i)
	{
		minIndex = i;
		for(int j = i+1; j<size; ++j)
		{
			if(Selection[j] < Selection[minIndex])
				minIndex = j;
		}
			if(minIndex != i)
			{
				temp = Selection[i];
				Selection[i] = Selection[minIndex];
				Selection[minIndex] = temp;
			}
	}
}

//gets the time for selection sort
void Sorting::SelectionSortTime()
{
	clock_t t;
	t = clock();

	SelectionSort();

	t = clock() - t;

	cout << "time for Selection sort: " << t << " miliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

}

//quick sort wrapper
void Sorting::QuickSort()
{
	int n= sizeof(Quick)/sizeof(Quick[0]);

	QuickSort(Quick, 0, n);
}

//quick sort function
void Sorting::QuickSort(double * copyQuick, int left, int right)
{
	if(right > left)
	{
		int p = partition(Quick, left, right);
		QuickSort(copyQuick, left, p-1);
		QuickSort(copyQuick, p + 1, right);
	}
}

//partition
int Sorting::partition(double * copyQuick, int left, int right)
{
	int i = left;
	int j = right;
	double temp = 0;
	int pivot = copyQuick[(left+right) / 2];

	/*Partition*/

	while(i < j)
	{
		while(copyQuick[i] < pivot)
			++i;
		while(copyQuick[j] > pivot)
			--j;
		if(i < j)
		{
			temp = copyQuick[i];
			copyQuick[i] = copyQuick[j];
			copyQuick[j] = temp;
			//++i;
			//--j;
		}
	}

	return i;
}

//gets time for quick sort
void Sorting::QuickSortTime()
{
	clock_t t;
	t = clock();

	QuickSort();

	t = clock() - t;

	cout << "time for Quick sort: " << t << " miliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

}

//displays functions for all arrays
void Sorting::displayQuick()
{
	for(int i = 0; i < size; ++i)
	{
		cout << Bubble[i] << "|";
	}
	cout << endl;
}


void Sorting::displayBubble()
{
	for(int i = 0; i < size; ++i)
	{
		cout << Bubble[i] << "|";
	}
	cout << endl;
}

void Sorting::displayInsertion()
{
	for(int i = 0; i < size; ++i)
	{
		cout << Insertion[i] << "|";
	}
	cout << endl;
}

void Sorting::displaySelection()
{
	for(int i = 0; i < size; ++i)
	{
		cout << Selection[i] << "|";
	}
	cout << endl;
}
