//THis is a practice doc to test compiling

#include <iostream>

using namespace std;

int main()
{
	char input[500];
	cout << "Hi there, good to see it works" << endl;

	cout << "How many minutes until class starts?" << endl;
	cin >> input;
	cin.ignore(100, '\n');

	cout << input;

	return 0;
}

