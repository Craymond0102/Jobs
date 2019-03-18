//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the Falculty class and implementation for assignment 5

#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Serializable.h"

using namespace std;

//faculty class, and is serializable
class Faculty : public Serializable
{
	public:
		//constructors
		Faculty();
		Faculty(string name, string level, string department, int student[], int size);
		Faculty(int newID, string name, string level, string department, int student);
		~Faculty();	//deconstructors

		int makeID();	//makes Id for faculty

		//overloaded operators
		friend bool operator < (Faculty &s1, Faculty & s2);
		friend bool operator > (Faculty &s1, Faculty & s2);
		friend bool operator == (Faculty &s1, Faculty & s2);
		friend bool operator != (Faculty &s1, Faculty & s2);

		//serialiable functions
		virtual void serialize(ostream & stream)
		{
			stream << facultyID << ' ' << name << ' ' << level << ' ' << department << ' ';
			stream << studentListSize << ' ';
			for(int i = 0; i < studentListSize; ++i)
			{
				stream << studentList[i] << ' ';
			}
			stream << endl;
		}

		virtual void deserialize(istream & stream)
		{
			stream >> facultyID >> name >> level >> department >> studentListSize;
			for(int i = 0; i < studentListSize; ++i)
			{
				stream >> studentList[i];
			}

		}

		//getters and setters
		int getID();
		int * getStudentList();
		int getSize();
		void addAdvisee(int ID);
		void removeAdvisee(int ID);

		void display();

	private:
		//Faculty information
		int facultyID;
		string name;
		string level;
		string department;
		int * studentList ;	//Faculty can have at max 10 students
					//if full, students must find another faculty member
		int studentListSize;
};

#endif
