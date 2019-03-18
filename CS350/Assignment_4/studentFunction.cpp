//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//this is the file for the functions for the student class

#include <ctime>
#include "Student.h"
#include "unistd.h"

using namespace std;

//initializer
Student::Student()
{
	completionTime = 0;
	totalWait = 0;
	arrivalTime = 0;
	inLine = 0;
}

//constructor, set values
Student::Student(int newArrivalTime, int newCompletionTime)
{
	completionTime = newCompletionTime;
	totalWait = 0;
	arrivalTime = newArrivalTime;
	inLine = 1;
}

//nothing dynamic, nothing to do 
Student::~Student()
{

}

//display, mainly for me
void Student::display()
{
	cout << "The time this student took to complete their action: " << completionTime <<endl;
	cout << "The time this student waited in line: " << totalWait << endl;
	cout << "The time this student arrived: " << arrivalTime << endl;
}

//setter functions to aid adt
void Student::setCompletionTime(int newCompletionTime)
{
	completionTime = newCompletionTime;
}

void Student::setTotalWait(double newTotalWait)
{
	totalWait = newTotalWait;
}

void Student::setArrivalTime(int newArrivalTime)
{
	arrivalTime = newArrivalTime;
}

void Student::setInLine(int newInLine)
{
	inLine = 0;
}

//getter functions to aid adt
int Student::getCompletionTime()
{
	return completionTime;
}

int Student::getTotalWait()
{
	return totalWait;
}

int Student::getArrivalTime()
{
	return arrivalTime;
}

int Student::getInLine()
{
	return inLine;
}
