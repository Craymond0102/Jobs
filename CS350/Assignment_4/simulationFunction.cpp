//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the function file for the simulation class

#include "Simulation.h"
#include "unistd.h"

using namespace std;

//constructor
Simulation::Simulation()
{
	time = 0;
	studentTen = 0;
	windowFive = 0;
	studentLongestWait = 0;
	windowLongestWait = 0;
	totalWaitTime = 0;
	totalWindowWait = 0;
	startingTime = 0;
}

//deconstructor... nothing dynamically allocated so nothing to do
Simulation::~Simulation()
{
}

//adds a student to the queue
void Simulation::addStudent(int time, int completionTime)
{
	Student student(time, completionTime);
	queue.enqueue(student);
}

//reads in from a file and places the data in the correct order given by the 
//assignment prompt
//
//this function also calls the simulation function and outputs the data 
//to the console for the user
void Simulation::writeInFile(string filename)
{
	cout << "Starting simulation" << endl;
	fstream file_in(filename);
	int count = 0;
	int innerCount;
	int value = 0;
	int time = 0;
	int studentNumber =0;
	int openWindows = 0;
	int firstPass = 0;

	if(file_in)
	{
		if(file_in.is_open())
		{
			while(file_in >> value && !file_in.eof())
			{
				if(count == 0)
				{
					openWindows = value;
					windowsOpen(openWindows);	
				}
				else if(count == 1)
				{
					if(firstPass == 1)
					{
						startingTime = value;
					}
					time = value;
				}
				else if(count == 2)
					studentNumber = value;
				else if(studentNumber > innerCount)
				{
					addStudent(time, value);
					++innerCount;
					if(innerCount == studentNumber)
					{
						count = 0;
						innerCount = 0;
						studentNumber = 0;
					}

				}
				else
				{
					return;
				}
				++count;
				++firstPass;

			}
			studentSimulation(openWindows);
			windowsOverFive(openWindows);
			calculateLongestWindowWait(openWindows);
		}
	}
	else
	{
		cout << "The file does not exist" << endl;
		return;
	}

	cout << "The amount of students with a wait time of ten or more is: " << studentTen << endl;
	cout << "The longest wait is: " << studentLongestWait << endl;
	cout << "The mean student wait time is: " << calculateMeanStudentWait() << endl;

	cout << "The mean window wait time is: " << calculateMeanWindowWait(openWindows) << endl;
	cout << "Windows idle for over 5 minutes: " << windowFive << endl;
	cout << "Longest window wait: " << windowLongestWait << endl;

}

//sets windows to be open
void Simulation::windowsOpen(int amount)
{
	for(int i = 0; i < amount; ++i)
	{
		window[i].setOpen(1);
	}
}

//starts the student simulation
void Simulation::studentSimulation(int openWindows)
{
	bool again = false;
	int count = 0;

	while(queue.isEmpty() == false )
	{
		openRegister(openWindows, count);
		wait();
		windowIdleTime(openWindows);
		studentDone(openWindows);
		again = isOpen(openWindows);

		++count;
	}
}

//checks for an open register and then based on the time of when the student arrived
//sets the student to the register
void Simulation::openRegister(int openWindows, int count)
{
	for(int i = 0; i < openWindows; ++i)
	{
		if(window[i].getOpen() == 1 && queue.isEmpty() == false && checkTime(i) == true)
		{
				window[i].setStudent(queue.dequeue(), time);
		

				if(window[i].getTotalWait() >= 10)
				{
					++studentTen;
				}
			
				calculateLongestWait(window[i].getTotalWait());//- ((time * 60) - window[i].getArrivalTime())));
				totalWaitTime += window[i].getTotalWait();//- ((time * 60) - window[i].getArrivalTime()));

				window[i].setOpen(0);
			//}
		}
	}
}

//waits one unit of time for my clock calculations
void Simulation::wait()
{
	usleep(25000);
	++time;
}

//checks if a student is done based upon their completion time at the register
void Simulation::studentDone(int openWindows)
{
	for(int i = 0; i < openWindows; ++i)
	{
		int theTotalTime = 0;
		theTotalTime = window[i].getTotalStudentTime() + ((window[i].getArrivalTime() * 60) - startingTime * 60);

		if(window[i].getTotalStudentTime() == time || (window[i].getOpen() == 0 && theTotalTime == time))
		{
			window[i].setTotalStudentTime();
			window[i].setOpen(1);
		}
	}
}

//displays, mainly for me
void Simulation::display()
{
	for(int i = 0; i < 5; ++i)
	{
		if(window[i].getOpen() == 1)
		{
			window[i].display();
		}
	}
}

//checks the next in line if its time for them to go to the register
bool Simulation::checkTime(int index)
{
	int studentTime = (window[index].getStudentArrivalTime(queue.peek())) * 60;
	int passingTime = time + (startingTime * 60);
	if(window[index].getArrivalTime() == 0 )
	{
		return true;
	}
	else if(window[index].getArrivalTime() == window[index].getStudentArrivalTime(queue.peek()))
	{
		return true;
	}
	else if(studentTime <= passingTime)
	{
		return true;
	}
	return false;
}

//checks if all the windows are open
bool Simulation::isOpen(int openWindows)
{
	int count = 0;

	for(int i = 0; i < openWindows; ++i)
	{
		if(window[i].getOpen() == 1)
		{
			++count;
		}
	}

	if(count == 5)
	{
		return true;
	}
		return false;
}

//calculates the longest wait for the students
void Simulation::calculateLongestWait(int newWait)
{
	if(newWait > studentLongestWait)
		studentLongestWait = newWait;
}

//calculates the mean wait time for students
double Simulation::calculateMeanStudentWait()
{
	return	totalWaitTime / queue.getSize(); 
}

//calculates the window idle timer
void Simulation::windowIdleTime(int openWindows)
{
	for(int i = 0; i < openWindows; ++i)
	{
		if(window[i].getOpen() == 1 )//&& checkTime(i) == true)
		{
			window[i].setIdleTime(1);
			++totalWindowWait;// += window[i].getIdleTime();

		}
	}
}

//checls for the mean window wait time
double Simulation::calculateMeanWindowWait(int openWindows)
{
	return totalWindowWait / (double) openWindows;
}

//checks for every window idle for over 5 minutes
void Simulation::windowsOverFive(int openWindows)
{
	for(int i = 0; i < openWindows; ++i)
	{
		if(window[i].getIdleTime() >= 5)
		{
			++windowFive;
		}
	}
}

//calculates the longest window wait
void Simulation::calculateLongestWindowWait(int openWindows)
{
	for(int i = 0; i < openWindows; ++i)
	{
		if(window[i].getIdleTime() > windowLongestWait)
		{
			windowLongestWait = window[i].getIdleTime();
		}
	}
}
