#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<string>
#include "student.h"
using namespace std;
void displaystudents(const Student[], const int); //const makes the array non-updatable
void displaystudents_reverse(const Student[], const int);

void bubble_sort(Student students[], int size); 
void menu_select(Student students[], int count, string& slname, string& options);//needed to set these. Otherwise, I wouuld have to include "cosnt" before "Student" in the headers.
void menu(Student students[], int count, string& slname, string& options);
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
void bubble_sort(Student students[], int size) //Needs to organize students in alphabetical order by last name.
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (students[j].lname > students[j + 1].lname)
			{
				Student temp = students[j];//this line makes a temporary variable that stores the value of the first element.
				students[j] = students[j + 1];//this sets the first element to have the value of the element to the right of it.
				students[j + 1] = temp;//this sets the element on the right with the value of the first element
			}
		}
	}

	displaystudents(students, size);
}
void menu_select(Student students[], int count, string& slname, string& options)// Menu selection
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
		bubble_sort(students, count);
	}
	else if (options == "4")
	{
		cout << "Please enter the students last name to search: ";
		cin >> slname;
		search_array(students, count, slname);
	}
	else if (options == "5")
	{
		cout << endl;
	}
	else
	{
		cout << "Not an option";
	}
}
void menu(Student students[], int count, string& slname, string& options)//Menu display loop
{
	while (options != "5") //when option 5 gets entered, the program ends
	{
		cout << "-------- MENU --------" << endl;
		cout << "1. Display arrays in order" << endl;
		cout << "2. Display arrays in reverse order" << endl;
		cout << "3. Bubble sort last name" << endl;
		cout << "4. Search student by last name" << endl;
		cout << "5. Exit" << endl;
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