#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include "student.h"
using namespace std;
void displaystudents(const Student[], const int); //const makes the array non-updatable
void displaystudents_reverse(const Student[], const int);
const int array_size = 10;

//sequential search
void search_array(const Student students[], int size, string slname) 
{
	int i;
	bool found_flag; //value is true or false

	found_flag = false;

	for (i = 0; i < size; i++)
	{
		if (students[i].lname == slname)
		{
			cout << students[i].fname << " " << students[i].lname << " " << students[i].gpa << endl;
			found_flag = true;
		}
	}
	if (found_flag == false)
	{
		cout << "Student was not found" << endl;
	}
}
void menu_select(const Student students[], int count, string& slname, string& options)// Menu selection
{
	if (options == "1")
	{
		cout << "Name L-Name GPA" << endl;
		displaystudents(students, count);
	}
	else if (options == "2")
	{
		displaystudents_reverse(students, count);
	}
	else if (options == "3")
	{
		cout << "Please enter the students last name to search: ";
		cin >> slname;
		search_array(students, count, slname);
	}
	else
	{
		cout << "Not an option";
	}
}
void menu(const Student students[], int count, string& slname, string& options)//Menu display loop
{
	while (options != "4") //when option 4 gets entered, the program ends
	{
		cout << "-------- MENU --------" << endl;
		cout << "1. Display arrays in order" << endl;
		cout << "2. Display arrays in reverse order" << endl;
		cout << "3. Search student by last name" << endl;
		cout << "4. Exit" << endl;
		cout << "-----------------------" << endl;
		cout << "Enter the number of the correspdonding option: ";
		cin >> options;
		menu_select(students, count, slname, options);
	}
}
int main()
{
	string slname, options;
	Student students[array_size]; //creates array of structs
	ifstream file("names.txt");

	if (!file)
	{
		cerr << "Error opening file." << endl;
		return 1;
	}

	string line;
	int count = 0;
	
	while (count < array_size && file >> students[count].fname >> students[count].lname >> students[count].gpa) //loads data into the struct
	{
		count++;
	}

	file.close();
	
	menu(students, count, slname, options);

	return 0;

}
void displaystudents(const Student students[], const int size)
{
	cout << endl << "Student List - Given order" << endl << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << "First name: " << students[i].fname << endl;
		cout << "Last name: " << students[i].lname << endl;
		cout << "GPA: " << students[i].gpa << endl;
		cout << endl;
	}
}
void displaystudents_reverse(const Student students[], const int size)
{
	cout << endl << "Student List - Reverse order" << endl << endl;

	for (int i = size - 1; i >= 0; --i)
	{
		cout << "First name: " << students[i].fname << endl;
		cout << "Last name: " << students[i].lname << endl;
		cout << "GPA: " << students[i].gpa << endl;
		cout << endl;
	}
}