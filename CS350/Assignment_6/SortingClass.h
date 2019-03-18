//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h main class file for assignment 6, containing the class to hold all sorting algorithms

#ifndef SORTINGCLASS_H
#define SORTINGCLASS_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <math.h>

using namespace std;

class Sorting
{
	public:
		//constructors & deconstructors
		Sorting();
		Sorting(int size);
		~Sorting();

		//file IO
		int writeInSize(string filename);
		void writeInArray(string filename);


		//algorithms, displays, and time functions
		void BubbleSort();
		void BubbleSortTime();
		void displayBubble();

		void InsertionSort();
		void InsertionSortTime();
		void displayInsertion();

		void SelectionSort();
		void SelectionSortTime();
		void displaySelection();

		void QuickSort();
		void QuickSort(double * copyQuick, int left, int right);
		int partition(double * copyQuick, int left, int right);
		void QuickSortTime();
		void displayQuick();
		

	private:
		//the arrays for each algorithm
		double * Bubble;
		double * Insertion;
		double * Quick;
		double * Selection;

		//size for each array initialize
		int size;
};
#endif
