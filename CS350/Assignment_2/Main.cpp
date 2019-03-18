//Charles Raymond, 2306164, raymond@chapman.edu, CPCS350, Rene German, Assingment 2
//This assignment is a simulation of the game of life game

#include "header.h"


int main()
{
	//variables for the main and user input
	int row1 = 0;
	int col1 = 0;
	int count = 0;
	bool again = true;
	bool retry = true;
	int input = 0;
	string answer = "";
	string filename = " " ;
	string prompt1 = " ";
	string user_filename = " ";
	bool first = true;

	//gets whether they want file or random config, prompts correctly
	while(first)
	{

		cout << "Would you like to use a file or a random configuration? file/random" << endl;
		cin >> prompt1;
		cin.ignore(100, '\n');

		if(prompt1 == "file" || answer == "File")
		{
			cout << "Please enter a filename you would like to use, using the" 
				" correct file format" << endl;
			cin >> user_filename ;
			cin.ignore(100, '\n');

			gameOfLife game;
			game.write_in_shape(user_filename);

			row1=game.row;
			col1=game.col;

			first = false;
		}
		else if(prompt1 == "random" || prompt1 == "Random")
		{
			cout << "How many columns will the grid have?: ";
			cin >> col1;
			cout << endl;

			cout << "How many rows will the grid have?: ";
			cin >> row1;
			cout << endl;

			cout << "Random file generated" << endl;

			first = false;
		}
		else
		{
			cout << "Incorrect input, try again" << endl;
		}

	}

	//initiates the board
	gameOfLife board(row1, col1);

	if(prompt1 == "file" || answer == "File")
	{
		cout << "Working" << endl;
		board.write_in_board(user_filename);
	}
	else
		board.fillBoard(row1, col1);

	//asks for what kind of simulation
	while(retry)
	{
		cout << "Do you want a pause in between each generation?" << endl;
		cout << "OR do you want to do it personally by pressing the enter key?" << endl;
		cout << "OR outprint to file? (pause/enter/file)" << endl;
		cin >> answer;
		cin.ignore(100, '\n');
				
		if(answer == "Pause" || answer == "pause" ||
			answer == "Enter" || answer == "enter" ||
			answer == "File" || answer == "file")
		{
			retry = false;	
		}
		else
			cout << "You did not enter a correct response, please try again" << endl;
					
	}

	//asks for game mode
	cout << "Select which game modes you would like to run" << endl;
	cout << "Case 1: Classic Mode & Doughnut Mode" << endl;
	cout << "Case 2: Classic Mode & Mirror Mode" << endl;
	cout << "Case 3: Doughnut Mode & Mirror Mode" << endl;
	cin >> input;
	cin.ignore(100, '\n');

/*
		while(retry)
		{
			cout << "Do you want a pause in between each generation?" << endl;
			cout << "OR do you want to do it personally by pressing the enter key?" << endl;
			cout << "OR outprint to file? (pause/enter/file)" << endl;
			cin >> answer;
			cin.ignore(100, '\n');
				
			if(answer == "Pause" || answer == "pause" ||
				answer == "Enter" || answer == "enter" ||
				answer == "File" || answer == "file")
			{
				retry = false;	
			}
			else
				cout << "You did not enter a correct response, please try again" << endl;
					
		}
		*/

	if(answer == "file" || answer == "File")
	{
		cout << "What is the filename?" << endl;
		cin >> filename;
		cin.ignore(100, '\n');
	}

	//runs each game mode
	if(input == 1) 
	{
		cout << "Classic Mode" << endl;
		board.classicModeSimulation(row1, col1, answer, filename, 1);

		cout << "Doughnut Mode" << endl;
		board.doughnutModeSimulation(row1, col1, answer, filename, 2);
	}
	else if(input == 2)
	{
		cout << "Classic Mode" << endl;
		board.classicModeSimulation(row1, col1, answer, filename, 1);

		cout <<	"Mirror Mode" << endl;
		board.mirrorModeSimulation(row1, col1, answer, filename, 3);	
	}	
	else if(input == 3)
	{
		cout << "Doughnut Mode" << endl;
		board.doughnutModeSimulation(row1, col1, answer, filename, 2);

		cout << "Mirror Mode" << endl;
		board.mirrorModeSimulation(row1, col1, answer, filename, 3);	
	}
	else
		cout << "Incorrect input, by" << endl;

	//program over
	cout << "Program is over!" << endl;


	return 0;
}
