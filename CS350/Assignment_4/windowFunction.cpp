//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the function file for the window class

#include "Window.h"

using namespace std;

Window::Window()
{
	open = 0;
	totalStudentTime = 0;
	idleTime = 0;
}
Window::~Window()
{
}

//setter functions
void Window::setOpen(int newOpen)
{
	open = newOpen;
}

void Window::setTotalStudentTime()
{
}

void Window::setIdleTime(int newTime)
{
	idleTime += newTime;
}

//getter functions
int Window::getArrivalTime()
{
	return student.getArrivalTime();
}
int Window::getOpen()
{
	return open;
}

int Window::getTotalStudentTime()
{
	return totalStudentTime;
}

int Window::getIdleTime()
{
	return idleTime;
}


//sets the student values
void Window::setStudent(Student newStudent, int totalWait)
{
	student.setCompletionTime(newStudent.getCompletionTime());
	student.setTotalWait(totalWait);
	student.setArrivalTime(newStudent.getArrivalTime());
	student.setInLine(newStudent.getInLine());
	totalStudentTime += student.getCompletionTime();
}

//More getters
int Window::getStudentArrivalTime(Student newStudent)
{
	return newStudent.getArrivalTime();
}


int Window::getTotalWait()
{
	return student.getTotalWait();
}

//display, for me
void Window::display()
{
	cout << "Completion Time: " << student.getCompletionTime() << endl;
	cout << "Wait time so far: " << student.getTotalWait() << endl;
	cout << "Arrival Time: " << student.getArrivalTime() << endl;
	cout << "In Line " << student.getInLine() << endl;
	cout << "Idle time for this window: " << idleTime << endl;
}
