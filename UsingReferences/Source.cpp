using namespace std;
#include <iostream>

void output(int& rNum)
{
	cout << "input a number" << endl;
	cin >> rNum;
	cout << "rNum value is: " << rNum << endl;
	rNum += 25;
	cout << "rNum value is: " << rNum << endl;
	cout << "input another number" << endl;
	cin >> rNum;
	cout << "rNum value is: " << rNum << endl;
	rNum -= 25;
	cout << "rNum value is: " << rNum << endl;
}

int main()
{
	int num;
	int &rNum = num;
	
	output(num);
	

	return 0;
}
