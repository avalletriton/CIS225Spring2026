#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int total = 10;
struct car
{
	string make;
	string model;
	int msrp;
};

void load_array(ifstream& infile, car list[], int& count)
{
	string make, model, msrpt;

	while (getline(infile, make, ','))
	{
		if (make.size() > 0 && make[0] == ' ')
			make.erase(0, 1);

		getline(infile, model, ',');
		if (model.size() > 0 && model[0] == ' ')
			model.erase(0, 1);

		getline(infile, msrpt);
		if (msrpt.size() > 0 && msrpt[0] == ' ')
			msrpt.erase(0, 1);

		list[count].make = make;
		list[count].model = model;
		list[count].msrp = stoi(msrpt);

		count++;
	}
}
void display_array(const car list[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << list[i].make << "   " << list[i].model << "   " << list[i].msrp << endl;
	}
}
void sequential_search(const car list[],string search, int count)
{
	bool t = false;

	for (int i = 0; i < count; i++)
	{
		if (search == list[i].make)
		{
			cout << list[i].make << "   " << list[i].model << "   " << list[i].msrp << endl;
			t = true;
		}
	}
	cout << endl;
	if (t == false)
	{
		cout << "Car not found" << endl;
	}
}
int main()
{
	car list[total];
	int count = 0;
	string search;

	ifstream infile("auto.txt");
	if (!infile)
	{
		cout << "File couldn't open." << endl;
		return 1;
	}

	load_array(infile, list, count);
	infile.close();

	cout << "     List of cars" << endl;
	cout << "-----------------------------------" << endl;
	display_array(list, count);
	cout << endl << endl;

	while (!cin.eof())
	{
		cout << "Enter car model to search or press ctrl z to stop: ";
		cin >> search;

		sequential_search(list, search, count);
	}

	return 0;
}