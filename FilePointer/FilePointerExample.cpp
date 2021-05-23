#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	streampos begin,end;
	// open file
	ifstream inFile("example.txt", ios::binary);

	if (!inFile)
	{
		cerr << " file could not be opened !!!" << endl;
		std::exit;
	}
	// get current  file position

	begin = inFile.tellg();

	// reposition to end of file

	inFile.seekg(0, ios::end);

	// currrent position in file

	end = inFile.tellg();

	// close the file

	inFile.close();

	cout << " the size is : " << (end - begin) << " bytes.\n" << endl;

	cin.get();

	return 0;
}
