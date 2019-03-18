//Charles Raymond, 2306164, raymond@chapman.edu, CPCS350, Assignment1
//This is where the functions for the DNA class are going to be

#include "DNA.h"

using namespace std;

//constructor
DNA::DNA()
{
	name = "";
}

//copy constructor
DNA::DNA(const DNA& add)
{
	name = add.name;
}

//puts the dna string into the class, and counts the sum
int DNA::copy_entry(string input, double & sum)
{

	name = input;

	sum +=  calculate_length(name);

	return 1;
}

//calculates the length
int DNA::calculate_length(string input)
{
	int length = input.length(); 

	return length;
}

//to upper function for a string
string DNA::string_toupper(string dna)
{
	int length = calculate_length(dna);

	for(int i = 0; i < length; ++i)
	{
		dna[i] = toupper(dna[i]);
	}

	return dna;
}

//calculates the average
double DNA::calculate_avg(double j, double sum)
{
	return (sum/j);
}

//calculates the variance
double DNA::calculate_variance(string DNA, double average, double & varianceSum)
{
	double length = calculate_length(DNA);
	double difference = length - average;

	varianceSum += difference * difference;

	return difference;
}

//calculates the standard deviation
double DNA::calculate_standard_deviation(double variance)
{
	double deviation = sqrt(variance);

	return deviation;
}

//get the amount of times each nucleotide appears
void DNA::count_of_nucleotide(string dna, Nucleotide & add)
{
	int length = calculate_length(dna);


	for(int i = 0; i < length; ++i)
	{
		if(dna[i] == 'A')
			++add.A;
		if(dna[i] == 'T')
			++add.T;
		if(dna[i] == 'C')
			++add.C;
		if(dna[i] == 'G')
			++add.G;
	}
}

//gets the probability of each nucleotide occuring
void DNA::prob_of_nucleotide(double sum, Nucleotide & add)
{
	add.A = add.A/sum;
	add.T = add.T/sum;
	add.C = add.C/sum;
	add.G = add.G/sum;
}

//counts the amount of times each bigram appears
void DNA::count_of_bigram(string dna, Bigram & add)
{
	int length = calculate_length(dna);

	for(int i = 0; i < length; i += 2)
	{
		if(dna.substr(i, 2).compare("AA") == 0)
			++add.AA;
		if(dna.substr(i, 2).compare("AT") == 0)
			++add.AT;
		if(dna.substr(i, 2).compare("AC") == 0)
			++add.AC;
		if(dna.substr(i, 2).compare("AG") == 0)
			++add.AG;
		if(dna.substr(i, 2).compare("TT") == 0)
			++add.TT;
		if(dna.substr(i, 2).compare("TA") == 0)
			++add.TA;
		if(dna.substr(i, 2).compare("TC") == 0)
			++add.TC;
		if(dna.substr(i, 2).compare("TG") == 0)
			++add.TG;
		if(dna.substr(i, 2).compare("CC") == 0)
			++add.CC;
		if(dna.substr(i, 2).compare("CA") == 0)
			++add.CA;
		if(dna.substr(i, 2).compare("CT") == 0)
			++add.CT;
		if(dna.substr(i, 2).compare("CG") == 0)
			++add.CG;
		if(dna.substr(i, 2).compare("GG") == 0)
			++add.GG;
		if(dna.substr(i, 2).compare("GA") == 0)
			++add.GA;
		if(dna.substr(i, 2).compare("GT") == 0)
			++add.GT;
		if(dna.substr(i, 2).compare("GC") == 0)
			++add.GC;
	}
}

//gets the probability of each bigram occuring
void DNA::prob_of_bigram(double sum, Bigram & add)
{
	add.AA = add.AA/sum;
	add.AT = add.AT/sum;
	add.AC = add.AC/sum;
	add.AG = add.AG/sum;
	add.TT = add.TT/sum;
	add.TA = add.TA/sum;
	add.TC = add.TC/sum;
	add.TG = add.TG/sum;
	add.CC = add.CC/sum;
	add.CA = add.CA/sum;
	add.CT = add.CT/sum;
	add.CG = add.CG/sum;
	add.GG = add.GG/sum;
	add.GA = add.GA/sum;
	add.GT = add.GT/sum;
	add.GC = add.GC/sum;
}

//gets the length of a string to create my own distribution
double DNA::distribution(double average, double standard_deviance)
{
	double a = ((double) rand() / (RAND_MAX));
	double b = ((double) rand() / (RAND_MAX));

	double C = sqrt( -2 * log(a)) * cos(2*M_PI*b);
	double D = (standard_deviance * C) + average;

	return D;
}

//writes in each line of the file and counts the amount of string
int DNA::write_in(string input, double & j, double & sum)
{
	ifstream file_in (input);
	string DNA;

	if(file_in.is_open())//file_in && !file_in.eof())
	{

		while( getline (file_in, DNA) && !file_in.eof())
		{
			DNA = string_toupper(DNA);
			copy_entry(DNA, sum);

			++j;
		}
	}

	return j;
}

//writes in each line again, but this time to get the average, variance, and probabilities
void DNA::write_in_variance(string input, double average, double & variance, double sum, Nucleotide & add, Bigram & plus)
{
	ifstream file_in (input);
	string DNA;

	if(file_in.is_open())
	{
		while( getline (file_in, DNA) && !file_in.eof())
		{
			DNA = string_toupper(DNA);

			calculate_variance(DNA, average, variance);
			count_of_nucleotide(DNA, add);
			count_of_bigram(DNA, plus); 
		}
	}
}

//writes out the info to another file
void DNA::write_out(double sum, double average, double variance, double standard_deviation, Nucleotide tide, Bigram big)
{
	ofstream file_out;

	file_out.open("CharlieRaymond.out", ios::app);

	if(file_out)
	{
		file_out << "Charles Raymond, 2306164, raymond@chapman.edu, CPCS 350 section 1, Rene German" << endl;
		file_out << "Sum : " << sum << endl;
		file_out << "Average : " << average << endl;
		file_out << "Variance : " << variance << endl;
		file_out << "Standard deviation : " << standard_deviation << endl;
		file_out << "-Probabilities- " << endl;
		file_out << "A: " << tide.A << endl;
		file_out << "T: " << tide.T << endl;
		file_out << "C: " << tide.C << endl;
		file_out << "G: " << tide.G << endl;
		file_out << "AA: " << big.AA << endl;
		file_out << "AT: " << big.AT << endl;
		file_out << "AC: " << big.AC << endl;
		file_out << "AG: " << big.AG << endl;
		file_out << "TT: " << big.TT << endl;
		file_out << "TA: " << big.TA << endl;
		file_out << "TC: " << big.TC << endl;
		file_out << "TG: " << big.TG << endl;
		file_out << "CC: " << big.CC << endl;
		file_out << "CA: " << big.CA << endl;
		file_out << "CT: " << big.CT << endl;
		file_out << "CG: " << big.CG << endl;
		file_out << "GG: " << big.GG << endl;
		file_out << "GA: " << big.GA << endl;
		file_out << "GT: " << big.GT << endl;
		file_out << "GC: " << big.GC << endl;

		for(int i = 0; i < 1000; ++i)
		{
			file_out << produce_dna(average, standard_deviation, tide, big) << endl;
		}

	}
}

//produces a string of length D with the probabilities of the nucleotides and bigrams
string DNA::produce_dna(double average, double standard_deviation, Nucleotide tide, Bigram big)
{
	string current;
	string temp;

	int length = distribution(average, standard_deviation);

	for(int i = 0; i < length; ++i)
	{
		if(i == 0 || i % 2 == 0)
		{		
			temp = prob_string(tide);
			current = temp + current;
		}
		else
		{
			temp = prob_bigram(big,  temp);
			current = temp + current;
		}

	}
	
	return current;
}

//returns a random nucleotide based off of probability
string DNA::prob_string(Nucleotide tide)
{
	double prob = ((double) rand() / (RAND_MAX));

	double A_bound = 1-tide.A;
	double T_bound = 1- (tide.A+tide.T);
	double C_bound = 1 - (tide.A + tide.T + tide.C);

	if(prob < 1 && prob >= A_bound)
		return "A";
	else if(prob < A_bound && prob >= T_bound)
		return "T";
	else if(prob < T_bound && prob >= C_bound)
		return "C";
	else
		return "G";
}

//returns a random bigram based off the probability
string DNA::prob_bigram(Bigram big, string ref)
{
	double prob = ((double) rand() / (RAND_MAX));

	double sum;

	if(ref == "A")
	{
		sum = big.AA + big.AT + big.AC + big.AG;
		return prob_bi_A(big, sum, prob);
	}	
	else if(ref == "T")
	{
		sum = big.TT + big.TA + big.TC + big.TG;
		return prob_bi_T(big, sum, prob);
	}
	else if(ref == "C")
	{
		sum = big.CC + big.CA + big.CT + big.CG;
		return prob_bi_C(big, sum, prob);
	}
	else
	{
		sum = big.GG + big.GA + big.GT + big.GC;
		return prob_bi_G(big, sum, prob);
	}
	
}

//the probability if the letter before was an A 
string DNA::prob_bi_A(Bigram big, double sum, double prob)
{
	double prob_A = big.AA/sum;
	double prob_T = big.AT/sum;
	double prob_C = big.AC/sum;

	double A_bound = 1 - prob_A;
	double T_bound = 1 - (prob_A + prob_T);
	double C_bound = 1 - (prob_A + prob_T + prob_C);

	return bound(A_bound, T_bound, C_bound, prob);
}

//the probability if the letter before was an T
string DNA::prob_bi_T(Bigram big, double sum, double prob)
{
	double prob_A = big.TT/sum;
	double prob_T = big.TA/sum;
	double prob_C = big.TC/sum;

	double A_bound = 1 - prob_A;
	double T_bound = 1 - (prob_A + prob_T);
	double C_bound = 1 - (prob_A + prob_T + prob_C);

	return bound(A_bound, T_bound, C_bound, prob);
}

//the probability if the letter before was an C
string DNA::prob_bi_C(Bigram big, double sum, double prob)
{
	double prob_A = big.CC/sum;
	double prob_T = big.CA/sum;
	double prob_C = big.CT/sum;

	double A_bound = 1 - prob_A;
	double T_bound = 1 - (prob_A + prob_T);
	double C_bound = 1 - (prob_A + prob_T + prob_C);

	return bound(A_bound, T_bound, C_bound, prob);
}

//the probability if the letter before was an G
string DNA::prob_bi_G(Bigram big, double sum, double prob)
{
	double prob_A = big.GG/sum;
	double prob_T = big.GA/sum;
	double prob_C = big.GT/sum;

	double A_bound = 1 - prob_A;
	double T_bound = 1 - (prob_A + prob_T);
	double C_bound = 1 - (prob_A + prob_T + prob_C);

	return bound(A_bound, T_bound, C_bound, prob);
}

//the bounds for each probability of the bigram
string DNA::bound(double A_bound, double T_bound, double C_bound, double prob)
{
	if(prob < 1 && prob >= A_bound)
		return "A";
	else if(prob < A_bound && prob >= T_bound)
		return "T";
	else if(prob < T_bound && prob >= C_bound)
		return "C";
	else
		return "G";
}

//resets all of the variables from main to 0 for another file input
void DNA::reset(double & j, double & sum, double & average, double & variance, double & standard_deviation, Nucleotide & tide, Bigram & big)
{
	j = 0;
	sum = 0;
	average = 0;
	variance = 0;
	standard_deviation = 0;

	tide.A = 0;
	tide.T = 0;
	tide.C = 0;
	tide.G = 0;

	big.AA = 0;
	big.AT = 0;
	big.AC = 0;
	big.AG = 0;

	big.TT = 0;
	big.TA = 0;
	big.TC = 0;
	big.TG = 0;

	big.CC = 0;
	big.CA = 0;
	big.CT = 0;
	big.CG = 0;

	big.GG = 0;
	big.GA = 0;
	big.GT = 0;
	big.GC = 0;

}

//to display the name, not used
void DNA::display()
{
		cout << name << endl;
}

//deconstructor
DNA::~DNA()
{
	cout << "The program is over!" << endl;
}

