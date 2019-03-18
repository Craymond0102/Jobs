//Charlie Raymond, 2306164, raymond@chapman.edu, Rene German, CPCS350
//This is the Function .cpp file for Assingment 5, which simulates a

#include "Function.h"
#include "BST.h"
using namespace std;

//constructor
Function::Function()
{
	studentTableTop = -1;
	studentTableSize = 0;

	facultyTableTop = -1;
}

//deconstructor
Function::~Function()
{

}

//prints all students
void Function::printAllStudent()
{
	studentTable.display();
}
//prints all faculty
void Function::printAllFaculty()
{
	facultyTable.display();
}

//adds student
void Function::addStudent()
{
	int ID = 0;
	string name = "";
	string classStanding = "";
	string major = "";
	double GPA = 0.0;
	int advisor = 0;


	cout <<"What is the students name"<< endl;
	cin >> name;
	cin.ignore(100, '\n');

	cout <<"What is the students class standing? " << endl;
	cin >> classStanding;
	cin.ignore(100, '\n');

	cout <<"What is the students Major?" << endl;
	cin >> major;
	cin.ignore(100, '\n');

	cout <<"What is the students GPA?" << endl;
	cin >> GPA;
	cin.ignore(100, '\n');

	cout << "What is their advisors ID?" << endl;
	cin >> advisor;
	cin.ignore(100, '\n');

	Student newStudent(name, classStanding, major, GPA, advisor);
	Faculty newFaculty(advisor, "Filler", "filler", "Filler", 9999);

	if(studentTable.search(newStudent) == false && facultyTable.search(newFaculty) == false)
	{
		if(studentTable.insert(newStudent) == true)
		{
			//updateStudentTable();	//doesn't work
			cout << "Success" << endl;
		}
		else
			cout <<"Failure" << endl;
	}
	else
		cout <<"This student or faculty is already in our system based on corresponding ID's, please try again" << endl;

}

//adds faculty
void Function::addFaculty()
{
	string name = "";
	string level = "";
	string department = "";
	int studentID = 0;
	int student[10];
	string answer = "";
	int count = 0;

	cout <<"What is the Faculty's name? " << endl;
	cin >>name; 
	cin.ignore(100, '\n');

	cout <<"What is the Faculty's level? " << endl;
	cin >>level; 
	cin.ignore(100, '\n');

	cout <<"What department is this Faculty member apart of? " << endl;
	cin >>department; 
	cin.ignore(100, '\n');

	do{

		cout <<"Who is the Faculty member a mentor for? (Will prompt for as many as 10 ID's? " << endl;
		cin >>studentID; 
		cin.ignore(100, '\n');

		Student newStudent(studentID, "charlie", "junior", "cs", 3.0, 432);

		if(studentTable.search(newStudent) == false)
		{
			cout << "Sorry that does not match our records, student does not exist" << endl;
			cout << "please try again" << endl;
		}
		else
		{
			student[count] = studentID;
			++count;
		}

		cout << "Would you like to enter in another ID? (yes/no)" << endl;
		cin >> answer;
		cin.ignore(100, '\n');

	}while((answer == "Yes" || answer == "yes") && count < 10);


	Faculty newFaculty(name, level, department, student, count);

	if(facultyTable.insert(newFaculty) == true)
	{
		//updateFacultyTable();	//doesn't work
		cout << "Success" << endl;
	}
	else
		cout <<"Failure" << endl;

	//updateFacultyTable();
}

//deletes student
void Function::deleteStudent()
{
	int ID = 0;

	cout << "What is the students ID?" << endl;
	cin >> ID;
	cin.ignore(100, '\n');

	Student newStudent(ID, "filler", "junior", "filler", 3.0, 9999);

	studentTable.deleteNode(newStudent);
}

//deletes faculty
void Function::deleteFaculty()
{
	int ID = 0;

	cout << "What is the Faculty's ID?" << endl;
	cin >> ID;
	cin.ignore(100, '\n');

	Faculty newFaculty(ID, "Filler", "filler", "Filler", 9999);

	facultyTable.deleteNode(newFaculty);

}

//prints based on student id
void Function::printStudentID()
{
	string name = "";
	string major ="";
	string classStanding= "freshmen";
	int ID = 0;
	double GPA = 0.0;
	int advisor = 0;

	cout << "What is the students ID that you would like to look for? " << endl;
	cin >> ID;
	cin.ignore(100, '\n');

	Student newStudent(ID, name, classStanding, major, GPA, advisor);

	if(studentTable.search(newStudent) == true)
	{
		cout << "A match was found!!" << endl;
		Student newerStudent;
	       	newerStudent =	studentTable.searchID(newStudent);
		newerStudent.display();
	}
	else
		cout <<"No match was found" << endl;
		
}

//prints based on faculty ID
void Function::printFacultyID()
{
	int ID = 0;
	string name = "";
	string level = "";
	string department = "";
	int student =  0;

	cout << "What is the Facutly's ID that you would like to look for? " << endl;
	cin >> ID;
	cin.ignore(100, '\n');

	Faculty newFaculty(ID, name, level, department, student);

	if(facultyTable.search(newFaculty) == true)
	{
		cout << "Match FOunD!" << endl;

		Faculty newerFaculty;
		newerFaculty = facultyTable.searchID(newFaculty);
		newerFaculty.display();
		
	}
	else
		cout <<"NO mAtch Found" << endl;
}

//tries to update the array of student BST's, but fails
void Function::updateStudentTable()
{
	if(studentTableTop < 4)
	{
		++studentTableTop;
		cout <<"Index of table is: " << studentTableTop << endl;
		Table[studentTableTop] = studentTable;
		return;
	}

	for(int i = 0; i < 4; ++i)
	{
		Table[i] = Table[i+1];
	}
	Table[4] = studentTable;
}

//student roll back, but fails
void Function::studentTableRollback()
{

	if(studentTableTop >= 0)
	{
		--studentTableTop;
		cout <<"Index of table is: " << studentTableTop << endl;
		studentTable = Table[studentTableTop];
	}
	else
		cout << "Less then 5 actions have been performed!" << endl;
}

//tries to update the array of faculty BST's
void Function::updateFacultyTable()
{
	if(facultyTableTop < 5)
	{
		rollbackFaculty[facultyTableTop] = facultyTable;
		++facultyTableTop;
		return;
	}


	for(int i = 0; i < 4; ++i)
	{
		rollbackFaculty[i] = rollbackFaculty[i+1];
	}

}

//faculty roll back
void Function::facultyTableRollback()
{
	if(facultyTableTop >= 0)
	{
		facultyTable = rollbackFaculty[facultyTableTop];
		--facultyTableTop;	
	}
	else
		cout << "Less then 5 actions have been performed!" << endl;
}


//rollback
void Function::rollBack()
{
	string answer = "";

	cout << "Would you like to roll back the student table or faculty table?" << endl;
	cout << "write 'student' for student table, or 'faculty' for faculty table" << endl;
	cin >> answer;
	cin.ignore(100, '\n');

	if(answer == "student")
	{
		studentTableRollback();
	}
	else if(answer == "faculty")
	{
		facultyTableRollback();
	}
	else
		cout <<"invalid input"<< endl;
}

//finds student based on Fauclty
void Function::findFacultyStudentID()
{
	int ID = 0;

	cout << "What is the students ID?" << endl;
	cin >> ID;
	cin.ignore(100, '\n');

	Student newStudent(ID, "fuller", "junior", "filler", 4.0, 9999);
	Student newerStudent;

	if(studentTable.search(newStudent) == true)
	{
		cout << "A match was found!!" << endl;
	       	newerStudent =	studentTable.searchID(newStudent);
	}
	else
		cout <<"No match was found" << endl;

	cout <<"WORKING THUS FAR" << endl;
	Faculty newFaculty(newerStudent.getAdvisor(), "filler", "filler", "diller", newerStudent.getAdvisor());

	cout <<"WORKING THUS FAR" << endl;
	if(facultyTable.search(newFaculty) == true)
	{
		cout << "Match FOunD!" << endl;

		Faculty newerFaculty;
		newerFaculty = facultyTable.searchID(newFaculty);
		newerFaculty.display();
		
	}
	else
		cout <<"NO mAtch Found" << endl;
}

//finds student based on Fauclty
void Function::findStudentFacultyID()
{
	int ID = 0;
	int size = 0;
	//int studentList[10];

	cout << "What is the Faculty's ID?" << endl;
	cin >> ID;
	cin.ignore(100, '\n');


	Faculty newFaculty(ID, "filler", "filler", "diller", 9999); 
	Faculty newerFaculty;

	if(facultyTable.search(newFaculty) == true)
	{
		cout << "Match FOunD!" << endl;

		newerFaculty = facultyTable.searchID(newFaculty);
		size = newerFaculty.getSize();
		
	}
	else
		cout <<"NO mAtch Found" << endl;

	int * studentList = newerFaculty.getStudentList();

	for(int i = 0; i < size; ++i)
	{
		Student newStudent(studentList[i], "fuller", "junior", "filler", 4.0, 9999);
		Student newerStudent;
	
		if(studentTable.search(newStudent) == true)
		{
			cout << "A match was found!!" << endl;
	       		newerStudent =	studentTable.searchID(newStudent);
			newerStudent.display();
		}
		else
			cout <<"No match was found" << endl;
	}
}

//chantes student advisor
void Function::changeStudentAdvisor()
{

	int ID = 0;
	int newID = 0;

	cout << "What is the students ID?" << endl;
	cin >> ID;
	cin.ignore(100, '\n');

	cout << "What is the new Faculty ID? " << endl;
	cin >> newID;
	cin.ignore(100, '\n');

	Student newStudent(ID, "fuller", "junior", "filler", 4.0, 9999);
	Student newerStudent;

	Faculty newFaculty(newID, "filler", "filler", "diller", 9999); 
	Faculty newerFaculty;

	int currentFID = 0;

	if(studentTable.search(newStudent) == true && facultyTable.search(newFaculty) == true)
	{
		cout << "A match was found!! and the faculty is avaliable" << endl;

	       	newerStudent =	studentTable.searchID(newStudent);
		currentFID = newerStudent.getAdvisor();	
		newerStudent.setAdvisor(newID);

		if(currentFID != 0)
		{
			Faculty currentFaculty(currentFID, "filler", "filler", "filler", 9999);
			currentFaculty = facultyTable.searchID(currentFaculty);
			currentFaculty.removeAdvisee(ID);
			facultyTable.findReplace(currentFaculty);		
		}
		newerFaculty = facultyTable.searchID(newFaculty);
		newerFaculty.addAdvisee(ID);

		studentTable.findReplace(newerStudent);
		cout << "WORKING 5" << endl;
		facultyTable.findReplace(newerFaculty);

		cout << "The advisor has been replaced" << endl;

	}
	else
		cout <<"No match was found" << endl;
}	

//changes advisors students
void Function::changeAdvisorStudent()
{
	int ID = 0;
	int newID = 0;

	cout << "What is the students ID?" << endl;
	cin >> ID;
	cin.ignore(100, '\n');

	cout << "What is the new Faculty ID? " << endl;
	cin >> newID;
	cin.ignore(100, '\n');

	Student newStudent(ID, "fuller", "junior", "filler", 4.0, 9999);
	Student newerStudent;

	Faculty newFaculty(newID, "filler", "filler", "diller", 9999); 
	Faculty newerFaculty;

	if(studentTable.search(newStudent) == true && facultyTable.search(newFaculty) == true)
	{
	       	newerStudent =	studentTable.searchID(newStudent);
		newerStudent.setAdvisor(0);
		studentTable.findReplace(newerStudent);

		newerFaculty = facultyTable.searchID(newFaculty);
		newerFaculty.removeAdvisee(ID);
		facultyTable.findReplace(newerFaculty);

	}
}

//writes out
void Function::writeOut()
{
	ofstream fileout("StudentTree.txt");
	studentTable.writeToFile(fileout);

	ofstream fileOut("FacultyTree.txt");
	facultyTable.writeToFile(fileOut);
}

//writes in
void Function::writeIn()
{
	Student newStudent;//(5555, "charlie", "junior", "ahhdf", 4.0, 76543);
	ifstream fileIn("StudentTree.txt");

	while(fileIn.is_open() && !fileIn.eof())
	{
		newStudent.deserialize(fileIn);
		studentTable.insert(newStudent);
		//updateStudentTable();
	}

	Faculty newFaculty;
	ifstream file_in("FacultyTree.txt");

	while(file_in.is_open() && !file_in.eof())
	{
		newFaculty.deserialize(file_in);
		facultyTable.insert(newFaculty);
	}

	fileIn.close();
	file_in.close();

}
