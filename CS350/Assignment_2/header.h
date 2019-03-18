//Charles Raymond, 2306164, raymond@chapman.edu, CPCS350, Rene German, Assingment 2
//Header file for game of life program


#include <iostream>
#include <fstream>
#include <istream>
#include <unistd.h>
#include <math.h>
//#include <boost>

using namespace std;

//game of life class, manages the board and each different simulation
class gameOfLife
{
	public:
		gameOfLife();			//constructor
		gameOfLife(int row1, int col1);	//constructor
		~gameOfLife();			//deconstructor

		//writes in parameters for board
		void write_in_shape(string filename);
		void write_in_board(string filename);
		//fills board
		void fillBoard(string line, int count);

		//gets neighbors for game mode
		int getNeighbors(int row1, int col1);
		int doughnutMode(int row1, int col1);
		int mirrorMode(int row1, int col1);
		
		//calculates next generation
		int normalNextGen(int row1, int col1, int input);

		//gets a population
		double population(int row1, int col1);
		//randomly fills the board
		void fillBoard(int row1, int col1);

		//game mod simulations
		void classicModeSimulation(int row1, int col1, string answer, string filename, int input);
		void doughnutModeSimulation(int row1, int col1, string answer, string filename, int input);
		void mirrorModeSimulation(int row1, int col1, string answer, string filename, int input);

		//checks to see if board is the same
		bool isSame();
		//checks to see if board is empty
		bool isEmpty();
		//resets generation
		void resetGen();
		//copy's over generation
		void copyPrevGen();

		//display the board
		void displayBoard();
		//writes out the gneration to a file
		void write_out_gen(string filename, int input, int count);

		//board variables
		char ** goldStandard;
		char ** board;
		char ** previous;
		int numGen;
		int row;
		int col;
};
