//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//this is the Window class for Assignment 4

#include "Student.h"
#include <iostream>
#include <fstream>

using namespace std;


class Window
{
	public:
		//constructor and deconstructor
		Window();
		~Window();

		void setOpen(int newOpen);	//setter and getter for if the window is open
		int getOpen();

		void setIdleTime(int newTime);	//setter and gett for the window idle tiem
		int getIdleTime();

		int getTotalStudentTime();	//getter and setter for total student tiem
		void setTotalStudentTime();

		int getTotalWait();	//getters for total wait, and arrival time
		int getArrivalTime();
		int getStudentArrivalTime(Student newStudent);

		void setStudent(Student newstudent, int totalTime);	//sets the student in the queue
		void display();

	private:
		
		Student student;	//student within the window
		int open;		//1 = window is open, 0 is closed
		int totalStudentTime;	//total student time
		int idleTime;		//idle time 

};

