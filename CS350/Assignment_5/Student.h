//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the Student class and implementation for assignment 5

#ifndef STUDENT_H
#define STUDENT_H
//#endif
#include <iostream>
#include <ostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Serializable.h"

using namespace std;

//Student class, and is serializable
class Student : public Serializable
{
	public:	
		Student();	//these are all the different constructors
		Student(Student & newStudent);
		Student(int newID, string newName, string newStanding, string newMajor, double newGPA, int newAdvisor);
		Student(string newName, string newStanding, string newMajor, double newGPA, int newAdvisor);
		~Student();	//deconstructor

		friend bool operator < (Student &s1, Student & s2);	//these are all the overloaded operators
		friend bool operator > (Student &s1, Student & s2);
		friend bool operator == (Student &s1, Student &s2);
		friend bool operator != (Student &s1, Student &s2);

		//serializable functions
		virtual void serialize(ostream & stream)
		{
			stream << studentID << ' ' << name << ' ' << classStanding << ' ' << major << ' ';
			stream <<  GPA <<' ' <<  advisor << endl;
		}
		
		virtual void deserialize(istream & stream)
		{
			stream >> studentID;
			stream >> name;
			stream >> classStanding;
			stream >> major;
			stream >> GPA;
			stream >> advisor;	
		}

		//getters
		int getID();
		string getName();
		string getClassStanding();
		string getMajor();
		double getGPA();
		int getAdvisor();

		//setters
		void setID(int newID);
		void setName(string newName);
		void setStanding(string newStanding);
		void setMajor(string newMajor);
		void setGPA(double newGPA);
		void setAdvisor(int newAdvisor);

		//makes ID
		int makeID();
		//displays
		void display();


	private:
		//information for student
		int studentID;
		string name;
		string classStanding;
		string major;
		double GPA;
		int advisor;
};
//#endif

/*
Student::Student()
{

}

Student::Student(int newID, string newName, string newStanding, string newMajor, double newGPA, int newAdvisor)
{
	studentID = newID;
	name = newName;
	classStanding = newStanding;
	major = newMajor;
	GPA = newGPA;
	advisor = newAdvisor;
}
*/
/*
Student::~Student()
{

}
*/

/*These are the getter functions for the Student class
 *
 */
/*
int Student::getStudentID()
{
	return studentID;
}

string Student::getName()
{
	return name;
}

string Student::getClassStanding()
{
	return classStanding;
}

string Student::getMajor()
{
	return major;
}

double Student::getGPA()
{
	return GPA;
}

int Student::getAdvisor()
{
	return advisor;
}
*/
/*These are the Setter functions for the Student class
 *
 */
/*
void Student::setID(int newID)
{
	studentID = newID;
}

void Student::setName(string newName)
{
	name = newName;
}

void Student::setStanding(string newStanding)
{
	classStanding = newStanding;
}

void Student::setMajor(string newMajor)
{
	major = newMajor;
}

void Student::setGPA(double newGPA)
{
	if(newGPA <= 4.0)
	{
		GPA = newGPA;
	}
	else
	{
		cout << "Invalid GPA, sorry!" << endl;
	}
}

void Student::setAdvisor(int newAdvisor)
{
	advisor = newAdvisor;
}

bool operator < (Student &s1, Student & s2)
{
	return s1.getStudentID() < s2.getStudentID();
}

bool operator > (Student &s1, Student & s2)
{
	return s1.getStudentID() > s2.getStudentID();
}

*/
#endif //STUDENT_H
