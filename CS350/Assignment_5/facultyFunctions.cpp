//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .cpp file for Faculty class functions for assignment 5


#include "Faculty.h"
#include <stdlib.h>


using namespace std;

//constructors
Faculty::Faculty()
{
	facultyID = 0;
	name = "";
	level = "";
	department = "";
	studentList = new int[10];
}

Faculty::Faculty(string newName, string newLevel, string newDepartment, int newStudent[], int size)
{
	facultyID = makeID();
	name = newName;
	level = newLevel;
	department = newDepartment;
	studentList = new int[10];
	cout <<"WORKING" << endl;

	for(int i = 0; i < size; ++i)
	{
		studentList[i] = newStudent[i];
	}
	studentListSize = size;
	cout << "WORKING" << endl;
}

Faculty::Faculty(int newID, string newName, string newLevel, string newDepartment, int newStudent)
{
	facultyID = newID;
	name = newName;
	level = newLevel;
	department = newDepartment;
	studentList = new int[10];
	studentList[0] = newStudent;
	studentListSize++;
}

//deconstructor
Faculty::~Faculty()
{
}

//makes ID
int Faculty::makeID()
{
	return rand() % 90000 +10000;
}

//getters
int Faculty::getID()
{
	return facultyID;
}

int* Faculty::getStudentList()
{
	return studentList;
}

int Faculty::getSize()
{
	return studentListSize;
}

//overloaded operators
bool operator < (Faculty &s1, Faculty & s2)
{
	return s1.getID() < s2.getID();
}

bool operator > (Faculty &s1, Faculty & s2)
{
	return s1.getID() > s2.getID();
}

bool operator == (Faculty &s1, Faculty & s2)
{
	return s1.getID() == s2.getID();
}
bool operator != (Faculty &s1, Faculty & s2)
{
	return s1.getID() != s2.getID();
}

//displays
void Faculty::display()
{
	cout << endl;
	cout <<"Faculty's name: " << name << endl;
	cout <<"Faculty's Level: " << level<< endl;
	cout <<"Faculty's department: " << department<< endl;
	//cout <<"Faculty members students: " << studentList[0]<< endl;
	cout <<"Faculty's ID: " << facultyID<< endl;
	cout << endl;
}

//adds student
void Faculty::addAdvisee(int ID)
{
	if(studentListSize < 10)
	{
		//++studentListSize;
		studentList[studentListSize] = ID;
		++studentListSize;
	}

}


//removes student
void Faculty::removeAdvisee(int ID)
{
	int i = 0;
	int j = 0;
	int newArray[10]; 
	if(studentListSize >= 0)
	{
		while(i < (studentListSize -1))
		{

			if(studentList[i] != ID)
			{
				newArray[i] = studentList[j];
				++i;
				++j;
			}
			++j;
		}

		--studentListSize;

		for(int k = 0; k < studentListSize; ++k)
		{
			studentList[k] = newArray[k];
		}
	}

}
