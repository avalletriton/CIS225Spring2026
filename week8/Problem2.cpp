#include<iostream>
#include"Header2.h"
#include<string>
using namespace std;
int main()
{
	string make, model;
	float msrp, discount;
	Car car;
	cout << "Enter make, model, and msrp of car: ";
	cin >> make >> model >> msrp;
	cout << "Enter a discount percentage amount (in decimal form 0 - 1.0): ";
	cin >> discount;

	//sends to functions
	car.make(make);
	car.model(model);
	car.msrp(msrp);
	car.discountpercent(discount);

	cout << "Make: " << car.make() << endl;
	cout << "Model: " << car.model() << endl;
	cout << "MSRP: $" << car.msrp() << endl;
	cout << "Sales price: $" << car.salesprice() << endl;
}