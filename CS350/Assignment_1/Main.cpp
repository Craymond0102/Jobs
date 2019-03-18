//Charles Raymond, 2306164, raymond@chapman.edu, CPCS350, Assignment1
//This is main, which will run the following program

#include "DNA.h"

using namespace std;

int main(int argc, char** argv)
{
	string filename;	//the filename 
	double j = 0;		//this is the count
	double sum = 0;		//the sum of all strings
	double variance = 0;	//the variance
	string answer;		//string answer to retry program

	DNA dna;		//DNA instance of the DNA class
	Nucleotide nucleotide;	//nucleotide instance
	Bigram bigram;		//Bigram instance

	do
	{
		if(argc > 1)
			filename = argv[1];	//inputs filename from terminal

		dna.write_in(filename, j, sum);	//writes in the DNA for count 
		double average = dna.calculate_avg(j, sum);	//gets the average from count

		dna.write_in_variance(filename, average, variance, sum, nucleotide, bigram);	//gets variance through second pass
		double standard_deviation = dna.calculate_standard_deviation(variance);		//gets standard deviation

		dna.prob_of_nucleotide(sum, nucleotide);	//gets prob of nucleotide
		dna.prob_of_bigram(sum, bigram);		//gets prob of bigram

		dna.write_out(sum, average, variance, standard_deviation, nucleotide, bigram);	//writes out info to external file

		//alerts user what has happened
		cout << "Data has been analyzed from " << filename << " and outputted to CharlieRaymond.out" << endl;


		cout << "Would you like to input another file?" << endl;	//asks user if theyd like to go again
		cin >> answer;							//input
		cin.ignore(100, '\n');							

		if(answer.compare("yes") == 0)
		{
			cout << "What is the file name you would like to add?" << endl;	//asks for new filename
			cin >> argv[1];
			cin.ignore(100, '\n');

			dna.reset(j, sum, average, variance, standard_deviation, nucleotide, bigram);	//resets all values
		}

	}while(answer.compare("yes") == 0);


	return 0;
}
