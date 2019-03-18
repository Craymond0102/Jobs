//Charles Raymond, 2306164, raymond@chapman.edu, CPCS350, Assignment1
//This is the header file that contains the class for the Dna

#include <cstring>
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <istream>
#include <math.h>
#include <stdlib.h>

using namespace std;

//struct for the probability of each nucleotide
struct Nucleotide
{
	double A;
	double T;
	double C;
	double G;
};

//struct for the probability of each Bigram
struct Bigram
{
	double AA;
	double AT;
	double AC;
	double AG;

	double TT;
	double TA;
	double TC;
	double TG;

	double CC;
	double CA;
	double CT;
	double CG;

	double GG;
	double GA;
	double GT;
	double GC;
};
	
//DNA class
class DNA
{
	public:
		DNA();		//constructor
		DNA(const DNA& add); 		//copy constructor
		~DNA();		//deconstructor

		int copy_entry(string input, double & sum);	//counts the sum and copies the name to the class
		int calculate_length(string input);		//calculates the length of the string
		string string_toupper(string dna);		//makes the string all uppercase

		void display();					//displays
		//resets all of the data
		void reset(double & j, double & sum, double & average, double & variance, double & standard_deviation, Nucleotide & tide, Bigram & big);
	
		int write_in(string input, double & j, double & sum);	////writes in the string and gets the sum & count
		//writes in and gets the average, variance, and probabilities
		void write_in_variance(string input, double average, double & variance, double sum, Nucleotide & add, Bigram & plus);

		//writes out the data to another file
		void write_out(double sum, double average, double variance, double standard_deviation, Nucleotide tide, Bigram big);

		double calculate_avg(double j, double sum);	//calculates average
		double calculate_variance(string DNA, double average, double & variance);	//calculates the variance
		double calculate_standard_deviation(double variance);				//calculates the standard deviation

		void count_of_nucleotide(string dna, Nucleotide & add);		//counts all the nuclotides
		void prob_of_nucleotide(double sum, Nucleotide & add);		//gets the probability of the nucleotides
		void count_of_bigram(string dna, Bigram & add);			//counts all the bigrams
		void prob_of_bigram(double sum, Bigram & add);			//gets the probability of each bigram

		double distribution(double average, double standard_deviance);	//gets length D for a distribution
		string produce_dna(double average, double standard_deviation, Nucleotide tide, Bigram big);	//produces a string 
		string prob_string(Nucleotide tide);	//helps produce a string based on nucleotide prob
		string prob_bigram(Bigram big, string ref);	//helps produce a string based on the bigram prob

		string prob_bi_A(Bigram big, double sum, double prob);	//these are the probabilities of each bigram counterpart
		string prob_bi_T(Bigram big, double sum, double prob);
		string prob_bi_C(Bigram big, double sum, double prob);
		string prob_bi_G(Bigram big, double sum, double prob);

		string bound(double A_bound, double T_bound, double C_bound, double prob);	//the bounds to randomize which nucleotide is chosen

	private:
		string name;	//dna string
};
