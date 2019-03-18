//Charles Raymond, 2306164, raymond@chapman.edu, CPCS350, Rene German, Assingment 2
//This is the functions for the game of life class

#include "header.h"

//constructor
gameOfLife::gameOfLife()
{
	board = NULL;
	previous= NULL;
	numGen = 0;
	row = 0;
	col = 0;
}

//constructor
gameOfLife::gameOfLife(int row1, int col1)
{
	row = row1;
	col = col1;

	goldStandard = new char*[row];
	board = new char*[row];
	previous = new char*[row];

	for(int i = 0; i < row1; ++i)
	{
		goldStandard[i] = new char[col];
		board[i] = new char[col];
		previous[i] = new char[col];
	}

	numGen = 0;
}

//deconstructor
gameOfLife::~gameOfLife()
{
	delete [] goldStandard;
	delete [] board;
	delete [] previous;
}

//write in the dimensions of the board
void gameOfLife::write_in_shape(string filename)
{
	ifstream file_in(filename);

	string line;
	int count = 1;

	if(file_in.is_open())
	{
		while(getline(file_in, line) &&!file_in.eof())
		{
			if(count == 1)
				row = stoi(line);
			if(count == 2)
				col = stoi(line);
			++count;
		}
	}
}

//write in the board from a file
void gameOfLife::write_in_board(string filename)
{
	ifstream file_in (filename);

	string line;	
	int count = 0;
	int row1 = 0;
	char temp[row][col];

	if(file_in.is_open())
	{
		while( getline(file_in, line) && !file_in.eof() && row1 < row)
		{
			if(count >= 2)
			{
				for(int j = 0; j < col; ++j)
				{
					goldStandard[row1][j] = line[j];
					board[row1][j] = line[j];
					previous[row1][j] = line[j];
				}
				++row1;
			}
			++count;
		}
	}
	else
	{
		cout <<"File does not exist, exiting" << endl;
		exit(0);
	}
}

//gets population density
double gameOfLife::population(int row1, int col1)
{
	double a = ((double) rand() / (RAND_MAX));
	double b = ((double) rand() / (RAND_MAX));

	return b;
}

//fills the random board
void gameOfLife::fillBoard(int row1, int col1)
{
	double pop = population(row1, col1);

	for(int i = 0; i < row1; ++i)
	{
		for(int j = 0; j < col1; ++j)
		{

			double a = ((double) rand() / (RAND_MAX));

			if(a <= pop)
			{
				goldStandard[i][j] = 'X';
				board[i][j] = 'X';
				previous[i][j] = 'X';
			}
			else
			{
				goldStandard[i][j]= '-';
				board[i][j]= '-';
				previous[i][j]= '-';
			}
		}
	}
}

//next calculates the next gen
int gameOfLife::normalNextGen(int row1, int col1, int input)
{
	int neighbors = 0;

	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			if(input == 1)
				neighbors = getNeighbors(i, j);	
			else if(input == 2)
				neighbors = doughnutMode(i, j);
			else
				neighbors = mirrorMode(i, j);

			if(neighbors <= 1 || neighbors > 3)
			{
				previous[i][j] = '-';
			}
			if(neighbors == 3)
			{
				previous[i][j] = 'X';
			}
		}
	}

	++numGen;

	return 1;
}

//copy's over last generation
void gameOfLife::copyPrevGen()
{
	for(int k = 0; k < row; ++k)
	{
		for(int p = 0; p < col; ++p)
		{
			board[k][p] = previous[k][p];
		}
	}
}

//checks to see if same between gen
bool gameOfLife::isSame()
{
	for(int k = 0; k < row; ++k)
	{
		for(int p = 0; p < col; ++p)
		{
			if(board[k][p] != previous[k][p])
			{
				return true;
			}
		}
	}

	cout << "Grid is the same, never ending" << endl;
	return false;
}

//checks to see if empty grid
bool gameOfLife::isEmpty()
{
	for(int k = 0; k < row; ++k)
	{
		for(int p = 0; p < col; ++p)
		{
			if(board[k][p] == 'X')
			{
				return true;
			}
		}
	}

	cout << "Grid is now empty" << endl;
	return false;
}

//resets the board for new game mode
void gameOfLife::resetGen()
{

	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			board[i][j] = goldStandard[i][j];
			previous[i][j] = goldStandard[i][j];
		}
	}
	numGen = 0;
}
	
//writes out generation to file
void gameOfLife::write_out_gen(string filename, int input, int count)
{
	ofstream file_out;

	file_out.open(filename, ios::app);

	if(file_out)
	{
		if(count == 0)
		{
			if(input == 1)
				file_out << "Starting Classic Mode" << endl;
			else if(input == 2)
				file_out << "Starting Doughnut Mode" << endl;
			else
				file_out << "Starting Mirror Mode" << endl;
		}

		file_out << numGen << endl;
		for(int i = 0; i < row; ++i)
		{
			for(int k = 0; k < col; ++k)
			{
				file_out << board[i][k];
			}
			file_out << endl;
		}
	}

}

//gets neighbors for classic mode
int gameOfLife::getNeighbors(int row1, int col1)
{
	int count = 0;

	if(row1-1 >= 0 && col1-1 >= 0 && board[row1-1][col1-1] == 'X')
		++count;
	if(col1-1 >= 0 && board[row1][col1-1] == 'X')
		++count;
	if(row1+1 < col && col1-1 >= 0 && board[row1+1][col1-1] == 'X')
		++count;
	if(row1+1 < col && col1-1 >= 0 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1-1 >= 0 && board[row1-1][col1] == 'X')
		++count;
	if(row1-1 >= 0 && col1+1 < row && board[row1-1][col1+1] == 'X')
		++count;
	if(col1+1 < col && board[row1][col1+1] == 'X')
		++count;
	if(row1+1 < col && board[row1+1][col1] == 'X')
		++count;
	if(row1+1 < col && col1+1 < col && board[row1+1][col+1] == 'X')
		++count;

	return count;
}

//gets neighbors for doughnut mode
int gameOfLife::doughnutMode(int row1, int col1)
{
	int count = 0;

	
	//this is top right corner case
	if(row1-1 < 0 && col1+1 > col-1 &&  board[row1][col1-1] == 'X')
		++count;
	if(row1-1 < 0 && col1+1 > col-1 && board[row1+1][col1] == 'X')
		++count;
	if(row1-1 < 0 && col1+1 > col-1 && board[row1+1][col1-1] == 'X')
		++count;
	if(row1-1 < 0 && col1+1 > col-1 && board[row1][col1%col] == 'X')
		++count;
	if(row1-1 < 0 && col1+1 > col-1 && board[row1+1][col1%col] == 'X')
		++count;
	if(row1-1 < 0 && col1+1 > col-1 && board[row1+row-1][col1%col] == 'X')
		++count;
	if(row1-1 < 0 && col1+1 > col-1 && board[row1+row-1][col1] == 'X')
		++count;
	if(row1-1 < 0 && col1+1 > col-1 && board[row1+row-1][col1-1] == 'X')
		++count;

	//this is top right corner case
	if(row1-1 < 0 && col1-1 < 0 && board[row1][col1+1] == 'X')
		++count;	
	if(row1-1 < 0 && col1-1 < 0 && board[row1+1][col1] == 'X')
		++count;
	if(row1-1 < 0 && col1-1 < 0 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1-1 < 0 && col1-1 < 0 && board[row1][col1+col-1] == 'X')
		++count;
	if(row1-1 < 0 && col1-1 < 0 && board[row1+1][col1+col-1] == 'X')
		++count;
	if(row1-1 < 0 && col1-1 < 0 && board[row1+row-1][col1] == 'X')
		++count;
	if(row1-1 < 0 && col1-1 < 0 && board[row1+row-1][col1+1] == 'X')
		++count;
	if(row1-1 < 0 && col1-1 < 0 && board[row1+row-1][col1+col-1] == 'X')
		++count;

	//this is the bottom left corner case
	if(row1+1 > row-1 && col1-1 < 0 && board[row1][col1+1] =='X')
		++count;
	if(row1+1 > row-1 && col1-1 < 0 && board[row1-1][col1] =='X')
		++count;
	if(row1+1 > row-1 && col1-1 < 0 && board[row1-1][col1+1] =='X')
		++count;
	if(row1+1 > row-1 && col1-1 < 0 && board[row1-row+1][col1] =='X')
		++count;
	if(row1+1 > row-1 && col1-1 < 0 && board[row1-row+1][col1+1] =='X')
		++count;
	if(row1+1 > row-1 && col1-1 < 0 && board[row1-row+1][col1+col-1] =='X')
		++count;
	if(row1+1 > row-1 && col1-1 < 0 && board[row1][col1+col-1] =='X')
		++count;
	if(row1+1 > row-1 && col1-1 < 0 && board[row1-1][col1+col-1] =='X')
		++count;

	//this is the bottom right corner case
	if(row1+1 > row-1 && col1+1 > col-1  && board[row1-1][col1] =='X')
		++count;
	if(row1+1 > row-1 && col1+1 > col-1 && board[row1][col1-1] =='X')
		++count;
	if(row1+1 > row-1 && col1+1 > col-1 && board[row1-1][col1-1] =='X')
		++count;
	if(row1+1 > row-1 && col1+1 > col-1 && board[row1][col1+1-col] =='X')
		++count;
	if(row1+1 > row-1 && col1+1 > col-1 && board[row1-1][col1+1-col] =='X')
		++count;
	if(row1+1 > row-1 && col1+1 > col-1 && board[row1+1-row][col1] =='X')
		++count;
	if(row1+1 > row-1 && col1+1 > col-1 && board[row1+1-row][col1-1] =='X')
		++count;
	if(row1+1 > row-1 && col1+1 > col-1 && board[row1+1-row][col1+1-col] =='X')
		++count;

	//top of the grid not corner case
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1][col1+1] == 'X')
		++count;
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1][col1-1] == 'X')
		++count;
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1+1][col1] == 'X')
		++count;
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1+1][col1-1] == 'X')
		++count;
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1+row-1][col1] == 'X')
		++count;
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1+row-1][col1+1] == 'X')
		++count;
	if(row1-1 < 0 && col1 < col-1 && col1 > 0 && board[row1+row-1][col1-1] == 'X')
		++count;

	//left side of the grid not corner case
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1+1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1-1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1-1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1][col1+1] == 'X')
		++count;	
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1][col1+col-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1+1][col1+col-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1-1 < 0 && board[row1-1][col1+col-1] == 'X')
		++count;

	//right side of the grid not corner case		
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1+1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1-1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1+1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1-1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1+1][col1-col+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1-1][col1-col+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1+1 == col && board[row1][col1-col+1] == 'X')
		++count;	

	//Bottom side of the grid not corner case	
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1][col1+1] == 'X')
		++count;
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1][col1-1] == 'X')
		++count;
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1-1][col1] == 'X')
		++count;
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1-1][col1+1] == 'X')
		++count;
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1-1][col1-1] == 'X')
		++count;
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1-row+1][col1+1] == 'X')
		++count;
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1-row+1][col1-1] == 'X')
		++count;
	if(row1+1 == row && col1 > 0 && col1 < col-1 && board[row1-row+1][col1] == 'X')
		++count;

	//rest of board
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1+1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1+1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1-1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1-1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1-1][col1] == 'X')
		++count;

	return count;

}

//gets neighbors for mirror mode
int gameOfLife::mirrorMode(int row1, int col1)
{
	int count = 0;

	//regular board
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1+1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1+1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1-1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1-1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 > 0 && col1 < col-1 && board[row1-1][col1] == 'X')
		++count;

	//top of the board mirror case
	if(row1 == 0 && col1 > 0 && col1 < col -1 && board[row1][col1] == 'X')
		++count;
	if(row1 == 0 && col1 > 0 && col1 < col -1 && board[row1][col1+1] == 'X')
		count+=2;
	if(row1 == 0 && col1 > 0 && col1 < col -1 && board[row1][col1-1] == 'X')
		count+=2;
	if(row1 == 0 && col1 > 0 && col1 < col -1 && board[row1+1][col1] == 'X')
		++count;
	if(row1 == 0 && col1 > 0 && col1 < col -1 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1 == 0 && col1 > 0 && col1 < col -1 && board[row1+1][col1-1] == 'X')
		++count;

	//top right corner case
	if(row1 == 0 && col1 == col - 1 && board[row1][col1] == 'X')
		count+=3;
	if(row1 == 0 && col1 == col - 1 && board[row1][col1-1] == 'X')
		count+=2;
	if(row1 == 0 && col1 == col - 1 && board[row1+1][col1] == 'X')
		count+=2;
	if(row1 == 0 && col1 == col - 1 && board[row1+1][col1-1] == 'X')
		++count;

	//bottom of the board mirror case
	if(row1 == row -1 && col1 > 0 && col1 < col -1 && board[row1][col1] == 'X')
		++count;
	if(row1 == row -1 && col1 > 0 && col1 < col -1 && board[row1][col1] == 'X')
		count+=2;
	if(row1 == row -1 && col1 > 0 && col1 < col -1 && board[row1][col1] == 'X')
		count+=2;
	if(row1 == row -1 && col1 > 0 && col1 < col -1 && board[row1-1][col1] == 'X')
		++count;
	if(row1 == row -1 && col1 > 0 && col1 < col -1 && board[row1-1][col1+1] == 'X')
		++count;
	if(row1 == row -1 && col1 > 0 && col1 < col -1 && board[row1-1][col1-1] == 'X')
		++count;

	//Bottom right corner case
	if(row1 == row -1 && col1 == col - 1 && board[row1][col1] == 'X')
		count+=3;
	if(row1 == row -1 && col1 == col - 1 && board[row1][col1-1] == 'X')
		count+=2;
	if(row1 == row -1 && col1 == col - 1 && board[row1-1][col1] == 'X')
		count+=2;
	if(row1 == row -1 && col1 == col - 1 && board[row1-1][col1-1] == 'X')
		++count;

	//left side of the board
	if(row1 > 0 && row1 < row-1 && col1 == 0 && board[row1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 == 0 && board[row1+1][col1] == 'X')
		count+=2;
	if(row1 > 0 && row1 < row-1 && col1 == 0 && board[row1-1][col1] == 'X')
		count+=2;
	if(row1 > 0 && row1 < row-1 && col1 == 0 && board[row1-1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 == 0 && board[row1+1][col1+1] == 'X')
		++count;
	if(row1 > 0 && row1 < row-1 && col1 == 0 && board[row1][col1+1] == 'X')
		++count;

	//Bottom left corner case
	if(row1 == row-1 && col1 == 0 && board[row1][col1] == 'X')
		count+=3;
	if(row1 == row-1 && col1 == 0 && board[row1-1][col1] == 'X')
		count+=2;
	if(row1 == row-1 && col1 == 0 && board[row1][col1+1] == 'X')
		count+=2;
	if(row1 == row-1 && col1 == 0 && board[row1-1][col1+1] == 'X')
		++count;

	//right side of the board	
	if(row1 > 0 && row1 < row -1 && col1 == col -1 && board[row1][col1] == 'X')
		++count;
	if(row1 > 0 && row1 < row -1 && col1 == col -1 && board[row1+1][col1] == 'X')
		count+=2;
	if(row1 > 0 && row1 < row -1 && col1 == col -1 && board[row1-1][col1] == 'X')
		count+=2;
	if(row1 > 0 && row1 < row -1 && col1 == col -1 && board[row1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row -1 && col1 == col -1 && board[row1+1][col1-1] == 'X')
		++count;
	if(row1 > 0 && row1 < row -1 && col1 == col -1 && board[row1-1][col1-1] == 'X')
		++count;

	//top left corner case
	if(row1 == 0 && col1 == 0 && board[row1][col1] == 'X')
		count+=3;
	if(row1 == 0 && col1 == 0 && board[row1][col1+1] == 'X')
		count+=2;
	if(row1 == 0 && col1 == 0 && board[row1+1][col1] == 'X')
		count+=2;
	if(row1 == 0 && col1 == 0 && board[row1+1][col1+1] == 'X')
		++count;

	return count;

}

//classic game mode simulation
void gameOfLife::classicModeSimulation(int row1, int col1, string answer, string filename, int input)
{
	int count = 0;
	bool again = true;

	do{
		copyPrevGen();

		if(answer == "pause" || answer == "Pause")
		{
			displayBoard();
			usleep(3000000);
		}
		else if(answer == "enter" || answer == "Enter")
		{
			displayBoard();
			cin.ignore();
		}
		else if(answer == "file" || answer == "File")
		{
			write_out_gen(filename, input, count);
			++count;
		}

		normalNextGen(row1, col1, input);

		if(isSame() == false)
			again = false;
		if(isEmpty() == false)
			again = false;
				
	}while(again);

	cout << "Classic Mode over" << endl;
	resetGen();

}

//doughnut game mode simulation
void gameOfLife::doughnutModeSimulation(int row1, int col1, string answer, string filename, int input)
{
	int count = 0;
	bool again = true;
	do{
		copyPrevGen();

		if(answer == "pause" || answer == "Pause")
		{
			displayBoard();
			usleep(3000000);
		}
		else if(answer == "enter" || answer == "Enter")
		{
			displayBoard();
			cin.ignore();
		}
		else if(answer == "file" || answer == "File")
		{
			write_out_gen(filename, input, count);
			++count;
		}

		normalNextGen(row1, col1, input);

		if(isSame() == false)
			again = false;
		if(isEmpty() == false)
			again = false;
				
	}while(again);

	cout << "Doughnut Mode is over" << endl;
	resetGen();
}

//mirror game mode simulation
void gameOfLife::mirrorModeSimulation(int row1, int col1, string answer, string filename, int input)
{
	int count = 0;
	bool again = true;
	do{
		copyPrevGen();

		if(answer == "pause" || answer == "Pause")
		{
			displayBoard();
			usleep(3000000);
		}
		else if(answer == "enter" || answer == "Enter")
		{
			displayBoard();
			cin.ignore();
		}
		else if(answer == "file" || answer == "File")
		{
			write_out_gen(filename, input, count);
			++count;
		}

		normalNextGen(row1, col1, input);

		if(isSame() == false)
			again = false;
		if(isEmpty() == false)
			again = false;
				
	}while(again);

}

//displays whole board
void gameOfLife::displayBoard()
{
	cout << "Generation " << numGen << endl;
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

