#include<iostream>
#include"Header1.h"
#include<string>
using namespace std;

class checkingAccount : public bankAccount
{
public:
	checkingAccount(int accNum, double balance, double interest, double minimum, double service) : bankAccount(accNum, balance)
	{
		m_interest = interest;
		m_minimum = minimum;
		m_service = service;
	}

	void s_interest(double interest);//set interest
	double interest();//retrieve interest
	void s_minimum(double minimum);//set minimum balance
	double minimum();//retrieve minimum balance
	void s_serviceCharges(double service);//set service charges
	double service();//retrive service charges
	void postInterest();//post interest
	void belowMin(); //verify if balance is less than minimum
	void writeCheck(double amount);//write a check
	void withdraw(double amount);//withdraw (override the method of the base class)
	void PrintInfo();//print account information
private:
	double m_minimum, m_interest, m_service;
};
void checkingAccount::s_interest(double interest)
{
	m_interest = interest;
}
double checkingAccount::interest()
{
	return m_interest;
}
void checkingAccount::s_minimum(double minimum)
{
	m_minimum = minimum;
}
double checkingAccount::minimum()
{
	return m_minimum;
}
void checkingAccount::s_serviceCharges(double service)
{
	m_service = service;
}
double checkingAccount::service()
{
	return m_service;
}
void checkingAccount::postInterest()
{
	double interestAmount = balance() * m_interest;
	deposit(interestAmount);
}
void checkingAccount::belowMin()
{
	if (balance() < m_minimum)
	{
		bankAccount::withdraw(m_service);
	}
}
void checkingAccount::writeCheck(double amount)
{
	withdraw(amount);
}
void checkingAccount::withdraw(double amount)
{
	if (amount > balance())
	{
		std::cout << "Insufficient funds" << std::endl;
		return;
	}

	bankAccount::withdraw(amount);
	
	if (balance() < m_minimum)
	{
		std::cout << "Below minimum balance. Service charges have been applied." << std::endl;
		bankAccount::withdraw(m_service);
	}
}
void checkingAccount::PrintInfo()
{
	bankAccount::PrintInfo(); //this is to reuse base
	std::cout << "Interest rate: " << m_interest << std::endl;
	std::cout << "Minimum balance: $" << m_minimum << std::endl;
	std::cout << "Service charge: $" << m_service << std::endl;
}
int main()
{
	checkingAccount account(0,100,0,0,0);
	double interest, minimum, service,amount;

	cout << "Test details" << endl;
	cout << "Account number: " << account.IaccNum() << endl;
	cout << "Account balance: $" << account.balance() << endl;

	cout << "Set interest (enter percentage in decimal form): ";
	cin >> interest;
	account.s_interest(interest);

	cout << "Set minimum balance: $";
	cin >> minimum;
	account.s_minimum(minimum);

	cout << "Set service charges: $";
	cin >> service;
	account.s_serviceCharges(service);

	cout << endl << endl;

	cout << "Checking minimum balance: " << endl;
	account.belowMin();
	account.PrintInfo();
	account.postInterest();
	cout << "Account post interest: $" << account.balance() << endl << endl;

	//writing checks
	cout << "Please enter check amount: $";
	cin >> amount;

	cout << endl;
	cout << "Info before writing check: " << endl;
	account.PrintInfo();
	cout << endl;
	account.writeCheck(amount);
	cout << "Info after writing check: " << endl;
	account.PrintInfo();

	return 0;
}