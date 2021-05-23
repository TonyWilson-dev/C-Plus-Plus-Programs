#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outfile("example.txt");

	// check if file was opened

	if (!outfile.is_open())
	{
		cerr << "file could not be opened !";
		std::exit(1);
	}

	// file must be open to reach here
	outfile << "this is a line.\n";
	outfile << "this is another line.\n";

	// close file

	outfile.close();

	return 0;

}
