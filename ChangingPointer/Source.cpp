using namespace std;
#include <iostream>



void inputDetails(int &n1, int &n2)
{
	
	cout << "enter a number" << endl;
	cin >> n1;
	cout << "enter another number" << endl;
	cin >> n2;
};

void outputDetails(int num1, int num2, int* pNum)
{
	cout << "1. Num 1 value is: " << num1 << endl;
	cout << "2. Num 1 address is: " << &num1 << endl;
	cout << "3. Num 2 value is: " << num2 << endl;
	cout << "4. Num 2 address is: " << &num2 << endl;
	cout << "5. pNum value is: " << pNum << endl;
	cout << "6. pNum dereferenced value is: " << *pNum << endl;
	cout << "7. pNum adress value is: " << &pNum << endl;
}

int main()
{
	int num1, num2;
	int* pNum = &num1;

	inputDetails(num1, num2);

	outputDetails(num1, num2, pNum);
}