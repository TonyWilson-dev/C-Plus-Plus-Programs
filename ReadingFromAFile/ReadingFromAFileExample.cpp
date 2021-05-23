#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string lineOfText;
	ifstream infile("example.txt");
	// check if file was opened
	if (infile.is_open())
	{
		// loops through whole file and outputs each line to the console
		while (getline(infile, lineOfText))
		{
			cout << lineOfText << endl;

		}
		infile.close();

	}
	else 
	{
		// file didnt open 
		cout << "unable to open file" << endl;
	}
	cin.get();
	return 0;
}