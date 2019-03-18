//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the Student class and implementation for assignment 5

#include "Student.h"
#include <stdlib.h>

using namespace std;

//all constructors
Student::Student()
{
	studentID = 0;
	name = "";
	classStanding = "";
	major = "";
	GPA = 0.0;
	advisor = 0;
}

Student::Student(int newID, string newName, string newStanding, string newMajor, double newGPA, int newAdvisor)
{
	studentID = newID;
	name = newName;
	setStanding(newStanding);
	major = newMajor;
	setGPA(newGPA);
	//GPA = newGPA;
	advisor = newAdvisor;
}

Student::Student(string newName, string newStanding, string newMajor, double newGPA, int newAdvisor)
{
	studentID = makeID();
	name = newName;
	setStanding(newStanding);
	major = newMajor;
	setGPA(newGPA);
	//GPA = newGPA;
	advisor = newAdvisor;
}

Student::Student(Student & newStudent)
{
	studentID = newStudent.studentID;
	name = newStudent.name;
	classStanding = newStudent.classStanding;
	major = newStudent.major;
	GPA = newStudent.GPA;
	advisor = newStudent.advisor;
}

//deconstructor
Student::~Student()
{

}

//makes ID
int Student::makeID()
{
	return rand() % 9000 +1000;
}

/*These are the getter functions for the Student class
 *
 */
int Student::getID()
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

/*These are the Setter functions for the Student class
 *
 */
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
	if(newStanding== "Freshmen" || newStanding == "freshmen" 
		|| newStanding == "Sophomore" || newStanding == "sophomore"
		|| newStanding == "Junior" || newStanding == "junior"
		|| newStanding == "Senior" || newStanding == "senior")
	{
		classStanding = newStanding;
	}
	else
	{
		cout << "Invalid classStanding, failure!" << endl;
	}
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
	cout <<"ADVISOR PAART IS WORKING : " << advisor << endl;
}

//overloaded operators
bool operator < (Student &s1, Student & s2)
{
	return s1.getID() < s2.getID();
}

bool operator > (Student &s1, Student & s2)
{
	return s1.getID() > s2.getID();
}

bool operator == (Student &s1, Student &s2)
{
	return s1.getID() == s2.getID();
}
bool operator != (Student &s1, Student &s2)
{
	return s1.getID() != s2.getID();
}

//display function
void Student::display()
{
	cout << endl;
	cout <<"Students name: " << name << endl;
	cout << "Students class Standing: " << classStanding << endl;
	cout << "Students ID: " << studentID << endl;
	cout << "Student advisor: " << advisor << endl;
	cout << endl;
}
