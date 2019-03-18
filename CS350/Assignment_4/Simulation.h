//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the simulation class that manages reading in the files

#include "Queue.h"
#include "Window.h"
//#include "Student.h"

using namespace std;

class Simulation
{
	public:
		Simulation();
		~Simulation();
		void addStudent(int time, int waitTime);	//adds a student to the queue
		void writeInFile(string filename);		//writes in the files
		void windowsOpen(int amount);			//makes widows open

		void studentSimulation(int openWindows); 	//the actual simulation
		void openRegister(int openWindows, int count);	//puts studenst in line in a register
		void wait();	//waits for timer
		void display();	//dispaly for me
		void studentDone(int openWindows);	//when students are done
		bool isOpen(int openWindows);	//checks to see if all windows are open

		bool checkTime(int index);	//checks the Time

		void calculateLongestWait(int newWait);	//calcultes longest wait
		double calculateMeanStudentWait();	//calculates mean student wait time

		void windowIdleTime(int openWindows);	//calculates window idle time
		double calculateMeanWindowWait(int openWindows); 	//calculates mean window wait times

		void windowsOverFive(int openWindows);	//calculates windows over 5 minuets
		void calculateLongestWindowWait(int openWindows);	//calculates longest window wait


	private:
		Window window[5];
		Queue<Student> queue;

		int time;		//total timer for the simulation
		int startingTime;	//starting time of when students show up
		int studentTen;		//students over ten minutes waitign
		int windowFive;		//windows waiting for over 5 minutes
		int studentLongestWait;	//students longest wait
		int windowLongestWait;	//windows longest wait
		double totalWaitTime;	//TOTAL WAIT TIME for students
		double totalWindowWait;	//total window wait time
};
