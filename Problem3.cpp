#include<iostream>
#include"Header1.h"
#include<string>
using namespace std;

class savingsAccount : public bankAccount
{
public:
	savingsAccount(int accNum, double balance, double interest) : bankAccount(accNum, balance) 
	{
		m_interest = interest;
	}

	void s_interest(double interest)
	{
		m_interest = interest;
	}

	double interest()
	{
		return m_interest;
	}

	void postInterest()
	{
		double interestAmount = balance() * m_interest;
		deposit(interestAmount);
	}

	void withdraw(double amount)
	{
		if (amount > balance())
		{
			std::cout << "Insufficient funds" << std::endl;
		}
		else
		{
			bankAccount::withdraw(amount);
		}
	}

	void PrintInfo()
	{
		bankAccount::PrintInfo(); //reuse the original
		std::cout << "Interest rate: " << m_interest << std::endl;
	}
private:
	double m_interest;
};

int main()
{
	savingsAccount account(123, 100, .10);
	int accNum;
	double amount, interest, balance;
	string w;

	cout << "Starting account info: " << endl;
	account.PrintInfo();
	cout << endl << endl;
	
	cout << "Set account number: ";
	cin >> accNum;
	account.accNum(accNum);

	cout << "Set balance: $";
	cin >> balance;
	account.Ibalance(balance);

	cout << "Set interest rate (In decimal form): ";
	cin >> interest;
	account.s_interest(interest);

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
	cout << endl;
	cout << "Account info before interest: " << endl;
	account.PrintInfo();
	cout << endl;

	account.postInterest();
	cout << "Account info after interest: " << endl;
	account.PrintInfo();

	return 0;
}