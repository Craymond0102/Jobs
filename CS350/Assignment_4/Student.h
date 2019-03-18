//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the Student class



#include <iostream>
#include <fstream>
//#include "Queue.h"

using namespace std;

//student class to keep information about the student
class Student
{
	public:
		Student();	//basic initializer
		Student(int newArrivalTime, int newCompletionTime);	//constructor
		~Student();	//deconstructor
		void display();	//dispaly (for me)

		void setCompletionTime(int newCompletionTime);	//setters for the data within studetn
		void setTotalWait(double newTotalWait);
		void setArrivalTime(int newArrivalTime);
		void setInLine(int newInLine);

		int getCompletionTime();	//getters for the data within studetn
		int getTotalWait();
		int getArrivalTime();
		int getInLine();


	private:
		int completionTime;
		double totalWait;
		int arrivalTime;
		int inLine;
};
