//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the .cpp Main file for assignment 5

#include "Function.h"
#include "BST.h"
#include "Student.h"
#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;


int main()
{

	Function program; 	//create instance of class for project

	
	//variables for console
	bool again = false;
	int input = 0;
	string answer = "";

	program.writeIn();	//writes in the BST from file
	while(!again)
	{
		//all cases
		cout << "Case 1: Add a student to the records" << endl;
		cout << "Case 2: Add a Faculty to the records" << endl;
		cout << "Case 3: Dislay student tree" << endl;
		cout << "Case 4: Dislay faculty tree" << endl;
		cout << "Case 5: Display student based on ID#" << endl;
		cout << "Case 6: Display Faculty based on ID#" << endl;
		cout << "Case 7: Display a students faculty advisor, based on the students ID" << endl;
		cout << "Case 8: Display a Faculty's list of students" << endl;
		cout << "Case 9: Change a students advisor, please give the student ID and new faculty ID" << endl;
		cout << "Case 10: Remove an advisee from a faculty member" << endl;
		cout << "Case 11: Delete a student from the records" << endl;
		cout << "Case 12: Delete a Faculty member from the records" << endl;
		cout << "Case 13: Rollback" << endl;
		cout << "Case 14: Exit" << endl;

		cout << "Please enter a number for the case you would like to test" << endl;
		cout << "Input: ";
		cin >> input;
		cin.ignore(100, '\n');


		//switch statements
		switch(input)
		{
			case 1:
				program.addStudent();
				break;
			case 2:
				program.addFaculty();
				break;
			case 3:
				program.printAllStudent();
				break;
			case 4:
				program.printAllFaculty();
				break;
			case 5: 
				program.printStudentID();
				break;
			case 6: 
				program.printFacultyID();
				break;
			case 7:
				program.findFacultyStudentID();
				break;
			case 8:
				program.findStudentFacultyID();
				break;
			case 9: 
				program.changeStudentAdvisor();
				break;
			case 10:
				program.changeAdvisorStudent();
				break;
			case 11: 
				program.deleteStudent();
				break;
			case 12:
				program.deleteFaculty();
				break;
			case 13:
				program.rollBack();
				break;
			case 14:
				again = true;
				break;
			default:
				cout <<"Wrong input"<< endl;
				break;
		}
	}

	//writes out to file
	program.writeOut();

	return 0;
}
