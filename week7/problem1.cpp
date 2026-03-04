#include<iostream>
#include<fstream>
#include<string>
#include"Employ.h"
using namespace std;

const int array_size = 10;

//prototypes
void menu_selection(Employee employees[], int count, string choice);
int binarySearch(Employee array[], int size, string searchValue);
void sequentialSearch(Employee employees[], int size, string search);

void bubbleSort(Employee employees[], int array_size)
{
	for (int i = 0; i < array_size; i++)
	{
		for (int j = 0; j < array_size - 1; j++)
		{
			if (employees[j].lname > employees[j + 1].lname)
			{
				Employee temporary = employees[j];
				employees[j] = employees[j + 1];
				employees[j + 1] = temporary;
			}
		}
	}
}
int main()
{
	string choice;
	Employee employees[array_size];
	ifstream file("empldat.txt");

	if (!file)
	{
		cerr << "Error opening the file" << endl;
		return 1;
	}

	int count = 0;
	string salary;
	while (count < array_size && getline(file, employees[count].fname, ',') && 
		                         getline(file, employees[count].lname, ',') && 
		                         getline(file, employees[count].department, ',') && 
		                         getline(file, salary))
	{
		employees[count].salary = stod(salary);
		count++;
	}
	file.close();
	
	bubbleSort(employees, count);

	while (choice != "4")
	{
		cout << "\n--- Menu ---\n";
		cout << "1. Binary Search for Employee Last Name\n";
		cout << "2. Display All Employees\n";
		cout << "3. Sequential Search for Employee Last Name\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		cout << endl;
		cin.ignore(); // Clear newline from input buffer

		menu_selection(employees, count, choice);
	}

	return 0;
}
void menu_selection(Employee employees[], int count, string choice)
{
	string search;
	if (choice == "1")
	{
		cout << "Please enter a last name to search by: ";
		cin >> search;
		int result = binarySearch(employees, count, search);

		if (result != -1)
		{
			cout << "First name: " << employees[result].fname << endl;
			cout << "Last name: " << employees[result].lname << endl;
			cout << "Department: " << employees[result].department << endl;
			cout << "Salary: $" << employees[result].salary << endl;
		}
		else
		{
			cout << "Employee was not found" << endl;
		}
	}
	else if (choice == "2")
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "First name: " << employees[i].fname << endl;
			cout << "Last name: " << employees[i].lname << endl;
			cout << "Department: " << employees[i].department << endl;
			cout << "Salary: $" << employees[i].salary << endl;
			cout << endl;
		}
	}
	else if (choice == "3")
	{
		cout << "Please enter a last name to search by: ";
		cin >> search;

		sequentialSearch(employees, count, search);
	}
}
int binarySearch(Employee array[], int size, string searchValue)
{
	int low = 0;
	int high = size - 1;

	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (searchValue == array[mid].lname)// if what we are searching for is equal to the element in the middle of the array, return mid.
		{
			return mid;
		}
		else if (searchValue > array[mid].lname)
		{
			low = mid + 1; //this makes low a larger than mid.
		}                  //the algorithm works by dividing the array in half and only focusing on the half that has the search value. Then it repeats, until the searched item is found.
		else
		{
			high = mid - 1;
		}
	}
	return -1;
}
void sequentialSearch(Employee employees[], int size, string search)
{
	bool t;

	t = false;

	for (int i = 0; i < size; i++)
	{
		if (employees[i].lname == search)
		{
			cout << "First name: " << employees[i].fname << endl;
			cout << "Last name: " << employees[i].lname << endl;
			cout << "Department: " << employees[i].department << endl;
			cout << "Salary: $" << employees[i].salary << endl;

			t = true;
		}
	}
	if (t == false)
	{
		cout << "Employee was not found" << endl;
	}
}