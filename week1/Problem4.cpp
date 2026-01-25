//Enter a number of widgets, use ctl+z to stop. Pass the number to a function by value, use ctl+z to stop.
// Use a single function to determine the cost per widget using the cost table below.
// Then compute extended price (number of widgets x cost per widget) and 7% sales tax.
// Finally compute total order to be extended price plus sales tax. Pass cost per widget, extended price, sales tax and total order by reference.
// For each line, display number of widgets, cost per widget, extended price, sales tax and total order.
// Sum all total orders and display when there is no more data to process.
#include<iostream>
#include<iomanip>
using namespace std;
void comp_cost(float widgets, float& costwidget, float& Eprice, float& tax, float& totalorder)
{
	if (widgets >= 10000)
		costwidget = 4;
	else if (widgets >= 5000)
		costwidget = 5;
	else
		costwidget = 10;

	Eprice = costwidget * widgets;
	tax = Eprice * 0.07f;

	totalorder = Eprice + tax;
}
int main()
{
	string stop;
	float widgets, costwidget, Eprice, tax, totalorder, sumtotalorders;
	costwidget = 0;
	sumtotalorders = 0;

	while (!cin.eof())
	{
		cout << "Please enter number of widgets: ";
		cin >> widgets;
		cout << "Enter any letter to continue or press ctrl z to stop: ";
		cin >> stop;

		comp_cost(widgets, costwidget, Eprice, tax, totalorder);

		cout << "Number of widgets: " << widgets << endl;
		cout << "Cost per widget: " << costwidget << endl;
		cout << "Extended Price: " << Eprice << endl;
		cout << "Sales tax: " << tax << endl;
		cout << "Total order: " << totalorder << endl;
		cout << "--------------------------------------------------" << endl;

		sumtotalorders = sumtotalorders + totalorder;
	}
	cout << "Sum of total orders: " << sumtotalorders << endl;
	return 0;
}