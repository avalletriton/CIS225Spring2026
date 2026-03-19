#include<iostream>
#include"Header3.h"
#include<string>
using namespace std;
int main()
{
	string name, description;
	float unitprice, quantity, discount;
	Item item;
	cout << "Enter name: ";
	cin >> item.name;
	cin.ignore(); //gets rid of /n so that geline works
	cout << "Enter description: ";
	getline(cin, item.description);
	cout << "Enter unit price: $";
	cin >> item.unitprice;
	cout << "Enter quantity: ";
	cin >> quantity;

	//sends to functions
	item.quantity(quantity);

	cout << "Name: " << item.name << endl;
	cout << "Description: " << item. description << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Unit price: $" << item.unitprice << endl;
	cout << "Discount price: $" << item.discountprice() << endl;
}