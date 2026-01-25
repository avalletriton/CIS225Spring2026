//Enter the amount of investment, the 5 year interest rate and 10 year interest rate, use ctl+z to stop.
//  Pass the amount and interest rates to a function by value.
// Pass variables representing five year amount and ten year amount to the same function by reference.
// Compute the five year amount and ten year amount using the formula below.
// Display the amount of the investment, the five year amount and the ten year amount.
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
void compute_rate(float amount, float fifth, float tenth, float& Vamount, float& Xamount)
{
	Vamount = amount * pow((1 + fifth), 5);
	Xamount = amount * pow((1 + tenth), 10);
}
int main()
{
	string stop;
	float amount, fifth, tenth, Vamount, Xamount;
	Vamount = 0;
	Xamount = 0;
	while (!cin.eof())
	{
		cout << "Enter an amount of investment: ";
		cin >> amount;
		cout << "Enter 5 year interest rate in decimal form: ";
		cin >> fifth;
		cout << "Enter 10 year interset rate in decimal form: ";
		cin >> tenth;
		cout << "Enter any letter to continue or press ctrl z to stop: ";
		cin >> stop;

		compute_rate(amount, fifth, tenth, Vamount, Xamount);

		cout << "Amount invested: " << amount << endl;
		cout << "Amount invested after five years: " << Vamount << endl;
		cout << "Amount invested after ten years: " << Xamount << endl;
		cout << "---------------------------------------------------" << endl;
	}
	cout << "Done";
	return 0;
}