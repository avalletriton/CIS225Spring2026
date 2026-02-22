#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include "employee.h"
using namespace std;
void displayemployees(const Employee[], const int);
const int array_size = 10;

void insertion_sort(Employee employees[], int size);
void menu_selection(Employee employees[], int count, string& slname, string& options, double& s_s);
void menu(Employee employees[], int count, string& slname, string& options, double& s_s);

void search_array(const Employee employees[], string& slname)
{
	int i;
	bool Employ;

	Employ = false;
	for (i = 0; i < 10; i++)
	{
		if (employees[i].lname == slname)
		{
			cout << employees[i].fname << " " << employees[i].lname << " " << employees[i].salary << endl;
			Employ = true;
		}
	}
	if (Employ == false)
	{
		cout << "Employee not found" << endl;
	}
}
void search_salary(const Employee employees[], int count, string& slname, string& options, double& s_s)
{
	int i;
	bool money;

	money = false;
	for (i = 0; i < count; i++)
	{
		if (s_s <= employees[i].salary)
		{
			cout << employees[i].fname << " " << employees[i].lname << " " << employees[i].salary << endl;
			money = true;
		}
	}
	cout << endl;
	if (money == false)
	{
		cout << "Employee not found" << endl;
	}
}
void menu_selection(Employee employees[], int count, string& slname, string& options, double& s_s)
{
	int i;
	if (options == "1")
	{
		displayemployees(employees, count);
	}
	else if (options == "2")
	{
		cout << "Please enter Employee's last name for search: ";
		cin.ignore();
		getline(cin, slname);
		search_array(employees, slname);
	}
	else if (options == "3")
	{
		cout << "Enter employee salary for search: ";
		cin >> s_s;
		search_salary(employees, count, slname, options, s_s);
	}
	else if (options == "4")
	{
		insertion_sort(employees, count);
	}
}
void menu(Employee employees[], int count, string& slname, string& options, double& s_s)
{
	while (options != "5")
	{
		cout << "------ MENU ------" << endl;
		cout << "1. Display Employee Data in Order" << endl;
		cout << "2. Search for Employee Last Name" << endl;
		cout << "3. Search for all Employees with salaries Greater Than ___" << endl;
		cout << "4. Insertion Sort employee last name" << endl;
		cout << "5. Exit" << endl;
		cout << "-------------------" << endl;
		cout << "Please enter the number corresponding to option: ";
		cin >> options;
		menu_selection(employees, count, slname, options, s_s);
	}
}
int main()
{
	int i;
	string slname, option;
	double s_s;
	s_s = 0;
	Employee employees[array_size];
	ifstream file("Empldata.txt");

	if (!file)
	{
		cerr << "Error opening file." << endl;
		return 1;
	}

	string line;
	int count = 0;

	while (count < array_size)
	{
		string line;
		getline(file, line);
		if (line.empty())
			continue; //continue skips the rest of the loop

		stringstream ss(line);

		getline(ss, employees[count].fname, ',');
		getline(ss, employees[count].lname, ',');

		if (!employees[count].lname.empty() && employees[count].lname[0] == ' ')
			employees[count].lname.erase(0, 1);

		ss >> employees[i = count].salary;

		count++;
	}

	file.close();

	menu(employees, count, slname, option, s_s);

	return 0;
}
void displayemployees(const Employee employees[], const int size)
{
	cout << endl << "Employee List" << endl << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << "First name: " << employees[i].fname << endl;
		cout << "Last name: " << employees[i].lname << endl;
		cout << "Salary: $" << employees[i].salary << endl;
		cout << endl;
	}
}
void insertion_sort(Employee employees[], int size)
{
	for (int i = 1; i < size; i++) // the outer loop uses i to look at the unsorted values
	{
		Employee key = employees[i];
		int j = i - 1;
		while (j >= 0 && employees[j].lname > key.lname)// the inner loop uses j to sort values in their correct spot
		{
			employees[j + 1] = employees[j];
			j = j - 1;
		}
		employees[j + 1] = key;
	}
	displayemployees(employees, size);
}