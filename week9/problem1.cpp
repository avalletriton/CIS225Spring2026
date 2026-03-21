#include<iostream>
#include"Header1.h"
#include<string>
using namespace std;
int main()
{
	int accNum;
	string w;
	double amount;
	
	cout << "Enter account number: ";
	cin >> accNum;
	bankAccount account(accNum,0);

	cout << "Would you like to deposit or withdraw? (Type 'D' for deposit, 'W' for withdraw): ";
	cin >> w;

	while (w != "D" && w != "d" && w != "W" && w != "w")
	{
		cout << "Please enter either D for deposit or W for withdraw: ";
			cin >> w;
	}

	if (w == "D" || w == "d")
	{
		cout << "How much would you like to deposit: $";
		cin >> amount;
		account.deposit(amount);
	}
	else if (w == "W" || w == "w")
	{
		cout << "How much would you like to withdraw: $";
		cin >> amount;
		account.withdraw(amount);
	}

	account.PrintInfo();
	
	return 0;
}