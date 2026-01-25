//Allow the user to enter a quantity and price, use ctl+z to stop.
//Use one function to compute the total (quantity times price), tax (7% of total) and total order (total plus tax).
//The function should be passed the quantity and price by value and total, tax and total order by reference.
//Display total, tax and total order in main. 
//Sum and display total of all orders and tax for all orders and display after the loop(all data is processed).
#include<iostream>
#include<iomanip>
using namespace std;
void compute_total(float quantity, float price, float& total, float& tax, float& totalorder)
{

	total = quantity * price;
	tax = .07 * total;
	totalorder = total + tax;
}
int main()
{
	string stop;
	float quantity, price, total, tax, totalorder, count, sumtotal, sumtax;
	total = 0;
	tax = 0;
	totalorder = 0;
	count = 0;
	sumtotal = 0;
	sumtax = 0;

	while (!cin.eof())
	{
		cout << "Please enter quantity: ";
		cin >> quantity;
		cout << "Please enter price: ";
		cin >> price;
		cout << "Enter any letter to continue or press ctrl z to stop: ";
		cin >> stop;

		compute_total(quantity, price, total, tax, totalorder);

		cout << "Total: " << total << endl;
		cout << "Tax: " << tax << endl;
		cout << "Total Order: " << totalorder << endl;
		cout << "-----------------------------------------------" << endl;
		count = count + 1;
		sumtotal = sumtotal + total;
		sumtax = sumtax + tax;
	}
	cout << "Total orders: " << count << endl;
	cout << "Sum of all totals: " << sumtotal << endl;
	cout << "Sum of all taxes: " << sumtax << endl;
	return 0;
}