using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include<conio.h>
#include<stdio.h>

enum accountType
{
	general,
	junior,
	savings
};


struct Account
{
	int number;
	string surname;
	string forename;
	string address;
	int balance;
	int interest;
	accountType type;
};

class createAccount
{
public
	:Account _account;
	
};

class createGeneralAccount : public createAccount
{
public:
	int max = 5000;
};

class createJuniorAccount : public createAccount
{
public:
	int max = 1000;
};

class createSavingsAccount : public createAccount
{
public:
	int max = 10000;
};

void writeAccount(Account _account)
{
	ofstream writeAccount;
	string name = to_string(_account.number);
	writeAccount.open(name + ".txt");
	writeAccount << _account.surname << "\n" << _account.forename << "\n" << _account.address << "\n" << _account.balance << "\n" << _account.interest << "\n" << _account.type << "\n";
	writeAccount.close();
}


void openAccount()
{
	cout << "choose what type of account, 1. General accout, 2. Junior account, 3. saving account. Enter 4 to return to menu" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		createGeneralAccount newAccount;
		newAccount._account.type = general;

		int accNo = (rand() % 10000);
		newAccount._account.number=accNo;
		cout << "your unique account number is " << accNo << " please remember it" << endl;

		cout << "what is your forename" << endl;
		cin >> newAccount._account.forename;
		cout << "what is your surname" << endl;
		cin >> newAccount._account.surname;
		cout << "what is your address" << endl;
		cin >> newAccount._account.address;
		bool cont = true;
		while (cont)
		{
			cout << "how much money are you going to add? This account has a maximum of: " << newAccount.max << endl;
			cin >> newAccount._account.balance;
			if (newAccount._account.balance <= newAccount.max)
			{
				cont = false;
			}
			else
			{
				cout << "This account has a maximum of: " << newAccount.max << "please try again" << endl;
			}
		};
		if (newAccount._account.balance <= 0)
		{
			cout << "sorry you are too broke to make this account, try again later" << endl;
			break;
		}

		cout << "your interest rate is 2 percent" << endl;
		newAccount._account.interest = 2;

		writeAccount(newAccount._account);

		cout << "your account has been saved" << endl;

		break;
	}
	case 2:
	{
		createJuniorAccount newAccount;
		newAccount._account.type = junior;

		int accNo = (rand() % 10000);
		newAccount._account.number = accNo;
		cout << "your unique account number is " << accNo << " please remember it" << endl;

		cout << "what is your forename" << endl;
		cin >> newAccount._account.forename;
		cout << "what is your surname" << endl;
		cin >> newAccount._account.surname;
		cout << "what is your address" << endl;
		cin >> newAccount._account.address;
		bool cont = true;
		while (cont)
		{
			cout << "how much money are you going to add? This account has a maximum of: " << newAccount.max << endl;
			cin >> newAccount._account.balance;
			if (newAccount._account.balance <= newAccount.max)
			{
				cont = false;
			}
			else
			{
				cout << "This account has a maximum of: " << newAccount.max << "please try again" << endl;
			}
		};
		if (newAccount._account.balance <= 0)
		{
			cout << "sorry you are too broke to make this account, try again later" << endl;
			break;
		}
		if (newAccount._account.balance > 1000)
		{
			cout << "sorry you are too broke to make this account, try again later" << endl;
			break;
		}

		cout << "your interest rate is 1 percent" << endl;
		newAccount._account.interest = 1;

		writeAccount(newAccount._account);

		cout << "your account has been saved" << endl;


		break;
	}
	case 3:
	{
		createSavingsAccount newAccount;
		newAccount._account.type = savings;

		int accNo = (rand() % 10000);
		newAccount._account.number = accNo;
		cout << "your unique account number is " << accNo << " please remember it" << endl;

		cout << "what is your forename" << endl;
		cin >> newAccount._account.forename;
		cout << "what is your surname" << endl;
		cin >> newAccount._account.surname;
		cout << "what is your address" << endl;
		cin >> newAccount._account.address;
		bool cont = true;
		while (cont)
		{
			cout << "how much money are you going to add? This account has a maximum of: " << newAccount.max << endl;
			cin >> newAccount._account.balance;
			if (newAccount._account.balance <= newAccount.max)
			{
				cont = false;
			}
			else
			{
				cout << "This account has a maximum of: " << newAccount.max << "please try again" << endl;
			}
		};
		if (newAccount._account.balance <= 0)
		{
			cout << "sorry you are too broke to make this account, try again later" << endl;
			break;
		}

		cout << "your interest rate is 3 percent" << endl;
		newAccount._account.interest = 3;

		writeAccount(newAccount._account);

		cout << "your account has been saved" << endl;


		break;
	}
	case 4:
	{
		break;
	}
	}
	;
}

void viewAccount()
{
	cout << "what is the number of the account you wish to veiw?" << endl;
	int accNo;
	cin >> accNo;

	ifstream veiwAccount;
	
	veiwAccount.open(to_string(accNo)+".txt");

		if (!veiwAccount)
		{
			cout << "account does not exist" << endl;
		}
		string line;
		
		string messages[10] = { "The accouts surname is: ", "The accounts forename is: ", "the accounts address is: ", "the accounts balance is: ", "the accounts interest percent is: ", "the account type is: " };
		int counter = 0;

		while (veiwAccount >> line)
		{
			cout << messages[counter];
			cout << line << endl;
			counter++;
		}

		cout << "account type 0 means general , 1 means junior, 2 means savings" << endl;
		
		veiwAccount.close();
}

void closeAccount()
{
	cout << "what is the account number of the account you wish to close?" << endl;
	int accNo;
	cin >> accNo;

	ifstream removeAccount;

	removeAccount.open(to_string(accNo) + ".txt");

	if (!removeAccount)
	{
		cout << "account does not exist" << endl;
	}
	else
	{
		
		//removeAccount.close();
		if (remove(accNo + ".txt") == 0)
		{
			cout << "Account removed successfully!" << endl;
		}
		else
		{
			cout << "unable to delete file" << endl;
		}
		
	};
}

int main()
{
	srand((int)time(0));
	bool cont = true;
	while (cont)
	{
		cout << "choose what to do, 1. open account 2. View account 3. Close account 4. Exit Program" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				openAccount();
			}
			break;
			case 2:
			{
				viewAccount();
			}
			break;
			case 3:
			{
				closeAccount();
			}
			break;
			case 4:
			{
				cont = false;
				cout << "See you later!" << endl;
			}
			break;
			default: 
			{
				cout << "try again" << endl;
			}
		}
	}
}