//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .h file for the actualy assignment class and implementation for assignment 5

#ifndef FUNCTION_H
#define FUNCTION_H
//#endif

#include <iostream>
#include "BST.h"
//#include "Student.h"

using namespace std;

//this class handles the actions for the database
class Function
{
	public:
		Function();
		~Function();
		
		void addStudent();	//adds students
		void addFaculty();	//adds faculty
		
		void deleteStudent();	//delets student
		void deleteFaculty();	//deletes faculty

		void printAllStudent();	//prints all students
		void printAllFaculty();	//prints all faculty

		void printStudentID();	//prints the student based on ID
		void printFacultyID();	//prints based on Faculty

		void updateStudentTable();	//these do not work... rollback does not work
		void studentTableRollback();	//same ^

		void updateFacultyTable();	//same^
		void facultyTableRollback();	//same^
		void rollBack();		//same^

		void findFacultyStudentID();	//finds a students faculty member
		void findStudentFacultyID();	//finds the faculty members students

		void changeStudentAdvisor();	//change the students advisor
		void changeAdvisorStudent();	//changes the faculty's students

		void writeOut();	//writes out to file
		void writeIn();		//writes in from file

	private:
		BST<Student> studentTable;	//student BST 
		BST<Student>  Table[5];		//doesn't work, but was for rollback
		BST<Faculty> facultyTable;	//faculty BST
		BST<Faculty> rollbackFaculty[5];	//doesn't work, but was for rollback

		int studentTableTop;	//for rollback
		int studentTableSize;	//for rollback

		int facultyTableTop;	//for rollback
};


#endif
