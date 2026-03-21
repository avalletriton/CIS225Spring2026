//#pragma once
#include<iostream>
class bankAccount
{
public:
	bankAccount(int accNum, double balance); //constructor

	void accNum(int accNum);
	int IaccNum();
	void Ibalance(double balance);
	double balance();
	void deposit(double amount);
	void withdraw(double amount);
	void PrintInfo();
private:
	int m_accNum;
	double m_balance;
};
void bankAccount::accNum(int accNum) //set account number
{
	m_accNum = accNum;
}
int bankAccount::IaccNum() //retrieve the account number
{
	return m_accNum;
}
void bankAccount::Ibalance(double balance)//set balance
{
	m_balance = balance;
}
double bankAccount::balance() //retrieve the account balance
{
	return m_balance;
}
void bankAccount::deposit(double amount)
{
	m_balance = m_balance + amount;
}
void bankAccount::withdraw(double amount)
{
	if (amount > m_balance)
	{
		std::cout << "Insufficient funds" << std::endl;
	}
	else
	{
		m_balance = m_balance - amount;
	}
}
void bankAccount::PrintInfo()
{
	std::cout << "Account number: " << m_accNum << std::endl;
	std::cout << "Balance: $" << m_balance << std::endl;
}
bankAccount::bankAccount(int accNum, double balance)
{
	m_accNum = accNum;
	m_balance = balance;
}
